#include "principal.h"
#include "ui_principal.h"
#include <QMap>
#include <QTextStream>
#include <persona.h>
#include <votacion.h>
#include <certificado.h>

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    Archivo();
}

principal::~principal()
{
    delete ui;
}

void principal::Archivo()
{

        ui->inCedula->setEchoMode(QLineEdit::Normal);

        QString nombreArchivo="D:/Universidad/Programacion/Proyectos QT/SistemaElectoral/SistemaElectoral/documentos/Padron.txt";

        QString cedulaPersona,nombrePersona;
        QFile documento;
        QTextStream bloctxt;

        documento.setFileName(nombreArchivo);

        documento.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!documento.isOpen()){
            return;
        };
        bloctxt.setDevice(&documento);
        int m_cedula=0,m_nombre=0;

        while(!bloctxt.atEnd()){
            auto linea = bloctxt.readLine();
            auto valores=linea.split(";");

            for(int i=0; i<valores.size();i++){
                auto dato=valores.at(i);

                if(i==0 or m_cedula==i){
                    cedulaPersona=dato;
                    m_cedula+=3;
                };

                if(i==1 or m_nombre==i){
                    nombrePersona=dato;
                    m_cedula+=3;

                     m_usuario.append(new Persona(cedulaPersona,nombrePersona));
                };
            }
        }

        documento.close();
    }




void principal::buscar()
{
    QString numeroCedula = ui->inCedula->text();

    bool busqueda=false;

    if (numeroCedula.isEmpty() || numeroCedula<10){
        QMessageBox::warning(0,"Advertencia","Verifique que los datos sean correctos");
        return;
    }
    for(int i=1;i< m_usuario.length();i++){
        if( m_usuario.at(i)->getCedula()==numeroCedula){


            QString nombre =  m_usuario.at(i)->getNombre();
            QString cedula =  m_usuario.at(i)->getCedula();
            votacionPersona = new Persona(cedula,nombre);


            QMessageBox::information(0,"Advertencia","Su voto es secreto");
            cedula =  m_usuario.at(i)->getCedula();
            nombre =  m_usuario.at(i)->getNombre();


            votacionPersona = new Persona(cedula,nombre);
            busqueda=true;

        }
    }

        if (busqueda==false){
            QMessageBox::warning(0,"Advertencia","No se encuentra en la lista");
            ui->inCedula->clear();

        }else{

            ui->inCedula->setText("");
            Votacion *ingreso = new Votacion(this);
            ingreso->obtenerDatos(votacionPersona);
            ingreso->setWindowModality(Qt::ApplicationModal);
            ingreso->show();
        }



    }


bool principal::verificar()
{

    if (ui->inCedula->text().isEmpty()){}
    return false;
}



void principal::on_pushButton_clicked()
{

    buscar();




}
