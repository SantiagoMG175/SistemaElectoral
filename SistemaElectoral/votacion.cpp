#include "votacion.h"
#include "ui_votacion.h"

Votacion::Votacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Votacion)
{
    ui->setupUi(this);
}

Votacion::~Votacion()
{
    delete ui;
}
