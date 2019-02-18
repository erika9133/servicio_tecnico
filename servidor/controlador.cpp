#include <QDebug>
#include <QString>
#include <QUuid>
#include <QStringList>
#include "controlador.h"
#include "xml.h"

Controlador::Controlador()
{
    qDebug() << "Gestiplus Sv: iniciado.";
    qDebug() << "Todos los derechos sin reservar. 2019.";
    m_bbdd = new BBDD();
    m_ws = new WebSocket();
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(MensajeEntrante)), this,SLOT(procesarPeticion(MensajeEntrante))); 
    m_ordenesActivas = m_bbdd->devolverOrdenesActicas("todos","pendiente");
}

Controlador::~Controlador()
{
    delete m_ws;
    //delete m_xml;
    //delete m_consultas;
}

QUuid Controlador::gestorDeColas(QString criterio)
{
    QUuid devolver = "00000000-0000-0000-0000-000000000000"; //Eliminar
    if(criterio == "TecnicoMenosOrdenesReparando"){
        //Asigna una orden al tecnico con menos ordenes reparando
        devolver = m_bbdd->devolverTecnicoMenosOrdenesReparando();
    }else if(criterio == "dameUnaOrden"){
        devolver = m_bbdd->devolverOrdenLibre();
        //Asigna una orden a un tecnico si hay alguna en pendiente.
    }

    return devolver;
}

void Controlador::procesarPeticion(MensajeEntrante m)
{
    ///TO DO validar pasando nombre del dtd y no direccion de la ubicacion
    if(XML::validaXML(&m.message))
    {
        QString action = XML::devolverNodo(&m.message,"action");
        if(action == "login"){
            QString tiendaUser = XML::devolverNodo(&m.message, "user");
            QString tiendaPass = XML::devolverNodo(&m.message, "pass");
            ///Verifica que el usuario esta en la bbdd
            if(m_bbdd->verificarLogin(tiendaUser,tiendaPass,"listado_tiendas"))
            {   
                ///Verificamos que esta verificado
                if(!m_ws->estaVerificado(m.cliente))
                {
                    QList<Cliente> &lista = m_ws->clientes();
                    for(int i = 0 ; i < lista.size() ; i++)
                    {
                        if(lista[i].cliente == m.cliente)
                        {
                            lista[i].verificado = true;
                            lista[i].id = m_bbdd->devolverUuid(tiendaUser,"listado_tiendas");
                            lista[i].tipo = "tienda";
                            lista[i].nombre = tiendaUser;
                        }//end if
                    }//end for
                    //Cliente &cli = m_ws->findClientes(*m.cliente);
                    QString xmlLogin = XML::generarLogin(true);
                    m_ws->emitTextMessage(xmlLogin,m.cliente);
                }//end verficicar cliente
            }else{
                enviarFallo(1,*m.cliente);
            }//end verificar login
        }else if(action == "loginStaff"){
            QString tecnicoUser = XML::devolverNodo(&m.message, "user");
            QString tecnicoPass = XML::devolverNodo(&m.message, "pass");
            if(m_bbdd->verificarLogin(tecnicoUser,tecnicoPass,"listado_tiendas"))
            {
                if(!m_ws->estaVerificado(m.cliente))
                {
                    QList<Cliente> &lista = m_ws->clientes();
                    for(int i = 0 ; i < lista.size() ; i++)
                    {
                        if(lista[i].cliente == m.cliente)
                        {
                            lista[i].verificado = true;
                            lista[i].id = m_bbdd->devolverUuid(tecnicoUser,"listado_tiendas");
                            lista[i].tipo = "tecnico";
                            lista[i].nombre = tecnicoUser;
                        }//end if
                    }//end for
                    QString xmlLogin = XML::generarLogin(true);
                    m_ws->emitTextMessage(xmlLogin,m.cliente);

                    ///antiguo metodo, borrar tras probar bien
                    /*Cliente &cli = m_ws->findClientes(*m.cliente);
                    cli.verificado = true;
                    cli.id = m_bbdd->devolverUuid(tecnicoUser,"listado_tiendas");
                    cli.tipo = "tecnico";
                    cli.nombre = tecnicoUser;
                    QString xmlLogin = XML::generarLogin(true);
                    m_ws->emitTextMessage(xmlLogin,m.cliente);*/
                }else{
                    enviarFallo(1,*m.cliente);
                }//end verificar
            }//end verificar login
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
            if(m_ws->estaVerifcadoConTipo(m.cliente,"tienda"))
            {
                 QString tienda = XML::devolverNodo(&m.message,"tienda");
                 QString cliente = XML::devolverNodo(&m.message,"cliente");
                 QString dispositivo = XML::devolverNodo(&m.message,"dispositivo");
                 //Asigna la orden al que menos tiene Select en consultas.
                 //QUuid tecnicos = gestorDeColas("menosOrdenesReparando");
                 //Asigna la orden a un tecnico null (en BBDD), aqui se envia un uuid 000
                 QUuid tecnicos = "00000000-0000-0000-0000-000000000000";
                 //QUuid tecnicos = m_consultas->devolverUuid("Martin horacio fernandez de la cruz","tecnicos");
                 QUuid estados_reparacion = m_bbdd->devolverUuid("pendiente","estados_reparacion");
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
            if(m_ws->estaVerifcadoConTipo(m.cliente,"tecnico"))
            {
                QUuid id;
                QString consulta = XML::devolverNodo(&m.message,"consulta");
                QString tecnico  = [=]()->QString{
                    QString devolver = "";
                    for (auto i : m_ws->clientes()) {
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
            }else{
                enviarFallo(2,*m.cliente);
            }
        }else if(action == "asignarOrden"){
               QString tecnicoUser = XML::devolverNodo(&m.message, "user");
               QStringList consulta = {gestorDeColas("dameUnaOrden").toString()};
               QString envio = XML::generarActionConsultas("ordenLibre", &consulta);
               m_ws->emitTextMessage(envio,m.cliente);

        }else if(action == "cambiarEstadoOrden"){
               QString estado = XML::devolverNodo(&m.message, "estado");
              //UPDATE BBDD ESTADO QUuid orden = gestorDeColas("dameUnaOrden");
        }else{
            enviarFallo(3,*m.cliente);
        }//End Action
    }//end validar
}//end function

void Controlador::enviarFallo(int codigoError, QWebSocket &cliente)
{
   QString mensajeError = m_bbdd->devolverMensajeError(codigoError);
   QStringList consultas = {QString::number(codigoError),mensajeError};
   QString envio = XML::generarActionConsultas("error",&consultas);
   m_ws->emitTextMessage(envio,&cliente);
}
/*
QList<OrdenesActivas>& BBDD::OrdenesActivas()
{
    return m_ordenesActivas;
}

void BBDD::setOrdenesActivas(const OrdenesActivas orden)
{
    m_ordenesActivas.push_back(orden);
}
*/
