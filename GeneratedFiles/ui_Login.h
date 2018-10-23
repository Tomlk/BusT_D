/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *User_account;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *Password;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *Is_administer;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *register_lb;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Button_Login;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginClass)
    {
        if (LoginClass->objectName().isEmpty())
            LoginClass->setObjectName(QStringLiteral("LoginClass"));
        LoginClass->resize(682, 344);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Login/Resources/Myicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginClass->setWindowIcon(icon);
        centralWidget = new QWidget(LoginClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Login/Resources/LoginA.bmp")));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        User_account = new QLineEdit(centralWidget);
        User_account->setObjectName(QStringLiteral("User_account"));
        User_account->setMaxLength(20);

        horizontalLayout->addWidget(User_account);

        horizontalSpacer_2 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Password = new QLineEdit(centralWidget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setMaxLength(20);
        Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(Password);

        horizontalSpacer_4 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        Is_administer = new QRadioButton(centralWidget);
        Is_administer->setObjectName(QStringLiteral("Is_administer"));

        horizontalLayout_3->addWidget(Is_administer);

        horizontalSpacer_6 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        register_lb = new QLabel(centralWidget);
        register_lb->setObjectName(QStringLiteral("register_lb"));
        register_lb->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout_4->addWidget(register_lb);

        horizontalSpacer_8 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        Button_Login = new QPushButton(centralWidget);
        Button_Login->setObjectName(QStringLiteral("Button_Login"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(16);
        Button_Login->setFont(font);

        horizontalLayout_4->addWidget(Button_Login);

        horizontalSpacer_7 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        LoginClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 18));
        LoginClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginClass->setStatusBar(statusBar);

        retranslateUi(LoginClass);

        QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginClass)
    {
        LoginClass->setWindowTitle(QApplication::translate("LoginClass", "\345\250\201\350\205\276\350\202\241\344\273\275(WETOWN GROUP)", nullptr));
        label_3->setText(QString());
        label->setText(QApplication::translate("LoginClass", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("LoginClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        Is_administer->setText(QApplication::translate("LoginClass", "\344\273\245\347\256\241\347\220\206\345\221\230\350\272\253\344\273\275\347\231\273\345\275\225", nullptr));
        register_lb->setText(QApplication::translate("LoginClass", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        Button_Login->setText(QApplication::translate("LoginClass", "       \347\231\273\345\275\225       ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
