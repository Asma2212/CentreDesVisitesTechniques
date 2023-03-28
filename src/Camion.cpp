#include "Camion.h"

Camion::Camion()
{
    //ctor
}
ostream& operator<<(ostream& out, Camion& c)
{
Vehicule *v;
v= new Camion(static_cast<const Camion&>(c));
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
}
Camion::~Camion()
{
    //dtor
}
