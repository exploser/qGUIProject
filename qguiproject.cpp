#include "qguiproject.h"
qGUIProject::qGUIProject(QMainWindow *parent)
	: QMainWindow(parent)
{
	uiMain.setupUi(this);
	uiVidHigh.setupUi(vWindowHigh);
	uiVidLow.setupUi(vWindowLow);
	vWindowHigh->setWindowTitle("High FPS");
	vWindowLow->setWindowTitle("Low FPS");

}

qGUIProject::~qGUIProject()
{

}

void qGUIProject::on_btnShowVids_clicked()
{
	uiMain.btnTerminate->setEnabled(true);
	uiMain.btnShowVids->setEnabled(false);
	// one thread acts as the clock, incrementing a QSemaphore every second
	thHighFPS = new VideoWindowThread("vid1_25.avi", 25, uiMain.rbAlter1->isChecked(), syncImpulseA, syncImpulseB);
	// the other listens to the clock, decrementing a QSemaphore every second
	thLowFPS = new VideoWindowThread("vid2_5.mp4", 5, uiMain.rbAlter2->isChecked(), syncImpulseB, syncImpulseA);

	// connect the threads to gui output
	connect(thHighFPS, &VideoWindowThread::frameAcquired, uiVidHigh.vidLabel, &PixmapDisplay::onFrameAcquired);
	connect(thLowFPS, &VideoWindowThread::frameAcquired, uiVidLow.vidLabel, &PixmapDisplay::onFrameAcquired);

	// connect gui input to the threads
	connect(uiMain.rbAlter1, &QRadioButton::toggled, thHighFPS, &VideoWindowThread::onAlteredChanged);
	connect(uiMain.rbAlter2, &QRadioButton::toggled, thLowFPS, &VideoWindowThread::onAlteredChanged);
	connect(uiMain.rbFramework1, &QRadioButton::toggled, thHighFPS, &VideoWindowThread::onFrameworkChanged);
	connect(uiMain.rbFramework1, &QRadioButton::toggled, thLowFPS, &VideoWindowThread::onFrameworkChanged);

	// connect the threads to termination slot; this is also triggered by 'terminate' button
	// for some videos this has a huge delay (~5s), probably because cv::VideoCapture::read() creates one
	connect(thHighFPS, &VideoWindowThread::vidFinished, this, &qGUIProject::on_btnTerminate_clicked);
	connect(thLowFPS, &VideoWindowThread::vidFinished, this, &qGUIProject::on_btnTerminate_clicked);

	thHighFPS->start();
	thLowFPS->start();
	vWindowHigh->show();
	vWindowLow->show();

}

void qGUIProject::on_btnTerminate_clicked()
{
	// a bad but simple way to stop the threads
	thHighFPS->terminate();
	thLowFPS->terminate();
	uiMain.btnTerminate->setEnabled(false);
	uiMain.btnShowVids->setText("Restart");
	uiMain.btnShowVids->setEnabled(true);
}

void qGUIProject::closeEvent(QCloseEvent *event)
{
	event->accept();
	qApp->exit(0);
}