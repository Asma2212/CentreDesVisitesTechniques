#include "Exterieur.h"

Exterieur::Exterieur()
{
    //ctor
}
char confirm()
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
    cout<<"Tester la carrosserie"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatCarosserie();
     return false ;
    }
    return true;
}
bool Exterieur::testFeux(Vehicule* v)
{
        char t;
    cout<<"Tester Feux"<<endl;
t=confirm();
    if(t=='m'){
     //v->changeEtatFeux();
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
    cout<<"Tester les roues"<<endl;
    if(typeid(*v) == typeid(Camion))
        {
    //v=&m;
    //v=new Moto();
    cout<<"Tester roue Supplementaire"<<endl;
    t=confirm();
    if(t=='n'){
     static_cast<Camion*>(v)->changeEtatRoueSupp();
     return false ;
    }
    }
    cout<<"Tester roue"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatRoues();
    }

    return true;
}

Exterieur::~Exterieur()
{
    //dtor
}
