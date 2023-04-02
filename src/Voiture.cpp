#include "Voiture.h"

Voiture::Voiture()
{
    //ctor
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
v.nbRoues=4;
v.tarif=40;
}

Voiture::~Voiture()
{
    //dtor
}
