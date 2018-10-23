#include "T_graph.h"
T_graph::T_graph(QWidget* parent) //index 为此页单元索引
	:QMainWindow(parent)
{
	ui.setupUi(this);
	dataTimer = new QTimer(this);
	dataTimer->start(1000);
	connect(dataTimer, SIGNAL(timeout()), this, SLOT(T_func()));
	ui.verticalLayout_2->setStretchFactor(ui.horizontalLayout_4,2);
	//ui.verticalLayout_3->setStretchFactor(ui.horizontalLayout_5, 5);
	ui.verticalLayout_2->setStretchFactor(ui.T_customplot, 8);
	set_unitindex(0);
//	m_TextTip = new QCPItemText(ui.T_customplot);
//	QcustomplotTest(ui.T_customplot);

}
void T_graph::QcustomplotTest(QCustomPlot* customplot)
{/*
	customplot->replot();
	QVector<double> Xvalue(20);
	QVector<double> Yvalue(20);
	for (int i = 0; i < 20; i++)
	{
		Xvalue[i] = -19 + i;
		Yvalue[i] = Data_dispose::window_data[i];
	}
	customplot->addGraph();
	customplot->graph(0)->setPen(QPen(Qt::red));
	customplot->graph(0)->setData(Xvalue, Yvalue);
	customplot->xAxis->setLabel(GBK::s2q("相对时间/s"));
	customplot->yAxis->setLabel(GBK::s2q("温度/℃"));
	customplot->xAxis->setRange(-19, 0);
	customplot->yAxis->setRange(20, 90);
	*/
	customplot->replot();
	/*m_TextTip = new QCPItemText(customplot);
	m_TextTip->setPositionAlignment(Qt::AlignTop | Qt::AlignLeft);
	QFont font;
	font.setPixelSize(10);
	m_TextTip->setFont(font);
	m_TextTip->setPen(QPen(Qt::black));
	m_TextTip->setBrush(Qt::white);
	m_TextTip->setVisible(true);
	m_TextTip->setText("sadsadsad");*/
	QVector<double> Xvalue(20);
	QVector<double> Yvalue(20); //20个数据点
	QVector<double> Yvalue1(20);
	QVector<double> Yvalue2(20);
	QVector<double> Yvalue3(20);
	for (int i = 0; i < 20; i++)
	{
		Xvalue[i] = -19 + i;
		//	Yvalue[i] = Data_dispose::window_data[i];
		//数据拷贝
		Yvalue[i] = Data_dispose::Window_data[unit_index][0][i];
		Yvalue1[i] = Data_dispose::Window_data[unit_index][1][i];
		Yvalue2[i] = Data_dispose::Window_data[unit_index][2][i];
		Yvalue3[i] = Data_dispose::Window_data[unit_index][3][i];
		ui.T_sensor1->setText(QString::number(Yvalue[i], 'f', 1));
		ui.T_sensor2->setText(QString::number(Yvalue1[i], 'f', 1));
		ui.T_sensor3->setText(QString::number(Yvalue2[i], 'f', 1));
		ui.T_sensor4->setText(QString::number(Yvalue3[i], 'f', 1));
		ui.T_sensor1->setStyleSheet("color:blue;");
		ui.T_sensor2->setStyleSheet("color:blue;");
		ui.T_sensor3->setStyleSheet("color:blue;");
		ui.T_sensor4->setStyleSheet("color:blue;");
	}
	if (customplot->graphCount() != 4)
	{
		customplot->addGraph();
		customplot->addGraph();
		customplot->addGraph();
		customplot->addGraph();
	}
	//qDebug()<<"layer number:"<<customplot->graphCount();
	//标签位置及字体
	customplot->legend->setVisible(true);
	customplot->legend->setFont(QFont("Helvetica", 9));
	customplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignLeft);
	customplot->legend->setSelectableParts(QCPLegend::spItems);
	
	//设置标签
	customplot->graph(0)->setPen(QPen(Qt::red));
	customplot->graph(0)->setData(Xvalue, Yvalue);
	customplot->graph(0)->setName("sensor 1   maxT:"+ QString::number(maxT[0],'f',1)+"   minT:"
		+ QString::number(minT[0], 'f', 1)+"   averageT:"
		+ QString::number(averageT[0], 'f', 1));


	customplot->graph(1)->setPen(QPen(Qt::green));
	customplot->graph(1)->setData(Xvalue, Yvalue1);
	customplot->graph(1)->setName("sensor 2   maxT:" + QString::number(maxT[1], 'f', 1) + "   minT:"
		+ QString::number(minT[1], 'f', 1) + "   averageT:"
		+ QString::number(averageT[1], 'f', 1));
	customplot->graph(2)->setPen(QPen(Qt::yellow));
	customplot->graph(2)->setData(Xvalue, Yvalue2);
	customplot->graph(2)->setName("sensor 3   maxT:" + QString::number(maxT[2], 'f', 1) + "   minT:"
		+ QString::number(minT[2], 'f', 1) + "   averageT:"
		+ QString::number(averageT[2], 'f', 1));
	customplot->graph(3)->setPen(QPen(Qt::black));
	customplot->graph(3)->setData(Xvalue, Yvalue3);
	customplot->graph(3)->setName("sensor 4   maxT:" + QString::number(maxT[3], 'f', 1) + "   minT:"
		+ QString::number(minT[3], 'f', 1) + "   averageT:"
		+ QString::number(averageT[3], 'f', 1));
	customplot->xAxis->setLabel(GBK::s2q("相对时间/s"));
	customplot->yAxis->setLabel(GBK::s2q("温度/℃"));
	customplot->xAxis->setRange(-19, 0);
	customplot->yAxis->setRange(20, 90);

}
void T_graph::CalculateT()
{
	sum[0] = sum[1] = sum[2]=sum[3] = 0;
	//计算平均温度

	for (int i = 0; i < 20; i++)
	{
		sum[0] += Data_dispose::Window_data[unit_index][0][i];
		sum[1] += Data_dispose::Window_data[unit_index][1][i];
		sum[2] += Data_dispose::Window_data[unit_index][2][i];
		sum[3] += Data_dispose::Window_data[unit_index][3][i];
	}
	for (int i = 0; i < 4; i++)
	{
		averageT[i] = sum[i]/20;
		maxT[i] = minT[i] = Data_dispose::Window_data[unit_index][i][0];

	}
	//计算最大最小值
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Data_dispose::Window_data[unit_index][j][i] > maxT[j])
				maxT[j] = Data_dispose::Window_data[unit_index][j][i];
			else if (Data_dispose::Window_data[unit_index][j][i] < minT[j])
				minT[j] = Data_dispose::Window_data[unit_index][j][i];
			else
				continue;
		}
	}



}
void T_graph::set_unitindex(int index)
{
	this->unit_index = index;

}
void T_graph::T_func()
{
	CalculateT();
	QcustomplotTest(ui.T_customplot);

}