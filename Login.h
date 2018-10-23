#pragma once

#include <QtWidgets/QMainWindow>
#include "Window_one.h"
#include "ui_Login.h"
#include "Register.h"
#include "qmessagebox.h"
class Login : public QMainWindow
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	//使用eventFilter为了响应label的点击
	bool eventFilter(QObject* obj,QEvent* event);
	QNetworkAccessManager* manager;
private:
	Ui::LoginClass ui;
	Window_one* window; 
	Register* W_register = new Register();
private slots:
	void OnBt_login();
	void reshow();
	void slotNetworkApply(QNetworkReply*);
};
