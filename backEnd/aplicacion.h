#ifndef APLICACION_H
#define APLICACION_H
#include <QString>
#include "cliente.h"
#include "xml.h"
#include "login.h"
#include "mainwindow.h"

class Aplicacion : public QObject
{
    Q_OBJECT

public:
    Aplicacion();
    ~Aplicacion();
    QString getTienda();
    void setTienda(QString tienda);
private:
    QString m_tienda;
    QString m_password;
    XML *m_xml;
    Cliente *m_cliente;
    Login *m_login;
    MainWindow *m_window;
    void hacerLogin();
private slots:
    void enviarLogin();
    void reciveMessage(QString message);
};

#endif // APLICACION_H
