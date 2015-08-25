#ifndef QGUIPROJECT_H
#define QGUIPROJECT_H

#include <QtWidgets/QMainWindow>
#include "ui_qguiproject.h"
#include "ui_VideoWindow.h"
#include <QLabel>
#include "VideoWindowThread.h"
#include <QVideoWidget>

class qGUIProject : public QMainWindow
{
	Q_OBJECT

public:
	qGUIProject(QMainWindow *parent = 0);
	~qGUIProject();

private:
	Ui::qGUIProjectClass uiMain;
	Ui::VideoWindowFormClass uiVidHigh, uiVidLow;
	QWidget *vWindowHigh = new QWidget,
		*vWindowLow = new QWidget;
	VideoWindowThread *thLowFPS, *thHighFPS;
	QElapsedTimer syncTimer;
	VideoWindowThread *syncLastThread;
public slots:
	void on_btnShowVids_clicked();
	void on_btnTerminate_clicked();
	void onSecondSync(VideoWindowThread *thread);
};

#endif // QGUIPROJECT_H
