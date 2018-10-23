/********************************************************************************
** Form generated from reading UI file 'T_graph.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_GRAPH_H
#define UI_T_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_T_graph
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_7;
    QLabel *T_sensor1;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_13;
    QLabel *T_sensor2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_14;
    QLabel *T_sensor3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_15;
    QLabel *T_sensor4;
    QCustomPlot *T_customplot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *T_graph)
    {
        if (T_graph->objectName().isEmpty())
            T_graph->setObjectName(QStringLiteral("T_graph"));
        T_graph->resize(838, 342);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Login/Resources/Myicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        T_graph->setWindowIcon(icon);
        centralwidget = new QWidget(T_graph);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/Login/Resources/T_icon.png")));

        horizontalLayout_4->addWidget(label_10);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font.setPointSize(22);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(16);
        label_11->setFont(font1);

        horizontalLayout_3->addWidget(label_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_2->addWidget(label_12);

        horizontalSpacer_7 = new QSpacerItem(18, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        T_sensor1 = new QLabel(centralwidget);
        T_sensor1->setObjectName(QStringLiteral("T_sensor1"));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(20);
        T_sensor1->setFont(font2);

        horizontalLayout_2->addWidget(T_sensor1);

        horizontalSpacer_10 = new QSpacerItem(19, 63, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        T_sensor2 = new QLabel(centralwidget);
        T_sensor2->setObjectName(QStringLiteral("T_sensor2"));
        T_sensor2->setFont(font2);

        horizontalLayout_2->addWidget(T_sensor2);

        horizontalSpacer_9 = new QSpacerItem(18, 63, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_2->addWidget(label_14);

        T_sensor3 = new QLabel(centralwidget);
        T_sensor3->setObjectName(QStringLiteral("T_sensor3"));
        T_sensor3->setFont(font2);

        horizontalLayout_2->addWidget(T_sensor3);

        horizontalSpacer_2 = new QSpacerItem(13, 63, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_2->addWidget(label_15);

        T_sensor4 = new QLabel(centralwidget);
        T_sensor4->setObjectName(QStringLiteral("T_sensor4"));
        T_sensor4->setFont(font2);

        horizontalLayout_2->addWidget(T_sensor4);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        T_customplot = new QCustomPlot(centralwidget);
        T_customplot->setObjectName(QStringLiteral("T_customplot"));

        verticalLayout_2->addWidget(T_customplot);


        verticalLayout_3->addLayout(verticalLayout_2);

        T_graph->setCentralWidget(centralwidget);
        menubar = new QMenuBar(T_graph);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 838, 18));
        T_graph->setMenuBar(menubar);
        statusbar = new QStatusBar(T_graph);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        T_graph->setStatusBar(statusbar);

        retranslateUi(T_graph);

        QMetaObject::connectSlotsByName(T_graph);
    } // setupUi

    void retranslateUi(QMainWindow *T_graph)
    {
        T_graph->setWindowTitle(QApplication::translate("T_graph", "\345\250\201\350\205\276\350\202\241\344\273\275(\346\270\251\345\272\246\346\233\262\347\272\277\345\233\276)", nullptr));
        label_10->setText(QString());
        label->setText(QApplication::translate("T_graph", "\346\257\215\347\272\277\346\270\251\345\272\246\346\225\260\346\215\256\345\217\230\345\214\226\345\233\276", nullptr));
        label_11->setText(QApplication::translate("T_graph", "\345\215\263\346\227\266\346\270\251\345\272\246\357\274\232", nullptr));
        label_12->setText(QApplication::translate("T_graph", "sensor1\357\274\232", nullptr));
        T_sensor1->setText(QApplication::translate("T_graph", "TextLabel", nullptr));
        label_13->setText(QApplication::translate("T_graph", "sensor2\357\274\232", nullptr));
        T_sensor2->setText(QApplication::translate("T_graph", "TextLabel", nullptr));
        label_14->setText(QApplication::translate("T_graph", "sensor3\357\274\232", nullptr));
        T_sensor3->setText(QApplication::translate("T_graph", "TextLabel", nullptr));
        label_15->setText(QApplication::translate("T_graph", "sensor4\357\274\232", nullptr));
        T_sensor4->setText(QApplication::translate("T_graph", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class T_graph: public Ui_T_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_GRAPH_H
