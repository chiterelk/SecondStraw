#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	LogInWindow l;
	MainWindow w;

	w.show();
	l.show();

	return a.exec();
}
