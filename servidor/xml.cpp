#include <QDebug>
#include <QtXml>
#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>
#include <iostream>
#include <fstream>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "xml.h"

XML::XML(){}

XML::~XML(){}

//Procesa un mensaje de tipo orden
QStringList XML::procesarOrden(const QStringList *orden)
{
    QString tienda;
    QString cliente;
    QString dispositivo;
    QStringList devolver;
    for(int i; i < orden->size(); i++)
    {
        QString temp = orden->at(i);
         if(QString::compare(temp, "<tienda>")){
             tienda = orden->at(i+1);
         }else if(QString::compare(temp, "<cliente>")){
             cliente = orden->at(i+1);
         }else if(QString::compare(temp, "<dispositivo>")){
             dispositivo = orden->at(i+1);
         }
    }
    devolver.append(cliente);
    devolver.append(tienda);
    devolver.append(dispositivo);
    return devolver;
}

QString XML::generarRespuestaSimple(QString action, QString respuesta)
{
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/consulta.dtd'>"
                        "<servicio_tecnico>"
                        "<action>"
                        +action+""
                        "</action>"
                        "<consulta>"
                        +respuesta+
                        "</consulta>"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;
}
QString XML::generarLogin(bool verificacion)
{
    QString insercion = "error";
    if(verificacion) insercion = "valido";
    QString devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                        "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/consulta.dtd'>"
                        "<servicio_tecnico>"
                        "<action>"
                        "login"
                        "</action>"
                        "<consulta>"
                        +insercion+
                        "</consulta>"
                        "</servicio_tecnico>"
                       };
    devolver.replace(0x27,0x22);
    return devolver;
}

QString XML::generarActionConsultas(const QString action, const QStringList *consultas)
{
    QString insercion;
    QString devolver;
    for(int i; i < consultas->size(); i++)
    {
        insercion.append("<consulta>"+consultas->at(i)+"</consulta>");
    }
    devolver = {"<?xml version='1.0' encoding='UTF-8'?>"
                "<!DOCTYPE servicio_tecnico SYSTEM 'http://www.3r1k4.com/dtd/dispositivos.dtd'>"
                "<servicio_tecnico>"
                "<action>"
                +action+""
                "</action>"
                +insercion+
                "</servicio_tecnico>"
                };
    devolver.replace(0x27,0x22);
    return devolver;
}

bool XML::validaXML(const QString *archivoXML)
{
    //QString temp = *archivoXML;
    //temp.replace('\n',' ');
    //const char* validar = temp.toLatin1().data();
    //qDebug() << validar;
    //COPY PASTE, todos los derechos sin reservar
    bool result = false;
    /// Crea el contexto del analizador.
    xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
    if (ctxt == NULL)
    {
        qDebug() << "Error al crear el contexto del analizador." ;
        return false;
    } // end if
    /*
     * Parche temporal. No consigo usar xmlCtxtReadDoc en lugar de xmlCtxtReadFile
     * asi que se crea un archivo temporal y luego se borra. Sustituir por la lectura en memoria.
     *
     */
    //QStringList listatemp = procesarXML(&temp);
    QString archivoTemp = QUuid::createUuid().toString()+".txt";
    crearArchivo(archivoTemp);
    escribir(archivoTemp,*archivoXML);
    /// Analiza el archivo activando la opción de validación DTD.
    xmlDocPtr doc = xmlCtxtReadFile(ctxt, archivoTemp.toStdString().c_str(), NULL, XML_PARSE_DTDVALID);
    //xmlDocPtr doc = xmlCtxtReadDoc(ctxt, NULL,validar,NULL, XML_PARSE_DTDVALID);
    if (doc == NULL)
    {
        qDebug() << "Error al analizar el archivo." ;
        return false;
    } // end if
    /// Comprueba la validez del XML.
    if (ctxt->valid == 0)
    {
          qDebug() << "El archivo XML no es valido." ;
    } else {
          qDebug() << "El archivo XML es valido." ;
          result = true;
    } // end if
    /// Libera memoria.
    xmlFreeDoc(doc);
    xmlFreeParserCtxt(ctxt);
    remove(archivoTemp.toStdString().c_str());
    return result;
}

//Devuelve el contenido de un nodo
QString XML::devolverNodo(const QString *archivoXML, const QString nodo)
{
    QString devolver = "";
    QString xmlText = *archivoXML;
    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list=doc.elementsByTagName(nodo);
    devolver = list.at(0).toElement().text();
    return devolver;
}

//Devuelve el contenido de un conjunto de nodos
QStringList XML::devolverNodos(const QString *archivoXML, const QString nodos)
{
    QStringList devolver = {};
    QString xmlText = *archivoXML;
    QDomDocument doc;
    doc.setContent(xmlText);
    QDomNodeList list = doc.elementsByTagName(nodos);
    for(int i = 0 ; i < list.size() ; i++)
    {
        devolver.append(list.at(i).toElement().text());
    }
    return devolver;
}

/*QStringList XML::devolverNodosOld(QString *archivoXML, QString nodos)
{
    QStringList devolver;
    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         if(xml.at(i) == "<"+nodos+">")
         {
             devolver.append(xml.at(i+1));
         }
    }
    return devolver;
}

//Limpia la tabulacion y devuelve el string en una lista
QStringList XML::procesarXML(QString *archivoXML)
{
    //QStringList devolver = archivoXML->split("\n");
    //QString temp = *archivoXML;

    for(auto i : devolver)
    {
        qDebug() << i;
    }
    //QByteArray xmlText;



    return devolver;
}
//Devuelve el contenido de un nodo
QString XML::devolverNodo(QString *archivoXML, QString nodo)
{
    QString devolver;
    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         if(xml.at(i) == "<"+nodo+">")
         {
             devolver = xml.at(i+1);
             break;
         }
    }
    return devolver;
}
*/

void XML::escribir(QString archivo, QString linea)
{
        std::ofstream archivoTemp;
        archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
        //archivoTemp << currentDateTime() << "\t" << datos << "\n" << std::endl;
        archivoTemp << linea.toStdString() << std::endl;
        archivoTemp.close();
}

void XML::escribir(QString archivo, QStringList lista)
{
        std::ofstream archivoTemp;
        archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
        for(auto i : lista)
        {
             archivoTemp << i.toStdString() << std::endl;
        }
        archivoTemp.close();
}

void XML::crearArchivo(QString archivo)
{
       std::ofstream archivoTemp;
       archivoTemp.open (archivo.toStdString().c_str(), std::ios::ate | std::ios::app);
       archivoTemp.close();
}
