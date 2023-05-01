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
void Reservation::modifierRes(int cd,Client& C)
{
    vector<Reservation> L;
    int i=0;
    bool trouver=false;
    L=C.getList();
    while(i<L.size())
    {
        if(rf==L[i].codeR)
        {
            cout<<"Donnez la nouvelle date : ";
            cin>>L[i].dateR;
            cout<<"Donnez une nouvelle heure : ";
            cin>>L[i].heure;
            TimeDate* D= new TimeDate();
            *D=D->tempsCourant();
            L[i]->modificationEff.push(D);
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver==false)
        cout<<"Reservation introuvable !"<<endl;
    else
        cout<<"modification terminee"<<endl;
}

ostream& operator<<(ostream& out, Reservation& r)
{
    cout<<"code de Reservation: ";
    out<<r.codeR<<endl;
    cout<<"date de Reservation: ";
    out<<r.dateR;
    cout<<"heure : ";
    out<<r.heure<<endl;
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
    //enregistrer dans fichier

    out<<r->codeR<<endl;
    out<<&r->dateR;
    out<<r->heure<<endl;
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
   in>>r->codeR;
    in>>r->dateR;
    in>>r->heure;
    in>>ch;
   // in>>r->v;
      if(ch=="Camion")
{
    Camion* c =new Camion();
       in>>c;
    r->v=c;
}

else
    if(ch=="Moto")
        {
        Moto* m =new Moto();
       in>>m;
        r->v=m;
        }
    else
    {

        Voiture* vt =new Voiture();
        in>>vt;
        r->v=vt;
    }

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
