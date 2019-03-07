#include "voiture.h"
#include <stdexcept>

Voiture::Voiture()
{
mModele = "";
mKilometrage=0;
mJaugeCarburant=0;
}

Voiture::Voiture(QString modele):mModele(modele)
{

}
//une autre façon d'ecriture
Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant):
    mModele(modele), mKilometrage(kilometrage), mJaugeCarburant(jaugeCarburant)
{
}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

void Voiture::rouler(int distance)
{

    //if precondition pas verifiée
    //conso si <150000 = distance *5, si faux distance *10
    int conso = (kilometrage()<150000) ? distance * 5 : distance * 10;
    if(conso > jaugeCarburant())
    {
        throw std::invalid_argument("pas assez d'essence");
    }
    else
    {
        setKilometrage(kilometrage() + distance);
        setJaugeCarburant(jaugeCarburant() - conso);
    }

}

