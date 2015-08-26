#include "VideoWindowThread.h"

VideoWindowThread::VideoWindowThread(std::string filename, int frameRate, bool altered, VideoWindowThread *syncWithThread)
{
	this->frameRate = frameRate;
	this->altered = altered;
	this->syncWithThread = syncWithThread;
	frameTime = 1000 / frameRate;
	vc = new cv::VideoCapture(filename);
	//vc = new cv::VideoCapture(0); 
	if (!vc->isOpened())
		return;
	vc->set(CV_CAP_PROP_FPS, frameRate);
	vc->set(CV_CAP_PROP_POS_FRAMES, 0);
	framesPlayed = 1;
}

void VideoWindowThread::run()
{
	frameTimer.start();
	frame = cv::Mat();



	while (vc->read(frame))
	{
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
					cv::putText(frame, std::to_string(framesPlayed), cv::Point(10, 50), CV_FONT_NORMAL, 1, cv::Scalar::all(255));
				}
				else
				{
					QPainter p(&qimg);
					p.setBrush(Qt::NoBrush);
					p.setPen(Qt::red);
					p.fillRect(QRect(10, 10, 90, 90), QColor(0, 0, 255, 127));
					p.drawRect(QRect(10, 10, 90, 90));
					p.drawText(QPoint(10, 50), QString::number(framesPlayed));
				}
			}
			QPixmap pm = QPixmap::fromImage(qimg);
			emit frameAcquired(pm);
		}

		uint64 t = frameTimer.elapsed();
		if (t < frameTime)
		{
			int64 trem = frameTime - t;
			msleep(trem);
			//msleep(frameTime);
		}
		if (framesPlayed++ % frameRate == 0)
		{
			doSync();
		}
		frameTimer.start();
	}
	// when one (shorter) video finishes playing, stop the other one
	emit vidFinished();
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

void VideoWindowThread::doSync()
{
	if (syncWithThread != NULL)
	{
		if (syncWithThread->isRunning())
			syncWithThread->syncImpulses.acquire();
		else
			return;
	}
	else
	{
		syncImpulses.release();
	}
}