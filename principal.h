#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QQueue>
#include <votacion.h>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <persona.h>
#include <QDebug>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class principal; }
QT_END_NAMESPACE

class principal : public QMainWindow
{
    Q_OBJECT

public:
    principal(QWidget *parent = nullptr);
    ~principal();
    QQueue <QString> cedulas;
    QString nombre;
    QString cedula;

private slots:
    void on_pushButton_clicked();

private:
    Ui::principal *ui;
    void Archivo();
    QList <Persona*> m_usuario;
    void buscar();
    bool verificar();
    Persona *votacionPersona;



};
#endif // PRINCIPAL_H
