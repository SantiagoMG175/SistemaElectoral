#include "certificado.h"
#include "ui_certificado.h"

Certificado::Certificado(Persona *usuarios, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Certificado)
{
    ui->setupUi(this);

      lienzo = QPixmap(350,200);
      QString nombre = usuarios->getNombre();
      QString cedula = usuarios->getCedula();
      this->dibujar(cedula, nombre);
      ui->dibujo->setPixmap(lienzo);

}

Certificado::~Certificado()
{
    delete ui;
}

void Certificado::informacion(Persona)
{
    QString registro;
    QString cedula;
}

void Certificado::on_cmdGuardar_clicked()
{


}

void Certificado::dibujar(QString cedula, QString nombre)
{

        lienzo.fill(Qt::white);
        QPainter painter(&lienzo);

        QTime tiempo = QTime::currentTime();
        QDate fecha = QDate::currentDate();
        lienzo.fill(Qt::white);

        QImage imagen(cedula);

        int x = 40;
        int y = 70;
        painter.drawImage(x,y, imagen.scaled(110,110));
        painter.setFont(QFont("Arial", 10));

        painter.drawText(x+50, y-50,tr("Certificado de Votación"));
        painter.drawText(x+70, y-30,tr("Elecciones 2021"));
        painter.drawText(x+150, y+20,tr("Nombre: ") + nombre );
        painter.drawText(x+150, y+40,tr("Cedula: ") + cedula);
        painter.drawText(x+150, y+60,tr("Fecha: ") + fecha.toString("dd-MM-yyyy"));
        painter.drawText(x+150, y+80,tr("Hora: ") + tiempo.toString("hh:mm"));

}


