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
        int tipo = m_xml->devolverTipo(&m.message);
        switch(tipo)
        {
            case 1: //peticion dispositivos
            {
                QString consulta = m_xml->devolverConsulta(&m.message);
                qDebug() <<"consulta es "<< consulta;
                QStringList devolverDispositivos = m_consultas->devolverDispositivosAceptados(consulta);
                QString envio;

                for(int i; i < devolverDispositivos.size(); i++)
                {
                    qDebug() << devolverDispositivos.at(i);
                    envio.append(devolverDispositivos.at(i));
                }
                m_ws->emitTextMessage(envio,m.cliente);
                break;
            }
            case 2: //crear orden
            {
                QStringList reciboSplit = m.message.split("");
                QStringList peticion = m_xml->procesarOrden(&reciboSplit);
                //WIP
                QUuid estados_reparacion = m_consultas->devolverUuid("reparando","estados_reparacion");
                QUuid dispositivos = m_consultas->devolverUuid(peticion.at(2),"dispositivos");
                QUuid listado_tiendas = m_consultas->devolverUuid(peticion.at(0),"listado_tiendas");
                QString cliente = peticion.at(1);
                QUuid tecnicos = m_consultas->devolverUuid("Martin horacio fernandez de la cruz","tecnicos");
                m_consultas->crearOrden(cliente,estados_reparacion,tecnicos,dispositivos,listado_tiendas);
                break;
            }
        }
    }
}
