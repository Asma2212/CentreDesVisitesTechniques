#include "Exterieur.h"

Exterieur::Exterieur()
{
    //ctor
}
char confirmer()
{
    char t;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer n"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='n'));
    return t;
}
bool Exterieur::testCarrosserie(Vehicule* v)
{
    char t;
    cout<<"\n********** Tester la carrosserie **********"<<endl;
    t=confirmer();
    if(t=='n'){
    v->changeEtatCarosserie();
    //*etatTest=false;
     return false ;
    }
    return true;
}
bool Exterieur::testFeux(Vehicule* v)
{
        char t;
    cout<<"\n********** Tester Feux **********"<<endl;
    t=confirmer();
    if(t=='n'){
     v->changeEtatFeux();
     //*etatTest=false;
     return false ;
    }
    return true;
}
bool Exterieur::testRoues(Vehicule* v)
{
Voiture *vt;
    Moto m;
    Camion*c;
    char t;
    cout<<"\n********** Tester les roues **********\n"<<endl;
    if(typeid(*v) == typeid(Camion))
        {
    cout<<"********** Tester roue Supplementaire **********\n"<<endl;
    t=confirmer();
    if(t=='n'){
     static_cast<Camion*>(v)->changeEtatRoueSupp();
    }
    }
    cout<<"********** Tester les roues normal **********"<<endl;
    t=confirmer();
    if(t=='n'){
    //*etatTest=false;
    v->changeEtatRoues();
    return false;
    }

    return true;
}

Exterieur::~Exterieur()
{
    //dtor
}
