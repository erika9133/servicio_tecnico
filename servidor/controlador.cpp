#include <QDebug>
#include <QString>
#include <QUuid>
#include <QStringList>
#include "controlador.h"
#include "xml.h"
#include "utils.h"

Controlador::Controlador()
{
    m_consultas = new Consultas();
    m_ws = new WebSocket();
    m_xml = new XML();
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(mensajeEntrante)), this,SLOT(procesarPeticion(mensajeEntrante)));
}

Controlador::~Controlador()
{
    delete m_ws;
    delete m_xml;
    delete m_consultas;
}

void Controlador::procesarPeticion(mensajeEntrante m)
{
    bool validar = false;
    validar = m_xml->validaXML(&m.message);
    if(validar)
    {
        QString tipoConsulta = m_xml->devolverNodo(&m.message,"action");
        if(tipoConsulta == "dispositivos")
        {
            QString tipoDispositivo = m_xml->devolverNodo(&m.message,"consulta");
            qDebug() <<"consulta es "<< tipoDispositivo;
            QStringList devolverDispositivos = m_consultas->devolverDispositivosAceptados(tipoDispositivo);
            if(!devolverDispositivos.isEmpty())
            {
                QString envio = m_xml->generarDispositivos(&devolverDispositivos);
                m_ws->emitTextMessage(envio,m.cliente);
            }
        }else if(tipoConsulta == "orden"){
            QString tienda = m_xml->devolverNodo(&m.message,"tienda");
            QString cliente = m_xml->devolverNodo(&m.message,"cliente");
            QString dispositivo = m_xml->devolverNodo(&m.message,"dispositivo");
            //Implementar tecnicos y estados de reparacion
            QUuid tecnicos = m_consultas->devolverUuid("Martin horacio fernandez de la cruz","tecnicos");
            QUuid estados_reparacion = m_consultas->devolverUuid("reparando","estados_reparacion");
            //Implementar*********************************
            QUuid dispositivos = m_consultas->devolverUuid(dispositivo,"dispositivos");
            QUuid listado_tiendas = m_consultas->devolverUuid(tienda,"listado_tiendas");

            if((listado_tiendas != NULL) && (estados_reparacion != NULL) && (dispositivo != NULL))
            {
                m_consultas->crearOrden(cliente,estados_reparacion,tecnicos,dispositivos,listado_tiendas);
               // QStringList peticion = m_xml->procesarOrden(&reciboSplit);
            }













        }
    }
}
