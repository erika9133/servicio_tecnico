#include <QDebug>
#include <QTimer>
#include "aplicacion.h"

Aplicacion::Aplicacion()
{
    //m_xml = new XML();

    QTimer::singleShot(0,this,SLOT(go()));
    m_cliente = new Cliente();
    m_login = new Login();
    m_login->show();
}

Aplicacion::~Aplicacion()
{
   // delete m_xml;
    delete m_cliente;
    delete m_login;
    delete m_window;
}

void Aplicacion::enviarLogin()
{
   m_tienda = m_login->getUser();
   QString loginXML = XML::generarLogin(m_tienda,m_login->getPassword());
   m_cliente->sendMessage(loginXML);

}
void Aplicacion::go()
{
    connect(m_login, SIGNAL(checkLogin()), this, SLOT(enviarLogin()));
    connect(m_cliente, SIGNAL(procesarMensaje(QString)), this, SLOT(reciveMessage(QString)));
}

QString Aplicacion::getTienda()
{
    return m_tienda;
}

void Aplicacion::setTienda(QString tienda)
{
    m_tienda = tienda;
}

void Aplicacion::reciveMessage(QString message)
{
    qDebug() << "el mensaje recibido es: " << message;
    QString tipoConsulta = XML::devolverNodo(&message,"action");
    if(tipoConsulta == "login")
    {
        if(XML::devolverNodo(&message,"consulta") == "valido"){
            hacerLogin();
        }else{
            m_login->error();
            qDebug() << "Datos no validos";
        }
    }else if(tipoConsulta == "dispositivos"){
        if(m_window != NULL)
        {
            m_window->recibirListaDispositivos(message);
        }
    }else if(tipoConsulta == "ordenExito"){
        if(m_window != NULL)
        {
            m_window->recibirOrdenExito();
        }
    }
}

void Aplicacion::hacerLogin()
{
    m_login->hide();
    m_window = new MainWindow(nullptr,m_cliente,m_tienda);
    m_window->show();
}
