#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Bot = new JSecondStraw(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}
