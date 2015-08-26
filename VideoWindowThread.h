#pragma once
#include <QThread>
#include <QElapsedTimer>
#include <QPixmap>
#include <QPainter>
#include <QSemaphore>
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

	VideoWindowThread(std::string filename, int frameRate = 30, bool altered = false, VideoWindowThread *syncWithThread = NULL);
	~VideoWindowThread();
	QSemaphore syncImpulses;

public slots:
	void onAlteredChanged(bool altered);
	void onFrameworkChanged(bool useOpenCV);

signals:
	void frameAcquired(QPixmap pm);
	void vidFinished();

private:
	int frameRate;
	cv::VideoCapture *vc;
	void run();
	QElapsedTimer frameTimer;
	uint64 frameTime = 400;
	cv::Mat frame;
	uint64 framesPlayed;
	bool altered = true;
	AlteringFramework framework = AlteringFramework::OpenCV;
	VideoWindowThread *syncWithThread;
	void doSync();
};

