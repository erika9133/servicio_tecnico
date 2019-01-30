#include <QDebug>
#include <QString>
#include <QStringList>
#include "controlador.h"
#include "xml.h"
#include "utils.h"

Controlador::Controlador()
{
    m_bbdd = new BBDD();
    m_consultas = new Consultas();
    m_ws = new WebSocket();
    m_xml = new XML();
    QObject::connect(m_ws,SIGNAL(mensajeRecibido(mensajeEntrante)), this,SLOT(procesarPeticion(mensajeEntrante)));

}
Controlador::~Controlador()
{
    if(m_bbdd->m_bdStatus)
    {
        m_bbdd->disconnet();
    }
    delete m_bbdd;
}


void Controlador::procesarPeticion(mensajeEntrante m)
{
    bool validar = false;

   /*QString temp = "temp_"+Utils::generarUUID().toString()+".xml";
    Utils::crearArchivo(temp);
    Utils::escribir(temp,*m_mensajeTemp);*/
   validar = m_xml->validaXML(&m.message);
    qDebug() << m.message;
    QStringList dispositivos = m_consultas->devolverDispositivosAceptados();

    for(int i; i<dispositivos.size();i++)
    {
           m_ws->emitTextMessage(dispositivos.at(i),m.cliente);
    }

    if(validar)
    {
        int tipo = m_xml->tipo(&m.message);
        switch(tipo)
        {
        case 1:

            //Peticion de dispositivos
            QStringList dispositivos = m_consultas->devolverDispositivosAceptados();

            //parsear a xml y responder
           // m_ws->processTextMessage();


        }

    }
}


