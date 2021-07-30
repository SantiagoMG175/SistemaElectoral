#include "votacion.h"
#include "ui_votacion.h"


Votacion::Votacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Votacion)
{
    ui->setupUi(this);
    Sufragaron.enqueue(1);
}

Votacion::Votacion(QList<Persona*>padron, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Votacion)
{
    ui->setupUi(this);
    cedulaPersona = padron.at(0)->getCedula();
    nombre = padron.at(0)->getNombre();
}

Votacion::~Votacion()
{
    delete ui;
}

void Votacion::votar()
{

  int l = ui->Lasso->checkState();
  int a = ui->Arauz->checkState();

  if(l==0 and a==0){
      voto = "Blanco";

  }else if(l==2 and a==0){
      voto = "Lasso";

  } else if(l==0 and a==2){
      voto = "Arauz";

  }else {
      voto = "Nulo";
  }


}

void Votacion::on_Arauz_clicked()
{
    ui->Arauz->setText("Arauz.");
}

void Votacion::on_Lasso_clicked()
{
    ui->Lasso->setText("Lasso");
}



void Votacion::on_cmdVotar_clicked()
{

    votar();
    guardarVotos();
    Certificado *w = new Certificado(m_persona);

     hide();
    w->show();




}

void Votacion::guardarVotos()
{


        QFile m_votos;
         QTextStream m_datos;
         QString cedula;

         m_votos.setFileName("D:/Universidad/Programacion/Proyectos QT/SistemaElectoral/SistemaElectoral/documentos/votosGuardados.txt");
         m_votos.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);
         if(!m_votos.isOpen()){
             QMessageBox::information(0,"Advertencia","No se encontro la informacion");
             return ;
         }

         m_datos.setDevice(&m_votos);
         m_datos << voto<<";";

         time_t t;
          char fecha[100];
         struct tm *tm;
         t=time(NULL);
             tm=localtime(&t);
             strftime(fecha, 100, "%d/%m/%Y %H:%M:%S ", tm);

             msg = cedula + " " + fecha + " " + votospersona + "\n";

          m_datos << msg;

         m_votos.close();
         this->hide();

}

Persona *Votacion::persona() const
{
    return m_persona;
}

void Votacion::obtenerDatos(Persona *persona)
{

    m_persona = persona;


}
