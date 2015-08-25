#pragma once
#include <QThread>
#include <QElapsedTimer>
#include <QPixmap>
#include <QPainter>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>



class VideoWindowThread :
	public QThread
{
	Q_OBJECT
public:
	enum AlteringFramework
	{
		OpenCV,
		QT
	};

	VideoWindowThread(std::string filename, int frameRate = 30, bool altered = false);
	~VideoWindowThread();
	int64 timeCorrection = 0;

public slots:
	void onAlteredChanged(bool altered);
	void onFrameworkChanged(bool useOpenCV);

signals:
	void frameAcquired(QPixmap pm);
	void frameTimeCalculated(quint64 t);
	void secondSync(VideoWindowThread *currentThread);

private:
	int frameRate;
	cv::VideoCapture *vc;
	void run();
	QElapsedTimer timer, secondtimer;
	uint64 frameTime = 400;
	cv::Mat frame;
	uint64 frames;
	bool altered = true;
	AlteringFramework framework = AlteringFramework::OpenCV;
};

