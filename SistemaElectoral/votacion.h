#ifndef VOTACION_H
#define VOTACION_H

#include <QMainWindow>

namespace Ui {
class Votacion;
}

class Votacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Votacion(QWidget *parent = nullptr);
    ~Votacion();

private:
    Ui::Votacion *ui;
};

#endif // VOTACION_H
