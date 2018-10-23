#include "Window_one.h"
#include "qtablewidget.h"
#include "GBK.h"
//double Window_one::window_data[20] = { 0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0};
Window_one::Window_one(QWidget *parent)
	: QMainWindow(parent)
{
	//connect(ui.Button_Login, SIGNAL(clicked()), this, SLOT(OnBt_login()));
	ui.setupUi(this);
	dataTimer = new QTimer(this);
	dataTimer->start(5000);

	initialLayout();
	graphexist =false;
	InitialTable(); //��ʼ�����
	InitialData();
	InitialPlot();
	initialNetwork();
	initialAreaCombox();
	DialogTInfor = new GetTInfor();
	connect(dataTimer, SIGNAL(timeout()), this, SLOT(T_func()));

	connect(ui.Bt_logout, SIGNAL(clicked()), this, SLOT(Logout()));
	connect(ui.Bt_showG, SIGNAL(clicked()), this, SLOT(change_graph()));
	connect(ui.MytableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(getIndex()));
	connect(ui.actionAbout_us, SIGNAL(triggered()), this, SLOT(About_us()));
	connect(ui.Bt_pause, SIGNAL(clicked()), this, SLOT(Bt_pause()));
	connect(ui.Button_export, SIGNAL(clicked()), this, SLOT(Bt_getFile()));
	connect(ui.Area_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(Request_Now()));
	connect(ui.Bt_OpenSearch, SIGNAL(clicked()), this, SLOT(Search_TInfor()));
	chosed_unit_index = 0; //Ĭ��Ϊ��һ��
	pauseshow = false;
	HighTexist = false;
	//table widget test
	//QcustomplotTest(ui.QcustomplotWidget);

}
void Window_one::initialLayout()
{
	//ui.verticalLayout->setStretchFactor(ui.horizontalLayout, 1);
	ui.verticalLayout_2->setStretchFactor(ui.horizontalLayout_4, 10);
	//ui.verticalLayout->setStretchFactor(ui.horizontalLayout_2, 1);
	ui.verticalLayout_2->setStretchFactor(ui.QcustomplotWidget, 5);
	ui.horizontalLayout_4->setStretchFactor(ui.MytableWidget, 7);
	ui.horizontalLayout_4->setStretchFactor(ui.verticalLayout, 3);
	ui.PlanTexit_T->setReadOnly(true);

}
void Window_one::initialNetwork()
{

	manager = new QNetworkAccessManager(this);
	manager1 = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotNetworkApply(QNetworkReply*)));
	connect(manager1, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotNetworkApply1(QNetworkReply*)));
}
void Window_one::InitialTable()
{
	ui.MytableWidget->setColumnCount(5);//��������
	ui.MytableWidget->setRowCount(100);//��������
	ui.MytableWidget->setWindowTitle("MyTableWidget_TEST");
	ui.MytableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	ui.MytableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//��ѡ
//	ui.MytableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	QStringList hearder;
	
	//�����б���
	hearder<<GBK::s2q("�ɼ�ʱ��") << "sensor-A"
		<< "sensor-B" << "sensor-C" << "sensor-N" ;
	int row = ui.MytableWidget->rowCount();
	int col = ui.MytableWidget->columnCount();
	//��ʼ������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ui.MytableWidget->setItem(i, j, new QTableWidgetItem(""));
		}
	}
//	ui.MytableWidget->setItem
	ui.MytableWidget->setHorizontalHeaderLabels(hearder);
	ui.MytableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	/*hearder << GBK::s2q("���") << GBK::s2q("ǰ�˵�Ԫ") << GBK::s2q("�ɼ�����") << GBK::s2q("�ɼ�ʱ��") << "sensor1"
	<< "sensor2" << "sensor3" << "sensor4" << "sensor5" << "sensor6";
	*/
}
void Window_one::InitialData()
{
	//assit_i = 0;
	//window_index = 0;
	//for (int i = 0; i < 1000; i++)
	//{
	//	test_Tarray[i] = 30 + double((rand() % 500)) / 10;
	//	test_Tarray1[i] = 25 + double((rand() % 300)) / 10;
	//	test_Tarray2[i]=20+ double((rand() % 400)) / 10;
	//}
	for (int i = 0; i < 100; i++)
	{
		sampleTime[i] = "";
		for (int j = 0; j < 4; j++)
		{
			Present_DATA[i][j] = 0;
		}
	}
	/*
	for (int i = 0; i < 20; i++)
	{
		Data_dispose::window_data[i] = 0;
	}
	*/
	for (int i1 = 0; i1 < Data_dispose::Uinit_N; i1++)
	{
		for (int i2 = 0; i2 < 4; i2++)
		{
			for (int i3 = 0; i3 < 20; i3++)
			{
			
				Data_dispose::Window_data[i1][i2][i3] = 0;
			}
		}
	}
	
}
void Window_one::InitialPlot()
{
	mygraph = new T_graph();
	ui.QcustomplotWidget->xAxis->setRange(-19, 0);
	ui.QcustomplotWidget->yAxis->setRange(20, 90);
	ui.QcustomplotWidget->xAxis->setLabel(GBK::s2q("���ʱ��/s"));
	ui.QcustomplotWidget->yAxis->setLabel(GBK::s2q("�¶�/��"));

}
void Window_one::getIndex()
{
	int row = ui.MytableWidget->currentRow(); //��ȡ�����к�
	chosed_unit_index = row;
	mygraph->set_unitindex(chosed_unit_index);
	//QMessageBox::information(this, "aa", "chosed row is:" + QString::number(row), QMessageBox::Yes);
	qDebug() << row<<endl;
}
void Window_one::closeEvent(QCloseEvent* event)
{
	QMessageBox::StandardButton button;
	button = QMessageBox::question(this, GBK::s2q("�˳��¶ȼ��ϵͳ"), GBK::s2q("ȷ���˳�"), QMessageBox::Yes | QMessageBox::No);
	if (button == QMessageBox::No)
		event->ignore();
	

	else if (button == QMessageBox::Yes)
	{
		event->accept();
		mygraph->close();
		
	}
}
void Window_one::Logout()
{
	
	this->close();
	emit sendsignal();
	mygraph->close();
	//window_data����
}
void Window_one::change_graph()
{
	//mygraph = new T_graph(chosed_unit_index);
	mygraph->move(200, 0);
	mygraph->show();
	graphexist = true;
}
void Window_one::T_func()
{
	
	
		int i;
		for (int i1 = 0; i1 < Data_dispose::Uinit_N; i1++)
		{
			for (int i2 = 0; i2 < 4; i2++)
			{
				for (i = 0; i < 19;i++)
				{
					Data_dispose::Window_data[i1][i2][i] = Data_dispose::Window_data[i1][i2][i + 1];
				}
				if(i2==0)
				Data_dispose::Window_data[i1][i2][19]= 30 + double((rand() % 500)) / 10;
				else if (i2==1)
					Data_dispose::Window_data[i1][i2][19] = 25 + double((rand() % 300)) / 10;
				else if(i2==2)
					Data_dispose::Window_data[i1][i2][19] = 20 + double((rand() % 400)) / 10;
				else if (i2 == 3)
					Data_dispose::Window_data[i1][i2][19] = 26 + double((rand() % 500)) / 10;
				
			}
		}
	//}
	
		Request_Now();
	if (!pauseshow)
	{
		for (int i = 0; i < 4; i++)
		{
			Data_dispose::Window_data[0][i][19] = Present_DATA[0][i];

		}
		ui.MytableWidget->setItem(0, 0, new QTableWidgetItem(sampleTime[0]));
		//��Ӧ������ʾ��ʱ�¶�
		for (int i1 = 0; i1 < Data_dispose::Uinit_N; i1++)
			for (int i2 = 0; i2 < 4; i2++)
			{
				ui.MytableWidget->setItem(i1, 1 + i2, new QTableWidgetItem(QString::number(Data_dispose::Window_data[i1][i2][19], 'f', 1)));
			}
		//��ѡ���е�ͼ

		QcustomplotTest(chosed_unit_index, ui.QcustomplotWidget);
	}
	//�����жϲ�������ʾ
	T_checkAndDisplay();
	
}
void Window_one::QcustomplotTest(int row,QCustomPlot* customplot)
{
	

	customplot->replot();
	customplot->legend->setVisible(true);
	QVector<double> Xvalue(20);
	QVector<double> Yvalue(20);
	QVector<double> Yvalue1(20);
	QVector<double> Yvalue2(20);
	QVector<double> Yvalue3(20);
	for (int i = 0; i < 20; i++)
	{
		Xvalue[i] = -19 + i;
	//	Yvalue[i] = Data_dispose::window_data[i];
		Yvalue[i] = Data_dispose::Window_data[chosed_unit_index][0][i];
		Yvalue1[i] = Data_dispose::Window_data[chosed_unit_index][1][i];
		Yvalue2[i] = Data_dispose::Window_data[chosed_unit_index][2][i];
		Yvalue3[i] = Data_dispose::Window_data[chosed_unit_index][3][i];
	}
	if (customplot->graphCount() != 4)
	{
		customplot->addGraph();
		customplot->addGraph();
		customplot->addGraph();
		customplot->addGraph();
	}
	customplot->graph(0)->setPen(QPen(Qt::red));
	customplot->graph(0)->setData(Xvalue, Yvalue);
	customplot->graph(0)->setName("sensor 1");
	customplot->graph(1)->setPen(QPen(Qt::green));
	customplot->graph(1)->setData(Xvalue, Yvalue1);
	customplot->graph(1)->setName("sensor 2");
	customplot->graph(2)->setPen(QPen(Qt::yellow));
	customplot->graph(2)->setData(Xvalue, Yvalue2);
	customplot->graph(2)->setName("sensor 3");
	customplot->graph(3)->setPen(QPen(Qt::black));
	customplot->graph(3)->setData(Xvalue, Yvalue2);
	customplot->graph(3)->setName("sensor 4");
	customplot->xAxis->setLabel(GBK::s2q("���ʱ��/s"));
	customplot->yAxis->setLabel(GBK::s2q("�¶�/��"));
	customplot->xAxis->setRange(-19, 0);
	customplot->yAxis->setRange(20, 90);

	
}
void Window_one::About_us()
{
	QMessageBox::information(this,GBK::s2q("��������"),
		GBK::s2q("2018.8\n����ʹ�ù��������������뽫��ϸ��Ϣ����\nlongshenhao@vip.qq.com") ,
		QMessageBox::Yes);
}
void Window_one::Bt_pause()
{
	if (pauseshow == true)
		pauseshow = false;
	else
		pauseshow = true;

}
void Window_one::Bt_getFile()
{
	if (pauseshow)
	{
		//
		if(ExportData()==true)
		QMessageBox::information(this, GBK::s2q("��Ϣ"), GBK::s2q("�ɹ�������"), QMessageBox::Yes);
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("�Ƿ�����"), GBK::s2q("������ͣ���ݱ仯�ٽ������ݵ���������"), QMessageBox::Yes);
	}

}
bool Window_one::ExportData()
{
	QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
		QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

	if (filepath != "")
	{
		int row = ui.MytableWidget->rowCount();
		int col = ui.MytableWidget->columnCount();
		QList<QString> list;
		//����б���  
		QString HeaderRow;
		for (int i = 0; i < col; i++)
		{
			HeaderRow.append(ui.MytableWidget->horizontalHeaderItem(i)->text() + "\t");
		}
		list.push_back(HeaderRow);
		for (int i = 0; i < row; i++)
		{
			QString rowStr = "";
			for (int j = 0; j < col; j++) {
			//	qDebug() << "(" << i << "," << j << "):" << ui.MytableWidget->item(i, j)->text() << "\t";
				rowStr += ui.MytableWidget->item(i, j)->text() + "\t";
			}
			list.push_back(rowStr);
		}
		QTextEdit textEdit;
		for (int i = 0; i < list.size(); i++)
		{
			textEdit.append(list.at(i));
		}

		QFile file(filepath);
		if (file.open(QFile::WriteOnly | QIODevice::Text))
		{
			QTextStream ts(&file);
			ts.setCodec("GB2312");//����ط�����Լ��ж��Ƿ��á�utf-8��
			ts << textEdit.document()->toPlainText();
			file.close();
		}
		//�����󽫱���������һ������Լ�ѡ��Ҫ��Ҫ
		//ui.MytableWidget->clearContents();
		//ui.MytableWidget->setRowCount(0);
		return true;
	}

	return false;
}
void Window_one::slotNetworkApply(QNetworkReply* reply)
{

	if (reply->error() == QNetworkReply::NoError)
	{
		//QMessageBox::question(this, GBK::s2q("Information"), GBK::s2q("NoError"), QMessageBox::Yes );
		/*QByteArray bytes = reply->readAll();
		QString string = QString::fromUtf8(bytes);
		GetPresentData(string);
		qDebug() << "getpresentData" << endl;
		*/
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("����ʱ"), QMessageBox::Yes);
	}
	reply->deleteLater();

}
void Window_one::slotNetworkApply1(QNetworkReply* reply)
{
	if (reply->error() == QNetworkReply::NoError)
	{
		//QMessageBox::question(this, GBK::s2q("Information"), GBK::s2q("NoError"), QMessageBox::Yes );
		QByteArray bytes = reply->readAll();
		QString string = QString::fromUtf8(bytes);
		GetPresentData(string);
		qDebug() << "getpresentData" << endl;
		/*qDebug() << sampleTime[0] << "\t" << QString::number(Present_DATA[0][0],'f',1) << "," << QString::number(Present_DATA[0][2], 'f', 1)
		<< "," << QString::number(Present_DATA[0][2], 'f', 1) << "," << QString::number(Present_DATA[0][3], 'f', 1) << endl;
		qDebug() << sampleTime[1] << "\t" << QString::number(Present_DATA[1][0], 'f', 1) << "," << QString::number(Present_DATA[1][1], 'f', 1) <<
		"," << QString::number(Present_DATA[1][2], 'f', 1) << "," << QString::number(Present_DATA[1][3], 'f', 1) << endl;*/
		//reader.addData(string);
	}
	else
	{
		QMessageBox::warning(this, GBK::s2q("warning"), GBK::s2q("����ʱ"), QMessageBox::Yes);
	}
	reply->deleteLater();

}

void Window_one::Request_Now()
{
	qDebug() << "getin" << endl;
	//QMessageBox::warning(this, "q", "q", QMessageBox::Yes);
	QString strUserInfo = QString("detectArea=%1&method=findInfoByArea").arg(ui.Area_comboBox->currentText());
	QByteArray content = strUserInfo.toUtf8();
	int contentLength = content.length();
	QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);
	//QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);
	req.setUrl(url);
	//req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

	// ���Ͳ���// ���û��������뷢����web������������֤
	manager1->post(req, content);
}
void Window_one::initialAreaCombox()
{
	for (int i = 0; i < 50; i++)
	{
		ui.Area_comboBox->addItem(QString::number(i + 1));
	}

}
void Window_one::GetPresentData(QString xmlstr)
{
	QXmlStreamReader reader; //reader����
	//qDebug() << "xmlstr"<<xmlstr << endl;
	int i = 0;
	QString unitn;
	reader.addData(xmlstr);//ԭʼxmlstr���
	while (!reader.atEnd())//���û����
	{
		if (reader.isStartElement())  //��ʼԪ�أ�������unit
		{
			QXmlStreamAttributes attributes = reader.attributes();
			if(reader.name()=="time")
			{ 
				//ʱ�� sampleTime����ĸ�ֵ
				sampleTime[i] = QString("%1").arg(reader.readElementText());
				qDebug() << sampleTime[i]<<endl;
			}
			else if (reader.name()=="sensor1")
			{
				QString Tstr= QString("%1").arg(reader.readElementText());
				Present_DATA[i][0] = Tstr.toDouble();
			
			}
			else if (reader.name() == "sensor2")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
				Present_DATA[i][1] = Tstr.toDouble();
			//	qDebug() << Tstr;
			}
			else if (reader.name() == "sensor3")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
				Present_DATA[i][2] = Tstr.toDouble();
			//	qDebug() << Tstr;
			}
			else if (reader.name() == "sensor4")
			{
				QString Tstr = QString("%1").arg(reader.readElementText());
				Present_DATA[i][3] = Tstr.toDouble();
				//qDebug() << Tstr;
			}

		}
		else if (reader.isEndElement() && reader.name() == "unit")
		{
			i++;
		}
		reader.readNext();
	}

}
void Window_one::Search_TInfor()
{
	DialogTInfor->move(500, 0);
	DialogTInfor->show();

}
void Window_one::T_checkAndDisplay()
{
	bool findHighT = false;
	QString current_Area = ui.Area_comboBox->currentText();
	QString PlantText = ui.PlanTexit_T->toPlainText();
	for (int i1 = 0; i1 < Data_dispose::Uinit_N; i1++)
		for (int i2 = 0; i2 < 4; i2++)
		{
			if (Data_dispose::Window_data[i1][i2][19] >= Tresh_T) //����
			{
				PlantText+="\n"+ GBK::s2q("��")+QString::number(i1)+ GBK::s2q("��Ԫ��������") + QString::number(i2+1) +GBK::s2q("��ʱ��")+GBK::s2q("��ʱ��")+sampleTime[i1]+
					GBK::s2q("��⵽����,�¶�Ϊ")+ QString::number(Data_dispose::Window_data[i1][i2][19],'f',1)+GBK::s2q("��");
				ui.PlanTexit_T->setPlainText(PlantText);
				findHighT = true;
				//��������������Ϣ
				SendHighTInfo(current_Area, sampleTime[i1], QString::number(i1), (i2 + 1), QString::number(Data_dispose::Window_data[i1][i2][19], 'f', 1));
			}
		}
	if (findHighT)
		QApplication::beep();

}
void Window_one::SendHighTInfo(QString Area, QString SampleT, QString UnitN, int sensor, QString T)
{
	QString strUserInfo;
	if(sensor==1)
	//QMessageBox::warning(this, "q", "q", QMessageBox::Yes);
		 strUserInfo = QString("detectArea=%1&unitid=%2&sensor1=%3&sensor2=0&sensor3=0&sensor4=0&method=addInfoWarning").arg(Area).arg(UnitN).arg(T);
	else if(sensor==2)
		 strUserInfo = QString("detectArea=%1&unitid=%2&sensor1=0&sensor2=%3&sensor3=0&sensor4=0&method=addInfoWarning").arg(Area).arg(UnitN).arg(T);
	else if(sensor==3)
		 strUserInfo = QString("detectArea=%1&unitid=%2sensor1=0&sensor2=0&sensor3=%3&sensor4=0&method=addInfoWarning").arg(Area).arg(UnitN).arg(T);
	else if(sensor==4)
		 strUserInfo = QString("detectArea=%1&unitid=%2&sensor1=0&sensor2=0&sensor3=0&sensor4=%3&method=addInfoWarning").arg(Area).arg(UnitN).arg(T);
	QByteArray content = strUserInfo.toUtf8();
	int contentLength = content.length();
	QString url = QString("http://%1:%2/Bus_DetectV1.0/BusServlet").arg(SERVER_IP).arg(SERVER_PORT);
	//QString url = QString("http://%1:%2/Bus_DetectV1.0/UserServlet").arg(SERVER_IP).arg(SERVER_PORT);
	req.setUrl(url);
	//req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	req.setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

	// ���Ͳ���// ���û��������뷢����web������������֤
	manager->post(req, content);
}
/*
< ? xml version = "1.0" encoding = "UTF-8" ? >
<Msg>
<Data id = "1">
<title>
<xmlname>hello.xml< / xmlname>
<owner>zhj< / owner>
< / title>
<Number>123456< / Number>
<Name>zhangjie< / Name>
<email>zhangjie@sina.cn< / email>
<website>zhangjie.hello.cn< / website>
< / Data>
<Data id = "2">
<Number>789012< / Number>
<Name>haier< / Name>
<email>haier@sina.cn< / email>
<website>haier.sina.cn< / website>
< / Data>
<Data id = "3">
<Number>345678< / Number>
<Name>sum< / Name>
<email>sum@sina.cn< / email>
<website>sum.sina.cn< / website>
< / Data>
<Data id = "4">
<Number>901234< / Number>
<Name>niil< / Name>
<email>niil@sina.cn< / email>
<website>niil.sina.cn< / website>
< / Data>
< / Msg>
*/
//https://blog.csdn.net/jiezhj/article/details/30241999