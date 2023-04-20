#include "Moto.h"

Moto::Moto()
{
    tarif=10.0;
    nbRoues=2;
}
void Moto::affiche(){
    Vehicule::affiche();
}
istream& operator>>(istream& in, Moto& m)
{
in>>m;
}
void Moto::saisie(){
   Vehicule::saisie();
}
Moto::~Moto()
{
    //dtor
}
