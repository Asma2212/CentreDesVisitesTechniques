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
void Moto::saisie(){
   Vehicule::saisie();
}
Moto::~Moto()
{
    //dtor
}
