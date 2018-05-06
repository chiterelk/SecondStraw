#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    Bot = new JSecondStraw(this);
    logInWindow = new LogInWindow(this);
    logInWindow->show();

	 connect(logInWindow,&LogInWindow::enteredKeys,this,&MainWindow::enteredKeys);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::enteredKeys(QString _apiKey, QString _secretKey)
{
	Bot->logIn(_apiKey, _secretKey);
	connect(Bot,&JSecondStraw::gotWallet,this,&MainWindow::gotWallet);
	connect(Bot,&JSecondStraw::doNotGetWallet,this,&MainWindow::didNotGetWallet);
}

void MainWindow::gotWallet(QList<JBalance *> _wallet)
{
	disconnect(Bot,&JSecondStraw::gotWallet,this,&MainWindow::gotWallet);
	disconnect(Bot,&JSecondStraw::doNotGetWallet,this,&MainWindow::didNotGetWallet);
	logInWindow->close();
	this->show();
}

void MainWindow::didNotGetWallet()
{
	disconnect(Bot,&JSecondStraw::gotWallet,this,&MainWindow::gotWallet);
	disconnect(Bot,&JSecondStraw::doNotGetWallet,this,&MainWindow::didNotGetWallet);
	logInWindow->didNotGetWallet();
}
