#include "jsecondstraw.h"
#include <QDebug>

JSecondStraw::JSecondStraw(QObject *parent) : QObject(parent)
{
	bittrex = new JBittrex(this);
}

void JSecondStraw::logIn(QString _apiKey, QString _secretKey)
{
	connect(bittrex,&JBittrex::gotWallet,this,&JSecondStraw::logedIn);
	connect(bittrex,&JBittrex::didNotGetWallet,this,&JSecondStraw::didNotLogIn);
	bittrex->getWallet(_apiKey,_secretKey);


}

void JSecondStraw::logedIn(QList<JBalance *> _wallet)
{
	disconnect(bittrex,&JBittrex::gotWallet,this,&JSecondStraw::logedIn);
	disconnect(bittrex,&JBittrex::didNotGetWallet,this,&JSecondStraw::didNotLogIn);
	emit gotWallet(_wallet);
}

void JSecondStraw::didNotLogIn()
{
	disconnect(bittrex,&JBittrex::gotWallet,this,&JSecondStraw::logedIn);
	disconnect(bittrex,&JBittrex::didNotGetWallet,this,&JSecondStraw::didNotLogIn);
	emit doNotGetWallet();
}
