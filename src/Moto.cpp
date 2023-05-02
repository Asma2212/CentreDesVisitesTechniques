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
stack<int*> Moto::getVE2()
{
    stack<int*> L;
    for(unsigned i=0;this->visiteEff2.size();i++)
       {
           L.push(this->visiteEff2.top());
           this->visiteEff2.pop();
       }
    return L;
}
void Moto::saisie(){
   Vehicule::saisie();
}
Moto::~Moto()
{
    //dtor
}
