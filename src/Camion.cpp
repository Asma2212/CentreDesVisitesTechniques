#include "Camion.h"

Camion::Camion()
{
    //ctor
}
void Camion::affiche(){
    Vehicule::affiche();
        cout<<"charge: ";
    cout<<charge<<endl;
}
void Camion::saisie(){
   Vehicule::saisie();
    cout<<"entrer la charge du camion"<<endl;
    cin>>charge;
}
/*ostream& operator<<(ostream& out, Camion& c)
{
Vehicule *v;
//v= new Camion(static_cast<const Camion&>(c));
operator<<(out,*v);

cout<<"charge: ";
out<<c.charge<<endl ;
}
istream& operator>>(istream& in, Camion& c)
{
Vehicule *v;
v= new Camion(static_cast<const Camion&>(c));
cin>>*v;
cout<<v;
//c = (Camion)v ;
c.charge=11.3;
cout<<"dddddd"<<c.marque<<endl;
}*/
Camion::~Camion()
{
    //dtor
}
