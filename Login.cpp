#include "Login.h"
#include "qmessagebox.h"
Login::Login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	window = new Window_one();
	W_register->setWindowFlags(W_register->windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);//去掉最大化按钮
	W_register->setFixedSize(W_register->width(), W_register->height());//窗口不可拉伸
	connect(ui.Button_Login, SIGNAL(clicked()), this, SLOT(OnBt_login()));
	connect(window, SIGNAL(sendsignal()), this, SLOT(reshow()));
	ui.register_lb->installEventFilter(this);
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotNetworkApply(QNetworkReply*)));

}
void Login::OnBt_login()
{
	//this->hide();
	//window->show();
	
	QString account = ui.User_account->text();
	QString password = ui.Password->text();
	QString isadmin;
	if (ui.Is_administer->isChecked())
	{
		isadmin = "1";
	}
	else
	{
		isadmin = "0";
	}
	QString strUserInfo = QString("username=%1&password=%2&method=logIn&usertype=%3").
		arg(account).arg(password).arg(isadmin);//获取账号密码信息
	QByteArray content = strUserInfo.toUtf8();//转化格式
	int contentLength = content.length(); //信息长度
	QNetworkRequest req; //新建请求对象
	//设置请求地址
	QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);

	req.setUrl(url);
//设置请求头
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

	// 发送参数// 将用户名和密码发送至web服务器进行验证
	manager->post(req, content);
	
	
	/*this->hide();
	window->show();
	*/
	//QMessageBox::information(NULL, "warning", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	
}
bool Login::eventFilter(QObject* obj, QEvent* event)
{
	//
	if (obj == ui.register_lb)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
			if (mouseEvent->button() == Qt::LeftButton)
			{

		/*		QMessageBox::information(NULL, "点击", "点击了我",
					QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);*/

				W_register->show();
				return true;
			}
		}
	}
	return  false;
}
void Login::reshow()
{
	this->show();

}
void Login::slotNetworkApply(QNetworkReply* reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
		QByteArray bytes = reply->readAll();//读取服务器端返回数据
		QString string = QString::fromUtf8(bytes);//转成QString格式
		if (string == "login succeed")
		{
			this->hide();
			//window = new Window_one();
			window->show(); //显示主窗口界面
		}
		else if (string == "user doesn't exist")
		{
			QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("账号或密码错误！"), QMessageBox::Yes);
		}
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("请求超时"), QMessageBox::Yes);
	}
	reply->deleteLater();//reply 删除
}