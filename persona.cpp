#include "persona.h"

Persona::Persona(QObject *parent) : QObject(parent)
{

}

Persona::Persona(QString cedula, QString nombre)
{
    this->cedula = cedula;
    this->nombre = nombre;

}

QString Persona::getNombre() const
{
    return nombre;
}

QString Persona::getCedula() const
{
    return cedula;
}

QString Persona::getFoto() const
{
    return foto;
}



