#include "qguiproject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qGUIProject w;
	w.show();
	return a.exec();
}
