#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    cedulas.enqueue("1708541907");
    cedulas.enqueue("1751426584");
    cedulas.enqueue("1710546084");

}

principal::~principal()
{
    delete ui;
}


void principal::on_cmdIngresar_clicked()
{

   v.show();


}
