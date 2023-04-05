#include "Camion.h"

Camion::Camion()
{
    //ctor
}

void Camion::affiche(){
    Vehicule::affiche();
    cout<<"charge: "<<charge<<endl;
    cout<<"nbRouesSupp: "<<nbRouesSupp<<endl;
    cout<<"etatRoueSupp: "<<etatRoueSupp<<endl;
}
void Camion::saisie(){
   Vehicule::saisie();
    cout<<"entrer le nombre de roue supplementaire"<<endl;
    cin>>nbRouesSupp;
    cout<<"entrer la charge du camion"<<endl;
    cin>>charge;
}
ostream& operator<<(ostream& out, Camion& c)
{
cout<<"ouuh ouuhh";
out<<c;
cout<<"charge: ";
out<<c.charge<<endl ;
return out;
}
istream& operator>>(istream& in, Camion& c)
{
in>>c;
c.nbRoues=4;
cout<<"entrer la charge du camion"<<endl;
in>>c.charge;
c.tarif=50;
//c.charge=11.3;
return in;
}

ostream& operator<<(ostream& out, Camion* c)
{
    Vehicule *v =c;
    out<<v;
   // out<<c->charge;
   // out<<c->nbRouesSupp;

    return out;
}
istream& operator>>(istream& in, Camion* c)
{
     Vehicule *v=c;
    in>>v;
   // in>>c->charge;
   // in>>c->nbRouesSupp;
    return in;
}
Camion::~Camion()
{
    //dtor
}
