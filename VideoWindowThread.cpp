#include "VideoWindowThread.h"

VideoWindowThread::VideoWindowThread(std::string filename, int frameRate, bool altered)
{
	this->frameRate = frameRate;
	this->altered = altered;
	frameTime = 1000000000 / frameRate;
	vc = new cv::VideoCapture(filename);
	//vc = new cv::VideoCapture(0); 
	if (!vc->isOpened())
		return;
	vc->set(CV_CAP_PROP_FPS, frameRate);
	vc->set(CV_CAP_PROP_POS_FRAMES, 0);
	frames = 1;
	emit secondSync(this);
}

void VideoWindowThread::run()
{
	timer.start();
	secondtimer.start();
	frame = cv::Mat();
	forever
	{
		while (vc->read(frame))
		{
			//vc->retrieve(frame);
			if (!frame.empty())
			{
				cv::cvtColor(frame, frame, CV_BGR2RGB);

				// the data is not copied, which allows for its further modification in both objects simultaneously
				QImage qimg(frame.data, frame.size().width, frame.size().height, QImage::Format::Format_RGB888);
				if (altered)
				{
					if (framework == AlteringFramework::OpenCV)
					{
						cv::Mat roi = frame(cv::Rect(10, 10, 90, 90));
						cv::Mat color(roi.size(), CV_8UC3, cv::Scalar(0, 255, 0));
						cv::addWeighted(color, 0.5, roi, 0.5, 0.0, roi);
						cv::rectangle(frame, cv::Point(10, 10), cv::Point(100, 100), cv::Scalar(255, 0, 0));
					}
					else
					{
						QPainter p(&qimg);
						p.setBrush(Qt::NoBrush);
						p.setPen(Qt::red);
						p.fillRect(QRect(10, 10, 90, 90), QColor(0, 0, 255, 127));
						p.drawRect(QRect(10, 10, 90, 90));
					}
				}
				QPixmap pm = QPixmap::fromImage(qimg);
				emit frameAcquired(pm);
			}

			// did i even need this?
			//frame.release();

			uint64 t = timer.nsecsElapsed();

			if (t < frameTime)
			{
				int64 trem = frameTime - t;
				if (timeCorrection < trem)
				{
					usleep((trem - timeCorrection) / 1000);
					timeCorrection = 0;
				}
				else
					timeCorrection = 0;
			}

			if (!(frames % frameRate))
			{
				t = secondtimer.nsecsElapsed();
				timeCorrection += t - 1000000000;
				secondtimer.start();
				emit secondSync(this);
			}
			timer.restart();
			frames++;
		}
		vc->set(CV_CAP_PROP_POS_FRAMES, 0);
	}
}

VideoWindowThread::~VideoWindowThread()
{
}

void VideoWindowThread::onAlteredChanged(bool altered)
{
	this->altered = altered;
}

void VideoWindowThread::onFrameworkChanged(bool useOpenCV)
{
	if (useOpenCV)
		this->framework = AlteringFramework::OpenCV;
	else
		this->framework = AlteringFramework::QT;
}