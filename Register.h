#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Register.h"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "QtNetwork/qnetworkrequest.h"
#include "QtNetwork/qnetworkreply.h"
#include "qmessagebox.h"
#include "GBK.h"
#define SERVER_IP "192.168.43.159"
#define SERVER_PORT "8080"
class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	//void QcustomplotTest(QCustomPlot* customplot);

private:
	Ui::Register ui;
	QNetworkAccessManager* manager;
private slots:
	//void T_func();
	void slotReg();//°´Å¥µã»÷
	void slotNetworkApply(QNetworkReply*);
};
