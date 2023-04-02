#include "Moto.h"

Moto::Moto()
{
    //ctor
}
void Moto::affiche(){
    Vehicule::affiche();
    cout<<"etatRoueAv: "<<etatRoueAv<<endl;
    cout<<"etatRoueAr: "<<etatRoueAr<<endl;
}
istream& operator>>(istream& in, Moto& m)
{
in>>m;
m.nbRoues=2;
m.tarif=30;
}
void Moto::saisie(){
   Vehicule::saisie();
}
Moto::~Moto()
{
    //dtor
}
