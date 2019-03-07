#include <QCoreApplication>
#include <QDebug>
#include "voiture.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "------**Welcome to voiture application**-------";

    Voiture oldCar ("Ford Mustang 1967", 1600000, 500);
    oldCar.rouler(10);
    qDebug() << "My car : " <<oldCar.modele();
    return a.exec();
}
