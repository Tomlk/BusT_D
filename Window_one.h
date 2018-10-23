#pragma once
#include "Data_dispose.h"
#include <QtWidgets/QMainWindow>
#include "ui_Window_one.h"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "QtNetwork/qnetworkrequest.h"
#include "QtNetwork/qnetworkreply.h"
#include "qcustomplot.h"
#include "qstring.h"
#include "T_graph.h"
#include "GetTInfor.h"
#include "QCloseEvent"
#include "qtimer.h"
#include "QXmlStreamReader"
#define SERVER_IP "192.168.43.159"
#define SERVER_PORT "8080"
class Window_one : public QMainWindow
{
	Q_OBJECT

public:
	Window_one(QWidget *parent = Q_NULLPTR);
	void initialNetwork();
	void initialLayout();
	void InitialTable();
	void InitialData();
	void InitialPlot();
	void initialAreaCombox();
	void GetPresentData(QString);
	void SendHighTInfo(QString Area, QString SampleT, QString UnitN, int sensor, QString T);
	void QcustomplotTest(int row,QCustomPlot* );
	//重写窗口关闭事件
	void closeEvent(QCloseEvent* event);
	bool ExportData();
	void T_checkAndDisplay();
	double test_Tarray[1000];  //测试数据
	double test_Tarray1[1000];
	double test_Tarray2[1000];
	QString sampleTime[100];
	double Present_DATA[100][4];
	// static double window_data[20];
	int window_index;
	int assit_i;
	int chosed_unit_index;
	//static bool StartFlag = false;
public:
	QNetworkAccessManager * manager;
	QNetworkAccessManager* manager1;
	QNetworkRequest req;
	
private:
	Ui::Window_one ui;
	T_graph* mygraph;
	GetTInfor* DialogTInfor;
	QTimer* dataTimer; //
	bool graphexist;
	bool pauseshow;
	const int Tresh_T = 78;
	bool HighTexist;
private slots:
	void Logout();
signals:
	void sendsignal();
private slots:
	void change_graph();
	void T_func();
	void getIndex();
	void About_us();
	void Bt_pause();
	void Bt_getFile();
	void slotNetworkApply(QNetworkReply*);  //温度信息
	void slotNetworkApply1(QNetworkReply*); //过温信息
	void Request_Now();
	void Search_TInfor();



};
