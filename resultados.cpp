#include "resultados.h"
#include "ui_resultados.h"

Resultados::Resultados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);
}


Resultados::~Resultados()
{
    delete ui;
}

void Resultados::abrir()
{

    {
        QQueue <QString> m_Lasso;
        QQueue <QString> m_Arauz;
        QQueue <QString> m_Blanco;
        QQueue <QString> m_Nulo;



        QFile archivo;
        archivo.setFileName("D:/Universidad/Programacion/Proyectos QT/SistemaElectoral/SistemaElectoral/documentos/votosGuardados.txt");
        QTextStream votos;
        archivo.open(QIODevice::ReadOnly | QIODevice::Text);


        if(!archivo.isOpen()){
            QMessageBox::warning(0,"AVISO IMPORTANTE", "No se pudo abrir el archivo con los votos");
            return;
        }
        votos.setDevice(&archivo);
        while(!votos.atEnd()){

            auto linea = votos.readLine();
            auto split = linea.split(";");



            for(int i=0; i<split.size(); i++ ){

                auto datos = split.at(0);
                if(i == 0){

                    if(datos == "Lasso" ){
                        QString contadorL = datos;
                        m_Lasso.push_back(contadorL);
                        m_Lasso.size();
                    }
                    if(datos == "Arauz"){
                        QString contadorA = datos;
                        m_Arauz.push_back(contadorA);
                        m_Arauz.size();
                    }
                    if(datos == "Blanco"){
                        QString contadorB = datos;
                        m_Blanco.push_back(contadorB);
                        m_Blanco.size();
                    }
                    if(datos == "Nulo"){
                        QString contadorN = datos;
                        m_Nulo.push_back(contadorN);
                        m_Nulo.size();


                        }
                    }

                }


            }
            archivo.close();

    }


}
