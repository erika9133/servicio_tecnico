#include <QDebug>
#include <QtXml>
#include <QXmlSimpleReader>
#include <QXmlDefaultHandler>
#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "xml.h"
#include "utils.h"

XML::XML()
{
    //std::string archivoXML = "test_external.xml";
   // validaXML(archivoXML.c_str());
}

XML::~XML(){}

QStringList XML::procesarOrden(QStringList *orden)
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

//No se usa aun, sirve para pedir gestionar una orden a XML de vuelta
void XML::generarOrden(QUuid id)
{
    id = 0;
    /* En formato de archivo
    QString nombre = "Orden_"+id.toString();
    QString archivo =nombre+".xml";

    Utils::crearArchivo(archivo);
    QStringList xmldoc = {"<documento>",
                          "<id>"+nombre+"</id>",
                          "</documento>"
                          ""};
   Utils::escribir(archivo,xmldoc);

   */
}

bool XML::validaXML(QString *archivoXML)
{
    QString temp = *archivoXML;
    temp.replace('\n',' ');
    const char* validar = temp.toLatin1().data();
    qDebug() << validar;
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
        QStringList listatemp = procesarXML(&temp);
        QString archivoTemp = Utils::generarUUID().toString()+".txt";
        Utils::crearArchivo(archivoTemp);
        Utils::escribir(archivoTemp,listatemp);

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

int XML::devolverTipo(QString *archivoXML)
{
    int devolver = 0;

    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         qDebug() << "tamanyo " << xml.size();
         if(xml.at(i) == "<action>")
         {
             if(xml.at(i+1) == "dispositivos")
             {
                 qDebug() << "entra en dispo " << i+1;
                 qDebug() << "consulta tipo disposito";
                 devolver = 1;
             }else if(xml.at(i+1) == "orden")
             {
                 qDebug() << "consulta tipo orden";
                 devolver = 2;
             }
             break;
         }
    }
    return devolver;
}

QString XML::devolverConsulta(QString *archivoXML)
{
    QString devolver;
    QStringList xml = procesarXML(archivoXML);
    for(int i = 0; i < xml.size(); i++)
    {
         if(xml.at(i) == "<consulta>")
         {
             devolver = xml.at(i+1);

             break;
         }
    }
    return devolver;
}

//Limpia la tabulacion y devuelve el string en una lista
QStringList XML::procesarXML(QString *archivoXML)
{
    QStringList devolver = archivoXML->split("\n");
    for(auto i : devolver)
    {
        qDebug() << i;
    }
    return devolver;
}
