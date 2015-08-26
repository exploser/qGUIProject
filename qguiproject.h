#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qguiproject.h"
#include "ui_VideoWindow.h"
#include <QCloseEvent>
#include <QLabel>
#include "VideoWindowThread.h"

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
	void closeEvent(QCloseEvent *event);
public slots:
	void on_btnShowVids_clicked();
	void on_btnTerminate_clicked();
};
