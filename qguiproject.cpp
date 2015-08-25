#include "qguiproject.h"
qGUIProject::qGUIProject(QMainWindow *parent)
	: QMainWindow(parent)
{
	uiMain.setupUi(this);
	uiVidHigh.setupUi(vWindowHigh);
	uiVidLow.setupUi(vWindowLow);
	vWindowHigh->setWindowTitle("High FPS");
	vWindowLow->setWindowTitle("Low FPS");
	//this->setWindowTitle("No files selected");
	//QLabel lbl(widget);
	//QPixmap pm("sasha.png");
	//lbl.setPixmap(pm);
	//this->setCentralWidget(widget);

}

qGUIProject::~qGUIProject()
{

}

void qGUIProject::on_btnShowVids_clicked()
{
	uiMain.btnTerminate->setEnabled(true);
	uiMain.btnShowVids->setEnabled(false);
	thHighFPS = new VideoWindowThread("vid1_25.avi", 25, true);
	thLowFPS = new VideoWindowThread("vid2_5.mp4", 5);
	connect(thHighFPS, &VideoWindowThread::frameAcquired, uiVidHigh.vidLabel, &PixmapDisplay::onFrameAcquired);
	connect(thHighFPS, &VideoWindowThread::frameTimeCalculated, uiVidHigh.vidLabel, &PixmapDisplay::onFrameTimeReceived);
	connect(thLowFPS, &VideoWindowThread::frameAcquired, uiVidLow.vidLabel, &PixmapDisplay::onFrameAcquired);
	connect(thLowFPS, &VideoWindowThread::frameTimeCalculated, uiVidLow.vidLabel, &PixmapDisplay::onFrameTimeReceived);

	connect(uiMain.rbAlter1, &QRadioButton::toggled, thHighFPS, &VideoWindowThread::onAlteredChanged);
	connect(uiMain.rbAlter2, &QRadioButton::toggled, thLowFPS, &VideoWindowThread::onAlteredChanged);

	connect(uiMain.rbFramework1, &QRadioButton::toggled, thHighFPS, &VideoWindowThread::onFrameworkChanged);
	connect(uiMain.rbFramework1, &QRadioButton::toggled, thLowFPS, &VideoWindowThread::onFrameworkChanged);

	connect(thHighFPS, &VideoWindowThread::secondSync, this, &qGUIProject::onSecondSync);

	thHighFPS->start();
	thLowFPS->start();
	vWindowHigh->show();
	vWindowLow->show();
	//th->wait(5000);

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

void qGUIProject::onSecondSync(VideoWindowThread *thread)
{

	uint64 t = syncTimer.nsecsElapsed();
	if (t < 500000000 && syncLastThread != thread)
		syncLastThread->timeCorrection += t;
	syncLastThread = thread;
}