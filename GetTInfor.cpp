#include "GetTInfor.h"
GetTInfor::GetTInfor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.plainTextEdit->setReadOnly(true);
	connect(ui.Bt_Request, SIGNAL(clicked()), this, SLOT(Click_Search()));
	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotNetworkApply(QNetworkReply*)));
	//复选框添加
	InitialTime();
	for (int i = 0; i < 20; i++)
	{
		ui.CB_TimeS->addItem(TimeSearchS[i]);
	}
	for (int i = 0; i < 20; i++)
	{
		ui.CB_AreaN->addItem(GBK::s2q("区域") + QString::number(i+1));
	}


}
void GetTInfor::InitialTime()
{	
	QDateTime time = QDateTime::currentDateTime();
	QString str = time.toString("yyyy-MM-dd");
	QString BeforeDaystr, BeforeDaystr1, BeforeDaystr2;
	for (int i = 0; i < 20; i++)
	{
		BeforeDaystr = time.addDays(-i).toString("yyyy-MM-dd");
		BeforeDaystr1 = BeforeDaystr + " 00:00:00";
		BeforeDaystr2 = BeforeDaystr + " 24:59:59";
		TimeSearchS[i] = BeforeDaystr1;
		TimeSearchE[i] = BeforeDaystr2;
	}

	for (int j = 0; j < 1000; j++)
	{
		sampleTime[j] = "";
		sensor1T[j] = "";
		sensor2T[j] = "";
		sensor3T[j] = "";
		sensor4T[j] = "";
	}
}

void GetTInfor::Click_Search()
{
	int Time_i = ui.CB_TimeS->currentIndex();
	int Request_Area = ui.CB_TimeS->currentIndex()+1;
	QString SendInfo= QString("detectTime1=%1&detectTime2=%2&detectArea=%3&method=findWarningByAreaAndTime").arg(TimeSearchS[Time_i]).arg(TimeSearchE[Time_i]).arg(QString::number(Request_Area));
	QByteArray content = SendInfo.toUtf8();
	int contentLength = content.length();
	QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);

	req.setUrl(url);
	//req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

	// 发送某一时间某一地域的请求查询
	manager->post(req, content);

}
void GetTInfor::slotNetworkApply(QNetworkReply* reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
	
		QByteArray bytes = reply->readAll();
		QString string = QString::fromUtf8(bytes);
		GetPresentData(string);
		//利用plainTextEdit显示
		QString PlainT = ui.plainTextEdit->toPlainText();

		//QString str=GBK::s2q("单元")+UnitID+GBK::s2q("发生过温，其传感器1,2,3,4温度分别为")+ sensor1T+","+ sensor2T+","+ sensor3T+","+ sensor4T+"\n"
		PlainT += getOnePlaint();
		ui.plainTextEdit->setPlainText(PlainT);
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("请求超时"), QMessageBox::Yes);
	}
	reply->deleteLater();

}
QString GetTInfor::getOnePlaint()
{
	QString allstr="";
	for (int i = 0; i < TotalNumber; i++)
	{
		allstr += GBK::s2q("单元") + UnitID + GBK::s2q("在时间") + sampleTime[i] + GBK::s2q("发生过温，其传感器1,2,3,4温度分别为") + sensor1T[i] + "," + sensor2T[i] + "," + sensor3T[i] + "," + sensor4T[i] + "\n";
	}
	return allstr;
}
void GetTInfor::GetPresentData(QString xmlstr)
{
	//qDebug() << "xmlstr"<<xmlstr << endl;
	QXmlStreamReader reader;
	int i = 0;
	QString unitn;
	reader.addData(xmlstr);
	while (!reader.atEnd())
	{
		if (reader.isStartElement())
		{
			QXmlStreamAttributes attributes = reader.attributes();
			if (reader.name() == "time")
			{

				sampleTime[i] = QString("%1").arg(reader.readElementText());
				//qDebug() << sampleTime[i];
			}
			else if (reader.name() == "sensor1")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
				/*if (Tstr == "0.0")
					sensor1T[i] = "";
				else */
				sensor1T[i] = Tstr;
				//() << sampleTime[i];
			}
			else if (reader.name() == "sensor2")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
			/*	if (Tstr == "0.0")
					sensor2T[i] = "";
				else */
					sensor2T[i] = Tstr;
				//qDebug() << Tstr;
			}
			else if (reader.name() == "sensor3")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
		/*		if (Tstr == "0.0")
					sensor3T[i] = "";
				else */
				sensor3T[i] = Tstr;
				//qDebug() << Tstr;
			}
			else if (reader.name() == "sensor4")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
	
					//sensor4T[i] = "";
							
				 sensor4T[i] = Tstr;
				
			}
			else if (reader.name() == "unitid")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
				UnitID = Tstr;
				//qDebug() << Tstr;
			}

		}
		else if (reader.isEndElement() && reader.name() == "unit")
		{
			i++;
		}
		reader.readNext();
	}
	TotalNumber = i;

}