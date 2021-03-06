#include "principal.h"
#include <QApplication>
#include <QDate>
#include <QMessageBox>
#include <QObject>
#define FECHA "30-07-2021"
#define HORAINICIAL "00:00"
#define HORAFINAL "23:59"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal electoral;

    QDate diaElectoral = QDate::fromString(FECHA, "dd-MM-yyyy");
    QTime tiempoElectoralI = QTime::fromString(HORAINICIAL, "hh:mm");
    QTime tiempoElectoralF = QTime::fromString(HORAFINAL, "hh:mm");
    if(diaElectoral == QDate::currentDate())
    {
        if(QTime::currentTime() >= tiempoElectoralI && QTime::currentTime() <= tiempoElectoralF)
            electoral.show();
       else
            QMessageBox::warning(NULL, "Votaciones","Hora no válida para votar."
                                       "\nHora para sufragar (" HORAINICIAL "-" HORAFINAL ")");
    }
    else
        QMessageBox::warning(NULL, "Votaciones", "No permitido votar en este día."
                                                 "\n Día para sufragar (" FECHA ")");

    return a.exec();
}
