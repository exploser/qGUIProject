#include "PixmapDisplay.h"

PixmapDisplay::PixmapDisplay(QWidget *parent) : QLabel(parent)
{
	this->parent = parent;
	this->setText("");
}

void PixmapDisplay::onFrameAcquired(QPixmap pm)
{
	this->setPixmap(pm);
	if (!flowStarted)
	{
		this->resize(pm.size());
		flowStarted = true;
	}
}
void PixmapDisplay::onFrameTimeReceived(quint64 t)
{
	parent->setWindowTitle(QString::number(t));
}

