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
    cout<<"entrer la charge du camion"<<endl;
    cin>>charge;
}
ostream& operator<<(ostream& out, Camion& c)
{
cout<<"jeee";
out<<c;
cout<<"charge: ";
out<<c.charge<<endl ;
}
istream& operator>>(istream& in, Camion& c)
{
/*Vehicule *v;
v= new Camion(static_cast<const Camion&>(c));
cin>>*v;
cout<<v;
c = (Camion)v ;*/
in>>c;
cout<<"entrer la charge du camion"<<endl;
in>>c.charge;
//c.charge=11.3;
}
Camion::~Camion()
{
    //dtor
}
