#include "Exterieur.h"

Exterieur::Exterieur()
{
    //ctor
}
bool Exterieur::testCarrosserie(Vehicule* v)
{
    char t;
    cout<<"Tester la carrosserie"<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
     v->changeEtatCarosserie();
     return false ;
    }
    return true;
}
bool Exterieur::testFeux(Vehicule* v)
{
        char t;
    cout<<"Tester Feux"<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
     v->changeEtatFeux();
     return false ;
    }
    return true;
}
bool Exterieur::testRoues(Vehicule* v)
{
    char t;
    cout<<"Tester les roues"<<endl;
    if(typeid(v) == typeid(Moto)){
    v=new Moto(static_cast<const Moto&>(*v));
    cout<<"Tester roue avant "<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
     //v->changeEtatRoueAv();
     return false ;
     }
     cout<<"Tester roue arriere "<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
     //v->changeEtatRoueAr();
     return false ;
    }}else
    if(typeid(v) == typeid(Voiture))
    {

    }
    else
    {

    }
    return true;
}
Exterieur::~Exterieur()
{
    //dtor
}
