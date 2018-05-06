#ifndef JSECONDSTRAW_H
#define JSECONDSTRAW_H

#include <QObject>
#include <JBittrex/jbalance.h>
#include "jbittrex.h"

class JSecondStraw : public QObject
{
	Q_OBJECT
public:
	explicit JSecondStraw(QObject *parent = nullptr);
	void logIn(QString _apiKey, QString _secretKey);
	void logedIn(QList <JBalance*> _wallet);
	void didNotLogIn();
private:
	JBittrex *bittrex;

signals:
	gotWallet(QList <JBalance*> _wallet);
	doNotGetWallet();

public slots:
};

#endif // JSECONDSTRAW_H
