#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_GetTInfor.h"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "QtNetwork/qnetworkrequest.h"
#include "qmessagebox.h"
#include "GBK.h"
#include "QXmlStreamReader"
#include "QtNetwork/qnetworkreply.h"
#define SERVER_IP "192.168.43.159"
#define SERVER_PORT "8080"
class GetTInfor : public QMainWindow
{
	Q_OBJECT
public:
	GetTInfor(QWidget *parent = Q_NULLPTR);
	void InitialTime();
	void GetPresentData(QString);
	QString getOnePlaint();
	QString TimeSearchS[20];
	QString TimeSearchE[20];
	QString UnitID;
	QString sampleTime[1000];
	QString sensor1T[1000];
	QString sensor2T[1000];
	QString sensor3T[1000];
	QString sensor4T[1000];
	int TotalNumber;
public:
	QNetworkAccessManager * manager;
	QNetworkRequest req;
	
private:
	Ui::MainWindow ui;
	QString Chosed_Time;
	QString Area;

private slots:
	void Click_Search();
	void slotNetworkApply(QNetworkReply*);

};