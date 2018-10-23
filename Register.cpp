#include "Register.h"
Register::Register(QWidget* parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);
	manager = new QNetworkAccessManager(this);
	//	QcustomplotTest(ui.T_customplot);
	connect(ui.Bt_requset, SIGNAL(clicked()), this, SLOT(slotReg()));
	//网络载体的响应接受信号,与响应接收槽绑定
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotNetworkApply(QNetworkReply*)));

}

void Register::slotReg()
{
	QString useraccount = ui.R_account->text();
	QString password = ui.R_password->text();
	QString password2 = ui.R_password_2->text();
	QString key = ui.R_rqpwd->text();
	if (password !=password2)
	{
		QMessageBox::warning(NULL, "False!", GBK::s2q("两次密码输入不一致"));
		return;
	}

	QString strUserInfo = QString("key=%1&username=%2&password=%3&method=addUser&usertype=1").arg(key).arg(useraccount).arg(password);
	QByteArray content = strUserInfo.toUtf8();
	int contentLength = content.length();
	QNetworkRequest req;
	QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);
	req.setUrl(url);
	//req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);
	
	// 发送参数// 将用户名和密码发送至web服务器进行验证
	manager->post(req, content);

}
void Register::slotNetworkApply(QNetworkReply* reply)
{


	int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	qDebug() << "statusCode:" << statusCode;
	if (reply->error() == QNetworkReply::NoError)
	{
		//QMessageBox::question(this, GBK::s2q("Information"), GBK::s2q("NoError"), QMessageBox::Yes );
		QByteArray bytes = reply->readAll();
		QString string = QString::fromUtf8(bytes);
		if (string == "adduser succeed")
		{
			QMessageBox::information(this, "Information", GBK::s2q("注册成功！"), QMessageBox::Yes);
			ui.R_account->clear();
			ui.R_password->clear();
			ui.R_password_2->clear();
			ui.R_rqpwd->clear();
		}
		else if (string == "key wrong")
		{
			QMessageBox::warning(this, "Warning", GBK::s2q("秘钥号不能匹配。"), QMessageBox::Yes);
			ui.R_rqpwd->clear();
		}
		else if (string == "user already exist")
		{
			QMessageBox::warning(this, "Failed", GBK::s2q("该账号已被注册。"), QMessageBox::Yes);
			ui.R_account->clear();
			ui.R_password->clear();
			ui.R_password_2->clear();
		}

	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("连接失败！"), QMessageBox::Yes);
	}
	reply->deleteLater();
}
//https://blog.csdn.net/liukang325/article/details/46915359