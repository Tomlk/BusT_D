#include "Login.h"
#include "qmessagebox.h"
Login::Login(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	window = new Window_one();
	W_register->setWindowFlags(W_register->windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);//ȥ����󻯰�ť
	W_register->setFixedSize(W_register->width(), W_register->height());//���ڲ�������
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
		arg(account).arg(password).arg(isadmin);//��ȡ�˺�������Ϣ
	QByteArray content = strUserInfo.toUtf8();//ת����ʽ
	int contentLength = content.length(); //��Ϣ����
	QNetworkRequest req; //�½��������
	//���������ַ
	QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);

	req.setUrl(url);
//��������ͷ
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

	// ���Ͳ���// ���û��������뷢����web������������֤
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

		/*		QMessageBox::information(NULL, "���", "�������",
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
		QByteArray bytes = reply->readAll();//��ȡ�������˷�������
		QString string = QString::fromUtf8(bytes);//ת��QString��ʽ
		if (string == "login succeed")
		{
			this->hide();
			//window = new Window_one();
			window->show(); //��ʾ�����ڽ���
		}
		else if (string == "user doesn't exist")
		{
			QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("�˺Ż��������"), QMessageBox::Yes);
		}
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("����ʱ"), QMessageBox::Yes);
	}
	reply->deleteLater();//reply ɾ��
}