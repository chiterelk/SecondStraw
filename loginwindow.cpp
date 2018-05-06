#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>

LogInWindow::LogInWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::LogInWindow)
{
	ui->setupUi(this);
}

LogInWindow::~LogInWindow()
{
	delete ui;
}

void LogInWindow::didNotGetWallet()
{
	qDebug()<<"did not get wallet";
}

void LogInWindow::on_pushButtonStart_clicked()
{
	emit enteredKeys(ui->lineEditApiKey->text().toLatin1(),ui->lineEditSecretKey->text().toLatin1());
}

void LogInWindow::on_pushButtonQuit_clicked()
{
    QApplication::closeAllWindows();
}
