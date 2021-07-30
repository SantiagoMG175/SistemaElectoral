#ifndef VOTACION_H
#define VOTACION_H

#include <QMainWindow>
#include <certificado.h>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <persona.h>
#include <QLineEdit>
#include <QDebug>
#include <QList>
#include <QQueue> //Libreria para ED
#include <QFile>
#include <time.h>
#include <ctime>
#include <principal.h>

namespace Ui {
class Votacion;
}

class Votacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Votacion(QWidget *parent = nullptr);
    explicit Votacion(QList<Persona*> padron, QWidget *parent = nullptr);
    ~Votacion();
    void votar();
    QString cedulaPersona;
    QString nombre;
    Persona *persona() const;
    void obtenerDatos(Persona *persona);
    QString msg;

private slots:


    void on_Arauz_clicked();

    void on_Lasso_clicked();

    void on_cmdVotar_clicked();

private:
    Ui::Votacion *ui;

private:
    QString votospersona;
    QList<Persona*>Votos;
    QString m_usuarios;
    QQueue <int> Sufragaron;
    void guardarVotos();
    Persona *m_persona;
    QString voto;
    QString fecha;



};

#endif // VOTACION_H
