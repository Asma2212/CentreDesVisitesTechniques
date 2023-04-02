#include "Reservation.h"

Reservation::Reservation()
{
    this->codeR++ ;
}
ostream& operator<<(ostream& out, Reservation& r)
{
    cout<<"code de Reservation: ";
    out<<r.codeR;
    cout<<"date de Reservation: ";
    out<<r.dateR;
    cout<<"heure : ";
    out<<r.heure;
    cout<<"vehicule : ";
    if(typeid(*r.v) == typeid(Camion))
        {
            r.v=new Camion(static_cast<const Camion&>(*r.v));
            cout<<"CAMION"<<endl;
        }
    else
        if(typeid(*r.v) == typeid(Moto))
           {
             cout<<"MOTO"<<endl;
           }

        else
            cout<<"VOITURE"<<endl;
    //out<<*r.v;
    r.v->affiche();
    return out;
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

ostream& operator<<(ostream& out, Reservation* r)
{
    cout<<"res out elli bl *"<<endl;
    out<<r->dateR;
    out<<r->heure;
    out<<*r->v;
    return out;
}

istream& operator>>(istream& in, Reservation* r)
{
    Vehicule *v1 = new Vehicule();
    cout<<"res elli bl *"<<endl;
    //in.getline(r->dateR, 100, '\n');
    in>>r->dateR;
    //cout<<"date"<<r->dateR;
    in>>r->heure;
        cout<<"heure"<<r->heure;
    in>>v1;
    r->v=v1;
    return in;
}
istream& operator>>(istream& in, Reservation& r)
{
   int type,e;
   cout<<"res elli bl &"<<endl;
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


