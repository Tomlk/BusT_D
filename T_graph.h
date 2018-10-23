#pragma once
#include "Data_dispose.h"
#include <QtWidgets/QMainWindow>
#include "ui_T_graph.h"
#include "qcustomplot.h"
#include "qtimer.h"
#include "GBK.h"
class T_graph : public QMainWindow
{
	Q_OBJECT

public:
	T_graph(QWidget *parent = Q_NULLPTR);
	void QcustomplotTest(QCustomPlot* customplot);
	void set_unitindex(int index);
private:
	Ui::T_graph ui;
	QTimer* dataTimer; //
	int unit_index;
	QCPItemText* m_TextTip;
public:
	void CalculateT();
	double averageT[4];
	double minT[4];
	double maxT[4];
private:
	double sum[4];

private slots:
	void T_func();
};
