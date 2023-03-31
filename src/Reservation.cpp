#include "Reservation.h"

Reservation::Reservation()
{
    //this->codeR++ ;
}
ostream& operator<<(ostream& out, Reservation& r)
{

      out<<"date de Reservation: ";
    out<<r.dateR;
      out<<"heure : ";
    out<<r.heure<<endl;
    out<<"vehicule : ";
    if(typeid(*r.v) == typeid(Camion))
        out<<"CAMION"<<endl;
    else
        if(typeid(*r.v) == typeid(Moto))
            out<<"MOTO"<<endl;
        else
            out<<"VOITURE"<<endl;
    out<<*r.v;
    //r.v->affiche();
}
void Reservation::saisieRes(){
    int type;
    cout<<"date de reservation"<<endl;
    cin>>dateR;
    cout<<"heure"<<endl;
    cin>>heure;
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
      //  v=cm;
        setVehicule(cm);
        break;
            }
        case 2 :
        {
            Moto mt;
            mt.saisie();
            setVehicule(mt);
            break;

        }
       case 3 :
        {
            Voiture vt;
            vt.saisie();
            setVehicule(vt);
             break;

        }
        }

}
istream& operator>>(istream& in, Reservation& r)
{
   int type,e;
    do{
    cout<<"Date de reservation"<<endl;
    in>>r.dateR;
    }while(!r.dateR.verifDate(r.dateR.dateCourante()));
    do{
    cout<<"Heure exacte (on travail de 8h a 17h)"<<endl;
    in>>r.heure;
    }while(r.heure<8 || r.heure >17);
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
      //  v=cm;
        r.v=new Camion(static_cast<const Camion&>(cm));
        break;
            }
        case 2 :
        {
            Moto mt;
            mt.saisie();
            r.v=new Moto(static_cast<const Moto&>(mt));
            break;

        }
       case 3 :
        {
            Voiture vt;
            vt.saisie();
            r.v=new Voiture(static_cast<const Voiture&>(vt));
             break;

        }
        }
    return in;

}

void Reservation::setVehicule(Vehicule& v1){

    if(typeid(v1) == typeid(Camion))
        v=new Camion(static_cast<const Camion&>(v1));
    else
        if(typeid(v1) == typeid(Moto))
            v=new Moto(static_cast<const Moto&>(v1));
        else
            v=new Voiture(static_cast<const Voiture&>(v1));
}


