#include "Reservation.h"

Reservation::Reservation()
{
    //this->codeR++ ;
}
istream& operator>>(istream& in, Reservation& r)
{
    int type;
    Vehicule *v ;
    cout<<"date de reservation"<<endl;
    in>>r.dateR;
    cout<<"heure"<<endl;
    in>>r.heure;
    cout<<"Votre vehicule"<<endl;
    cout<<"entrer le type du vehicule"<<endl;
    cout<<"1:camion"<<endl;
    cout<<"2:moto"<<endl;
    cout<<"3:voiture"<<endl;
    cin>>type;
    switch(type)
    {
        case 1 :
            {
        Camion cm;
        cm.saisie();
        cm.affiche();
        /*cin>>*v;
        cout<<"AFFICHAAAGEEEEE"<<endl;
        cout<<v;*/
            //v = new Camion(static_cast<const Camion&>(cm));
             break;
            }
        case 2 :
        {
          Moto mt;
          cin>>mt;
            v = new Moto(static_cast<const Moto&>(mt)); break;

        }
       case 3 :
        {
              Voiture vt;
              cin>>vt;
             v = new Voiture(static_cast<const Voiture&>(vt));break;

        }
        }
    return in;

}
Reservation::~Reservation()
{
    //dtor
}
