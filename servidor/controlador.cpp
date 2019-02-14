#include <QDebug>
#include <QString>
#include <QUuid>
#include <QStringList>
#include "controlador.h"
#include "xml.h"

Controlador::Controlador()
{
    m_bbdd = new BBDD();
    m_ws = new WebSocket();
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(MensajeEntrante)), this,SLOT(procesarPeticion(MensajeEntrante)));
}

Controlador::~Controlador()
{
    delete m_ws;
    //delete m_xml;
    //delete m_consultas;
}

QUuid Controlador::gestorDeColas(QString criterio)
{
    QUuid tecnico;
    if(criterio == "menosOrdenesReparando")
    {

        tecnico = m_bbdd->devolverTecnicoMenosOrdenesReparando();
    }//WIP

    return tecnico;
}

void Controlador::procesarPeticion(MensajeEntrante m)
{
    bool validar = false;
    validar = XML::validaXML(&m.message);
    ///TO DO validar pasando nombre del dtd y no direccion de la ubicacion
    if(validar)
    {
        QString action = XML::devolverNodo(&m.message,"action");
        if(action == "login"){
            QString tiendaUser = XML::devolverNodo(&m.message, "user");
            QString tiendaPass = XML::devolverNodo(&m.message, "pass");
            bool verificacion = false;
            ///Verifica que el usuario esta en la bbdd
            if(m_bbdd->verificarLogin(tiendaUser,tiendaPass,"listado_tiendas"))
            {
                verificacion = true;    
                ///Verificamos que esta en la lista de clientesVerificados
                if(!m_ws->estaEnListaVerificados(m.cliente))
                {
                    ///Si no esta en la lista, lo metemos con su tipo y user
                    /// Asi habra correspondencia entre el pclient y quien es para el sistema
                    ClienteVerificado cli;
                    cli.nombre = tiendaUser;
                    cli.id = m_bbdd->devolverUuid(tiendaUser,"listado_tiendas");
                    cli.tipo = "tienda";
                    cli.cliente = m.cliente;
                    m_ws->m_clientesVerificados.append(cli);
                }
            }//end verificar
            ///Devuelve el login de success o no success para que el cliente le pase a otra ventana
            QString xmlLogin = XML::generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,m.cliente);
        }else if(action == "loginStaff"){
            QString tecnicoUser = XML::devolverNodo(&m.message, "user");
            QString tecnicoPass = XML::devolverNodo(&m.message, "pass");
            bool verificacion = false;
            verificacion = true;
            if(!m_ws->estaEnListaVerificados(m.cliente))
            {
                ClienteVerificado cli;
                cli.nombre = tecnicoUser;
                cli.tipo = "tecnico";
                cli.id = m_bbdd->devolverUuid(tecnicoUser,"uuid_tecnicos");
                cli.cliente = m.cliente;
                m_ws->m_clientesVerificados.append(cli);
            }
            QString xmlLogin = XML::generarLogin(verificacion);;
            m_ws->emitTextMessage(xmlLogin,m.cliente);
        }else if(action == "dispositivos"){
            QString tipoDispositivo = XML::devolverNodo(&m.message,"consulta");
            QStringList devolverDispositivos = m_bbdd->devolverConsultaDosCondiciones("nombre_dispositivos","dispositivos","nombre_dispositivos",tipoDispositivo);
            if(!devolverDispositivos.isEmpty())
            {
                QString envio = XML::generarActionConsultas("dispositivos",&devolverDispositivos);
                m_ws->emitTextMessage(envio,m.cliente);
            }
        }else if(action == "orden"){
            ///Solo las tiendas pueden crear ordenes
            if(m_ws->estaEnListaVerifcadosConTipo(m.cliente,"tienda"))
            {
                 QString tienda = XML::devolverNodo(&m.message,"tienda");
                 QString cliente = XML::devolverNodo(&m.message,"cliente");
                 QString dispositivo = XML::devolverNodo(&m.message,"dispositivo");
                 //Asigna la orden al que menos tiene Select en consultas.
                 QUuid tecnicos = gestorDeColas("menosOrdenesReparando");
                // QUuid tecnicos = m_consultas->devolverUuid("Martin horacio fernandez de la cruz","tecnicos");
                 QUuid estados_reparacion = m_bbdd->devolverUuid("reparando","estados_reparacion");
                 //Implementar*********************************
                 QUuid dispositivos = m_bbdd->devolverUuid(dispositivo,"dispositivos");
                 QUuid listado_tiendas = m_bbdd->devolverUuid(tienda,"listado_tiendas");
                 if((listado_tiendas != NULL) && (estados_reparacion != NULL) && (dispositivo != NULL))
                 {
                     bool checkOrden = m_bbdd->crearOrden(cliente,estados_reparacion,tecnicos,dispositivos,listado_tiendas);
                     if(checkOrden)
                     {
                         QString xmlExito = XML::generarRespuestaSimple("ordenExito","ordenExito");
                         m_ws->emitTextMessage(xmlExito,m.cliente);
                     }
                 }//end if
             }//end if verificado
        }else if(action == "ordenesActivas"){
            ///Solo los tecnicos pueden listar ordenes
            if(m_ws->estaEnListaVerifcadosConTipo(m.cliente,"tecnico"))
            {
                QUuid id;
                QString consulta = XML::devolverNodo(&m.message,"consulta");
                QString tecnico  = [=]()->QString{
                        QString devolver = "";
                        for (auto i : m_ws->m_clientesVerificados) {
                            if(i.cliente == m.cliente){
                                devolver = i.nombre;
                                i.id = id; //Para el envio posterior
                            }
                        }
                        return devolver;
                }();

                QStringList ordenes = [=]()->QStringList{
                    QStringList devolver = {};
                            QList<OrdenesActivas> ordenes = m_bbdd->devolverOrdenesActicas(tecnico,"reparando");
                            for(auto i : ordenes){
                                //devolver.append(i.id.toString()+"\n"+i.cliente);
                                devolver.append(i.id.toString()+i.cliente);
                            }
                            return devolver;
                }();
                QString envio = XML::generarActionConsultas("ordenesActivas", &ordenes);
                m_ws->emitTextMessageACliente(envio,id);
             }//end if verificado

        }else{

        }
        //Else consultas
        }//Esta en lista
    }//Validar

