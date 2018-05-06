#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LogInWindow;
}

class LogInWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit LogInWindow(QWidget *parent = 0);
	~LogInWindow();
	void didNotGetWallet();

private slots:
	void on_pushButtonStart_clicked();
	void on_pushButtonQuit_clicked();

private:
	Ui::LogInWindow *ui;
signals:
	enteredKeys(QString _apiKey, QString _secretKey);
};

#endif // LOGINWINDOW_H
