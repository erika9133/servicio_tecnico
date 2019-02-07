#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    m_user = new QString();
    m_pass = new QString();
    //debug
    ui->tienda->setText("mediamars");
    ui->password->setText("caracola11");
}

Login::~Login()
{
    delete m_user;
    delete m_pass;
}

void Login::on_botones_accepted()
{
    *m_user = ui->tienda->text();
    *m_pass = ui->password->text();
    emit checkLogin();
}

QString Login::getPassword()
{
    return *m_pass;
}

QString Login::getUser()
{
    return *m_user;
}

void Login::on_botones_rejected()
{

}

void Login::on_validar_clicked()
{
    *m_user = ui->tienda->text();
    *m_pass = ui->password->text();
    emit checkLogin();
}
