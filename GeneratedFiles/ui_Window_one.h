/********************************************************************************
** Form generated from reading UI file 'Window_one.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_ONE_H
#define UI_WINDOW_ONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Window_one
{
public:
    QAction *actionopen;
    QAction *actionAbout_us;
    QAction *actionsave;
    QAction *actionshutdown;
    QAction *actionexit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *Area_comboBox;
    QLabel *label_2;
    QComboBox *Subarea_comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *Bt_pause;
    QPushButton *Button_export;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *MytableWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Bt_OpenSearch;
    QPlainTextEdit *PlanTexit_T;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Bt_showG;
    QPushButton *Bt_logout;
    QCustomPlot *QcustomplotWidget;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_H;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_one)
    {
        if (Window_one->objectName().isEmpty())
            Window_one->setObjectName(QStringLiteral("Window_one"));
        Window_one->resize(625, 410);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Login/Resources/Myicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Window_one->setWindowIcon(icon);
        actionopen = new QAction(Window_one);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionAbout_us = new QAction(Window_one);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        actionsave = new QAction(Window_one);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionshutdown = new QAction(Window_one);
        actionshutdown->setObjectName(QStringLiteral("actionshutdown"));
        actionexit = new QAction(Window_one);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(Window_one);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Area_comboBox = new QComboBox(centralwidget);
        Area_comboBox->setObjectName(QStringLiteral("Area_comboBox"));

        horizontalLayout->addWidget(Area_comboBox);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        Subarea_comboBox = new QComboBox(centralwidget);
        Subarea_comboBox->setObjectName(QStringLiteral("Subarea_comboBox"));

        horizontalLayout->addWidget(Subarea_comboBox);

        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Bt_pause = new QPushButton(centralwidget);
        Bt_pause->setObjectName(QStringLiteral("Bt_pause"));

        horizontalLayout->addWidget(Bt_pause);

        Button_export = new QPushButton(centralwidget);
        Button_export->setObjectName(QStringLiteral("Button_export"));

        horizontalLayout->addWidget(Button_export);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        MytableWidget = new QTableWidget(centralwidget);
        MytableWidget->setObjectName(QStringLiteral("MytableWidget"));

        horizontalLayout_4->addWidget(MytableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        Bt_OpenSearch = new QPushButton(centralwidget);
        Bt_OpenSearch->setObjectName(QStringLiteral("Bt_OpenSearch"));

        horizontalLayout_3->addWidget(Bt_OpenSearch);


        verticalLayout->addLayout(horizontalLayout_3);

        PlanTexit_T = new QPlainTextEdit(centralwidget);
        PlanTexit_T->setObjectName(QStringLiteral("PlanTexit_T"));

        verticalLayout->addWidget(PlanTexit_T);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Bt_showG = new QPushButton(centralwidget);
        Bt_showG->setObjectName(QStringLiteral("Bt_showG"));

        horizontalLayout_2->addWidget(Bt_showG);

        Bt_logout = new QPushButton(centralwidget);
        Bt_logout->setObjectName(QStringLiteral("Bt_logout"));

        horizontalLayout_2->addWidget(Bt_logout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        QcustomplotWidget = new QCustomPlot(centralwidget);
        QcustomplotWidget->setObjectName(QStringLiteral("QcustomplotWidget"));

        verticalLayout_2->addWidget(QcustomplotWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        Window_one->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_one);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 625, 18));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        Window_one->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_one);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Window_one->setStatusBar(statusbar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(actionopen);
        menu_F->addAction(actionsave);
        menu_F->addAction(actionshutdown);
        menu_F->addAction(actionexit);
        menu_H->addAction(actionAbout_us);

        retranslateUi(Window_one);

        QMetaObject::connectSlotsByName(Window_one);
    } // setupUi

    void retranslateUi(QMainWindow *Window_one)
    {
        Window_one->setWindowTitle(QApplication::translate("Window_one", "\345\250\201\350\205\276\350\202\241\344\273\275(WETOWN GROUP)", nullptr));
        actionopen->setText(QApplication::translate("Window_one", "open", nullptr));
        actionAbout_us->setText(QApplication::translate("Window_one", "About us", nullptr));
        actionsave->setText(QApplication::translate("Window_one", "save", nullptr));
        actionshutdown->setText(QApplication::translate("Window_one", "shutdown", nullptr));
        actionexit->setText(QApplication::translate("Window_one", "exit", nullptr));
        label->setText(QApplication::translate("Window_one", "\347\233\221\346\265\213\345\214\272\345\237\237:", nullptr));
        label_2->setText(QApplication::translate("Window_one", "\345\211\215\347\253\257\345\215\225\345\205\203:", nullptr));
        Bt_pause->setText(QApplication::translate("Window_one", "\346\232\202\345\201\234", nullptr));
        Button_export->setText(QApplication::translate("Window_one", "\345\257\274\345\207\272", nullptr));
        label_4->setText(QApplication::translate("Window_one", "\350\277\207\346\270\251\344\277\241\346\201\257\357\274\232", nullptr));
        Bt_OpenSearch->setText(QApplication::translate("Window_one", "\345\216\206\345\217\262\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        label_3->setText(QApplication::translate("Window_one", "\345\212\250\346\200\201\346\233\262\347\272\277\345\233\276:", nullptr));
        Bt_showG->setText(QApplication::translate("Window_one", "\346\270\251\345\272\246\345\217\230\345\214\226\345\233\276", nullptr));
        Bt_logout->setText(QApplication::translate("Window_one", "\346\263\250\351\224\200", nullptr));
        menu_F->setTitle(QApplication::translate("Window_one", "\346\226\207\344\273\266F", nullptr));
        menu_H->setTitle(QApplication::translate("Window_one", "\345\270\256\345\212\251(H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_one: public Ui_Window_one {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ONE_H
