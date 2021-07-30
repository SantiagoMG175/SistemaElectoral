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

void Resultados::abrirArchivo()
{
    /*
    QFile m_archivo;
    m_archivo.setFileName("C:/Users/Usuario/Downloads/Ventanas/Login/Recursos/Votaciones.txt");
    QTextStream votos;
    m_archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!m_archivo.isOpen()){
        QMessageBox::warning(0,"AVISO IMPORTANTE", "No se pudo abrir el archivo con los votos");
        return;
    }

    votos.setDevice(&m_archivo);
    while(!votos.atEnd()){

        auto linea = votos.readLine();
        auto split = linea.split(";");

        for(int i=0; i<split.size(); i++ ){
            auto datos = split.at(0);
            if(i == 0){

                if(datos == "Arauz" ){
                    m_contadorLasso = datos;
                    lasso.push(m_contadorLasso);
                    m_glasso = lasso.size();
                }




}
*/

}
