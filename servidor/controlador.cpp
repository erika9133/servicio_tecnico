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
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(stringCliente)), this,SLOT(procesarPeticion(stringCliente)));
}

Controlador::~Controlador()
{
    delete m_ws;
    delete m_xml;
    delete m_consultas;
}

void Controlador::procesarPeticion(stringCliente sC)
{
    bool validar = false;
    validar = m_xml->validaXML(&sC.message);
    ///TO DO validar pasando nombre del dtd y no direccion de la ubicacion
    if(validar)
    {
        QString tipoConsulta = m_xml->devolverNodo(&sC.message,"action");

        if(tipoConsulta == "login"){
            QString tiendaUser = m_xml->devolverNodo(&sC.message, "user");
            QString tiendaPass = m_xml->devolverNodo(&sC.message, "pass");
            bool verificacion = false;
            if(m_consultas->verificarLogin(tiendaUser,tiendaPass,"listado_tiendas"))
            {
               verificacion = true;

               ///Si no contine el cliente verificado lo guarda. Evita dos inicios de sesion distintos con mismo pclient
              if(!m_ws->m_clientesVerificados.contains(stringCliente.cliente == sC.cliente))
               {
                   stringCliente cliente;
                   m_ws->m_clientesVerificados.append(cliente);
               }

            }//end verificar
            ///Devuelve el login de success o no success
            QString xmlLogin = m_xml->generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,sC.cliente);
        }else if(tipoConsulta == "loginStaff"){
            QString tecnicoUser = m_xml->devolverNodo(&m.message, "user");
            QString tecnicoPass = m_xml->devolverNodo(&m.message, "pass");
            bool verificacion = false;
            if(m_consultas->verificarLogin(tecnicoUser,tecnicoPass,"tecnicos"))
            {
               verificacion = true;
               if(!m_ws->m_tecnicosVerificados.contains(m.cliente)) m_ws->m_tecnicosVerificados.append(m.cliente);
               m_ws->m_tecnicosVerificados.append(m.cliente);
            }
            QString xmlLogin = m_xml->generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,m.cliente);
        }else if(tipoConsulta == "dispositivos"){
            QString tipoDispositivo = m_xml->devolverNodo(&m.message,"consulta");
            QStringList devolverDispositivos = m_consultas->devolverConsultaDosCondiciones("nombre_dispositivo","dispositivos","nombre_dispositivo",tipoDispositivo);
            if(!devolverDispositivos.isEmpty())
            {
                QString envio = m_xml->generarDispositivos(&devolverDispositivos);
                m_ws->emitTextMessage(envio,m.cliente);
            }
        }else if(tipoConsulta == "orden"){
            if(m_ws->m_clientesVerificados.contains(m.cliente)){
                ///Solo las tiendas pueden crear ordenes
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
                    bool checkOrden = m_consultas->crearOrden(cliente,estados_reparacion,tecnicos,dispositivos,listado_tiendas);
                    if(checkOrden)
                    {
                        m_xml->generarRespuestaSimple("ordenExito","ordenExito");
                    }
                }
            }

        }else if(tipoConsulta == "ListarOrden"){

        }else{

        }
        //Else consultas
        }//Esta en lista
    }//Validar
}
