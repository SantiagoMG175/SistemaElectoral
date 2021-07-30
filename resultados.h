#ifndef RESULTADOS_H
#define RESULTADOS_H
#include <QtDebug>
#include <QFile>
#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMainWindow>
#include <principal.h>
#include <votacion.h>
#include <certificado.h>
#include <QQueue>


namespace Ui {
class Resultados;
}

class Resultados : public QMainWindow
{
    Q_OBJECT

public:
    explicit Resultados(QWidget *parent = nullptr);
    ~Resultados();

private:
    Ui::Resultados *ui;
    void abrir();


};

#endif // RESULTADOS_H
