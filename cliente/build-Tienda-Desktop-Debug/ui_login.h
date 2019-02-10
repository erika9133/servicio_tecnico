/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *tienda;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *password;
    QPushButton *validar;
    QLabel *lbl;
    QFrame *error;
    QLabel *label_4;
    QPushButton *aceptarError;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        tienda = new QLineEdit(Login);
        tienda->setObjectName(QStringLiteral("tienda"));
        tienda->setGeometry(QRect(150, 90, 211, 32));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 211, 61));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 90, 58, 21));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 160, 71, 18));
        password = new QLineEdit(Login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(150, 150, 211, 32));
        password->setEchoMode(QLineEdit::Password);
        validar = new QPushButton(Login);
        validar->setObjectName(QStringLiteral("validar"));
        validar->setGeometry(QRect(150, 210, 211, 34));
        lbl = new QLabel(Login);
        lbl->setObjectName(QStringLiteral("lbl"));
        lbl->setGeometry(QRect(80, 215, 81, 21));
        error = new QFrame(Login);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(40, 90, 261, 131));
        error->setAutoFillBackground(true);
        error->setFrameShape(QFrame::StyledPanel);
        error->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(error);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 241, 20));
        aceptarError = new QPushButton(error);
        aceptarError->setObjectName(QStringLiteral("aceptarError"));
        aceptarError->setGeometry(QRect(50, 60, 151, 34));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "GestiPlus Tecnic SL", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "Tienda", Q_NULLPTR));
        label_3->setText(QApplication::translate("Login", "Password", Q_NULLPTR));
        validar->setText(QApplication::translate("Login", "Iniciar Sesion", Q_NULLPTR));
        lbl->setText(QString());
        label_4->setText(QApplication::translate("Login", "Datos no validos o servidor inaccesible", Q_NULLPTR));
        aceptarError->setText(QApplication::translate("Login", "Aceptar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
