#ifndef CERTIFICADO_H
#define CERTIFICADO_H

#include <QMainWindow>
#include <resultados.h>
#include <persona.h>
#include <QMainWindow>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QImage>
#include <QDesktopWidget>
#include <QDateTime>
#include "principal.h"
#include <QRectF>

namespace Ui {
class Certificado;
}

class Certificado : public QMainWindow
{
    Q_OBJECT

public:
    explicit Certificado(Persona *usuarios, QWidget *parent = nullptr);
    ~Certificado();
    void informacion(Persona);

private slots:
    void on_cmdGuardar_clicked();

    void on_cmdResultados_clicked();

private:
    Ui::Certificado *ui;

private:
    Persona m_persona;
    QPixmap lienzo;
    void dibujar(QString cedula, QString nombre);
    QImage *m_imagen;





};

#endif // CERTIFICADO_H
