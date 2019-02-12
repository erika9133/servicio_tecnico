#include "login.h"
#include "ui_login.h"
#include "ui_error.h"
#include <QDebug>
#include <QMovie>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    m_user = new QString();
    m_pass = new QString();
    //debug
    ui->error->hide();
    ui->tecnico->setText("Martin horacio fernandez de la cruz");
    ui->password->setText("chocolate");
}

Login::~Login()
{
    delete m_user;
    delete m_pass;
}

QString Login::getPassword()
{
    return *m_pass;
}

QString Login::getUser()
{
    return *m_user;
}

void Login::on_validar_clicked()
{

    *m_user = ui->tecnico->text();
    *m_pass = ui->password->text();
    emit checkLogin();
    QMovie *movie = new QMovie("ajax-loader.gif");
    ui->lbl->setMovie(movie);
    ui->lbl->show();
    movie->start();
}

void Login::error()
{
     ui->error->show();
     ui->lbl->hide();
}

void Login::on_aceptarError_clicked()
{
    ui->error->hide();
    ui->password->setText("");
}
