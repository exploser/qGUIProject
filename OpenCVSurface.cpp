#include "OpenCVSurface.h"

OpenCVSurface::OpenCVSurface(QLabel *target)
{
	this->target = target;
}

QList<QVideoFrame::PixelFormat> OpenCVSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
	Q_UNUSED(handleType);

	// Return the formats you will support
	return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB565;
}

bool OpenCVSurface::present(const QVideoFrame &frame)
{
	// frame has to be const, but map requires it to be not so we make a copy
	QVideoFrame frame_tmp = frame;
	frame_tmp.map(QAbstractVideoBuffer::ReadOnly);
	imageFormat = QVideoFrame::imageFormatFromPixelFormat(frame_tmp.pixelFormat());

	// that finally works
	QImage img(frame_tmp.bits(), frame_tmp.width(), frame_tmp.height(), frame_tmp.bytesPerLine(), imageFormat);
	QPixmap pm = QPixmap::fromImage(img);
	target->setPixmap(pm);
	
	return true;
}