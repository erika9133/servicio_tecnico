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
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(MensajeEntrante)), this,SLOT(procesarPeticion(MensajeEntrante)));
}

Controlador::~Controlador()
{
    delete m_ws;
    delete m_xml;
    delete m_consultas;
}

QUuid Controlador::gestorDeColas(QString criterio)
{
    QUuid tecnico;
    if(criterio == "menosOrdenesReparando")
    {

        tecnico = m_consultas->devolverTecnicoMenosOrdenesReparando();
    }//WIP

    return tecnico;
}

void Controlador::procesarPeticion(MensajeEntrante m)
{
    bool validar = false;
    validar = m_xml->validaXML(&m.message);
    ///TO DO validar pasando nombre del dtd y no direccion de la ubicacion
    if(validar)
    {
        QString action = m_xml->devolverNodo(&m.message,"action");
        if(action == "login"){
            QString tiendaUser = m_xml->devolverNodo(&m.message, "user");
            QString tiendaPass = m_xml->devolverNodo(&m.message, "pass");
            bool verificacion = false;
            ///Verifica que el usuario esta en la bbdd
            if(m_consultas->verificarLogin(tiendaUser,tiendaPass,"listado_tiendas"))
            {
                verificacion = true;    
                ///Verificamos que esta en la lista de clientesVerificados
                if(!m_ws->estaEnListaVerificados(m.cliente))
                {
                    ///Si no esta en la lista, lo metemos con su tipo y user
                    /// Asi habra correspondencia entre el pclient y quien es para el sistema
                    ClienteVerificado cli;
                    cli.nombre = tiendaUser;
                    cli.id = m_consultas->devolverUuid(tiendaUser,"listado_tiendas");
                    cli.tipo = "tienda";
                    cli.cliente = m.cliente;
                    m_ws->m_clientesVerificados.append(cli);
                }
            }//end verificar
            ///Devuelve el login de success o no success para que el cliente le pase a otra ventana
            QString xmlLogin = m_xml->generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,m.cliente);
        }else if(action == "loginStaff"){
            QString tecnicoUser = m_xml->devolverNodo(&m.message, "user");
            QString tecnicoPass = m_xml->devolverNodo(&m.message, "pass");
            bool verificacion = false;
            verificacion = true;
            if(!m_ws->estaEnListaVerificados(m.cliente))
            {
                ClienteVerificado cli;
                cli.nombre = tecnicoUser;
                cli.tipo = "tecnico";
                cli.id = m_consultas->devolverUuid(tecnicoUser,"uuid_tecnicos");
                cli.cliente = m.cliente;
                m_ws->m_clientesVerificados.append(cli);
            }
            QString xmlLogin = m_xml->generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,m.cliente);
        }else if(action == "dispositivos"){
            QString tipoDispositivo = m_xml->devolverNodo(&m.message,"consulta");
            QStringList devolverDispositivos = m_consultas->devolverConsultaDosCondiciones("nombre_dispositivos","dispositivos","nombre_dispositivos",tipoDispositivo);
            if(!devolverDispositivos.isEmpty())
            {
                QString envio = m_xml->generarActionConsultas("dispositivos",&devolverDispositivos);
                m_ws->emitTextMessage(envio,m.cliente);
            }
        }else if(action == "orden"){
            ///Solo las tiendas pueden crear ordenes
            if(m_ws->estaEnListaVerifcadosConTipo(m.cliente,"tienda"))
            {
                 QString tienda = m_xml->devolverNodo(&m.message,"tienda");
                 QString cliente = m_xml->devolverNodo(&m.message,"cliente");
                 QString dispositivo = m_xml->devolverNodo(&m.message,"dispositivo");
                 //Asigna la orden al que menos tiene Select en consultas.
                 QUuid tecnicos = gestorDeColas("menosOrdenesReparando");
                // QUuid tecnicos = m_consultas->devolverUuid("Martin horacio fernandez de la cruz","tecnicos");
                 QUuid estados_reparacion = m_consultas->devolverUuid("reparando","estados_reparacion");
                 //Implementar*********************************
                 QUuid dispositivos = m_consultas->devolverUuid(dispositivo,"dispositivos");
                 QUuid listado_tiendas = m_consultas->devolverUuid(tienda,"listado_tiendas");
                 if((listado_tiendas != NULL) && (estados_reparacion != NULL) && (dispositivo != NULL))
                 {
                     bool checkOrden = m_consultas->crearOrden(cliente,estados_reparacion,tecnicos,dispositivos,listado_tiendas);
                     if(checkOrden)
                     {
                         QString xmlExito = m_xml->generarRespuestaSimple("ordenExito","ordenExito");
                         m_ws->emitTextMessage(xmlExito,m.cliente);
                     }
                 }//end if
             }//end if verificado
        }else if(action == "ordenesActivas"){
            ///Solo los tecnicos pueden listar ordenes
            if(m_ws->estaEnListaVerifcadosConTipo(m.cliente,"tecnico"))
            {
                QUuid id;
                QString consulta = m_xml->devolverNodo(&m.message,"consulta");
                QString tecnico  = [=]()->QString{
                        QString devolver;
                        for (auto i : m_ws->m_clientesVerificados) {
                            if(i.cliente == m.cliente){
                                devolver = i.nombre;
                                i.id = id; //Para el envio posterior
                            }
                        }
                        return devolver;
                }();

                QStringList ordenes = [=]()->QStringList{
                            QStringList devolver;
                            QList<OrdenesActivas> ordenes = m_consultas->devolverOrdenesActicas(tecnico,"reparando");
                            for(auto i : ordenes){
                                devolver.append(i.id.toString()+"\n"+i.cliente);
                            }
                            return devolver;
                }();
                QString envio = m_xml->generarActionConsultas("ordenesActivas", &ordenes);
                m_ws->emitTextMessageACliente(envio,id);
             }//end if verificado

        }else{

        }
        //Else consultas
        }//Esta en lista
    }//Validar

