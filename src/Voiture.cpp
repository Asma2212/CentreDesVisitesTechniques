#include "Voiture.h"

Voiture::Voiture()
{
    tarif=20.0;
    nbRoues=4;
}
void Voiture::affiche(){
    Vehicule::affiche();
}
void Voiture::saisie(){
   Vehicule::saisie();
}

istream& operator>>(istream& in, Voiture& v)
{
in>>v;
}

Voiture::~Voiture()
{
    //dtor
}
