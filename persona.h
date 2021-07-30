#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>

class Persona : public QObject
{
    Q_OBJECT

public:
    explicit Persona(QObject *parent = nullptr);
    Persona(QString cedula, QString nombre);
    QString getNombre() const;
    QString getCedula() const;
    QString getFoto() const;


private:
    QString nombre;
    QString cedula;
    QString foto;
    QString m_persona;



signals:

};

#endif // PERSONA_H
