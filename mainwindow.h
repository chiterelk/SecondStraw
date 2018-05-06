#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jsecondstraw.h"
#include "loginwindow.h"
#include "JBittrex/jbalance.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void enteredKeys(QString _apiKey, QString _secretKey);
	void gotWallet(QList <JBalance*> _wallet);
	void didNotGetWallet();

private:
	Ui::MainWindow *ui;
	JSecondStraw *Bot;
	LogInWindow *logInWindow;

};

#endif // MAINWINDOW_H
