#include "Reservation.h"

int Reservation::nbInstance = 0;

Reservation::Reservation()
{
    nbInstance++;
    codeR=nbInstance;
}

Reservation::Reservation(const Reservation & r)
{
    codeR=r.codeR;
    dateR=r.dateR;
    heure=r.heure;
    v=r.v;

}
Reservation& Reservation::operator=(const Reservation & r)
{
if(this!=&r)
{
delete[]r.v;
codeR=r.codeR;
dateR=r.dateR;
heure=r.heure;
}
return *this;
}


ostream& operator<<(ostream& out, Reservation& r)
{
    cout<<"code de Reservation: ";
    out<<r.codeR<<endl;
    cout<<"date de Reservation: ";
    out<<r.dateR;
    cout<<"heure : ";
    out<<r.heure<<endl;
   /* cout<<"vehicule : ";
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
            cout<<"VOITURE"<<endl;*/
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
    //enregistrer dans fichier

    out<<r->codeR<<endl;
    out<<&r->dateR;
    out<<r->heure<<endl;
   /* out<<"vehicule : ";
    if(typeid(*r->v) == typeid(Camion))
        {
            r->v=new Camion(static_cast<const Camion&>(*r->v));
            out<<"CAMION"<<endl;
        }
    else
        if(typeid(*r->v) == typeid(Moto))
           {
             out<<"MOTO"<<endl;
           }

        else
            out<<"VOITURE"<<endl;*/
   /* out<<r->dateR;
    out<<r->heure<<endl;*/
if(typeid(*r->v)==typeid(Camion))
{
    out<<"Camion"<<endl;
    out<<new Camion(static_cast<Camion&>(*r->v))<<endl;
}
else
    if(typeid(*r->v)==typeid(Moto))
    {
        out<<"Moto"<<endl;;
        out<<new Moto(static_cast<Moto&>(*r->v))<<endl;
    }

    else
    {
        out<<"Voiture"<<endl;
        out<<new Voiture(static_cast<Voiture&>(*r->v))<<endl;
    }


    return out;
}

istream& operator>>(istream& in, Reservation* r)
{
    string ch;
    int i;
    Vehicule *v1 = new Vehicule() ;
   in>>r->codeR;
    in>>r->dateR;
    //cout<<"date"<<r->dateR;
    in>>r->heure;
    in>>ch;
   // in>>v1;
 /*      if(ch=="Camion")
{
    cout<<"dkhaal affiche";
    v1=new Camion(static_cast<Camion&>(*r->v));
    in>>v1;
    v1->affiche();
}

/*else
    if(typeid(*r->v)==typeid(Moto))
        {
        v1=new Moto(static_cast<Moto&>(*r->v));
        in>>v1;
        }
    else
    {

        v1=new Voiture(static_cast<Voiture&>(*r->v));
        in>>v1;
    }*/
   //
    //

    in>>v1;
    r->v=v1;

    return in;
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
