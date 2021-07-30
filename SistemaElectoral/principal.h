#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QQueue>
#include <votacion.h>
#include<QFileDialog>
#include <QDir>
#include<QFile>
#include<QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui { class principal; }
QT_END_NAMESPACE

class principal : public QMainWindow
{
    Q_OBJECT

public:
    principal(QWidget *parent = nullptr);
    ~principal();
    bool validar(QString);

     QQueue <QString> cedulas;

private slots:
     void on_cmdIngresar_clicked();

private:
    Ui::principal *ui;

  private:
    Votacion v;

};
#endif // PRINCIPAL_H
