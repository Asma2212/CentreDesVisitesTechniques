#include "Interieur.h"

Interieur::Interieur()
{
    //ctor
}
bool Interieur::testDirection(Vehicule* V)
{
    char t;
    cout<<"Tester la direction "<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
    // V->changeEtatDirection();
     return false ;
    }
    return true;
}
bool Interieur::testFrein(Vehicule* V)
{
    char t;
    cout<<"Tester les freins"<<endl;
    do{
    cout<<"s'il est en bon etat entrez o sinon entrer m"<<endl;
    cin>>t;
    }while((t!='o')&&(t!='m'));
    if(t=='m'){
    // V->changeEtatFrein();
     return false ;
    }
    return true;
}
Interieur::~Interieur()
{
    //dtor
}
