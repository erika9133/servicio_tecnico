#include <QDebug>
#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "xml.h"
XML::XML()
{

}





bool validaXML(const char *archivoXML)
{
    bool result = false;

    /// Crea el contexto del analizador.
    xmlParserCtxtPtr ctxt = xmlNewParserCtxt();
    if (ctxt == NULL)
    {
        std::cout << "Error al crear el contexto del analizador." << std::endl;
        return false;
    } // end if

    /// Analiza el archivo activando la opción de validación DTD.
    xmlDocPtr doc = xmlCtxtReadFile(ctxt, archivoXML, NULL, XML_PARSE_DTDVALID);
    if (doc == NULL)
    {
        std::cout << "Error al analizar el archivo." << std::endl;
        return false;
    } // end if

    /// Comprueba la validez del XML.
    if (ctxt->valid == 0)
    {
        std::cout << "El archivo XML no es valido." << std::endl;
    } else {
        std::cout << "El archivo XML es valido." << std::endl;
        result = true;
    } // end if

    /// Libera memoria.
    xmlFreeDoc(doc);
    xmlFreeParserCtxt(ctxt);

    return result;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string archivoXML = "test_external.xml";

    validaXML(archivoXML.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
