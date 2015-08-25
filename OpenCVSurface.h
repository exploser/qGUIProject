#pragma once

/*
 A low-level single frame renderer.
 */

#include <QAbstractVideoSurface>
#include <QLabel>

class OpenCVSurface : public QAbstractVideoSurface
{
public:
	OpenCVSurface(QLabel *target);
	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;
	bool present(const QVideoFrame &frame);
	
private:
	QImage::Format imageFormat;
	QLabel *target;
};