#include "Login.h"
#include "Window_one.h"
#include "T_graph.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Login w;
	//T_graph w;
	w.setWindowFlags(w.windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);//ȥ����󻯰�ť
	w.setFixedSize(w.width(),w.height());//���ڲ�������
	w.show();
	return a.exec();
}
