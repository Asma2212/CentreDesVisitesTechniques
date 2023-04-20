#include "Camion.h"

Camion::Camion()
{
    tarif=30.0;
    nbRoues=4;
}

void Camion::affiche(){
    Vehicule::affiche();
    cout<<"charge: "<<charge<<endl;
    cout<<"nbRouesSupp: "<<nbRouesSupp<<endl;
    cout<<"etatRoueSupp: ";
    {
    if(etatRoueSupp==1)
        cout<<"valide "<<endl;
    else
        cout<<"non valide X"<<endl;
}
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
out<<c;
cout<<"charge: ";
out<<c.charge<<endl ;
cout<<"nombre de roues: ";
out<<c.nbRouesSupp<<endl ;
cout<<"etat roues :";
out<<c.etatRoueSupp<<endl;
return out;
}
istream& operator>>(istream& in, Camion& c)
{
in>>c;
c.nbRoues=4;
cout<<"entrer la charge du camion"<<endl;
in>>c.charge;
cout<<"entrer le nombre des roues supp"<<endl;
in>>c.nbRouesSupp;
//c.charge=11.3;
return in;
}

ostream& operator<<(ostream& out, Camion* c)
{
    Vehicule *v =c;
    out<<v;
    out<<c->charge<<endl;
    out<<c->nbRouesSupp<<endl;
    out<<c->etatRoueSupp<<endl;

    return out;
}
istream& operator>>(istream& in, Camion* c)
{
     Vehicule *v=c;
    in>>v;
   in>>c->charge;
   in>>c->nbRouesSupp;
    in>>c->etatRoueSupp;
    return in;
}
Camion::~Camion()
{
    //dtor
}
