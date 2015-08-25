#pragma once
#include <QLabel>
#include <QPixmap>
#include <QWidget>

class PixmapDisplay :
	public QLabel
{
public:
	PixmapDisplay(QWidget *parent);
public slots:
	void onFrameAcquired(QPixmap pm);
	void onFrameTimeReceived(quint64 t);
private:
	QWidget *parent;
	bool flowStarted = false;
};

