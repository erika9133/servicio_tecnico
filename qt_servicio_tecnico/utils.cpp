#include <QDebug>
#include <iostream>
#include <fstream>
#include "utils.h"

Utils::Utils()
{

}

Utils::~Utils(){}

QStringList Utils::leer(QString archivo)
{
    QStringList lista;
    std::ifstream archivoTempI;
    std::string linea;
    archivoTempI.open (archivo.toStdString().c_str());
    if(archivoTempI.is_open())
    {
       while (getline(archivoTempI,linea))
       {
           lista.append(linea.c_str());
       }
    }
    return lista;
}

