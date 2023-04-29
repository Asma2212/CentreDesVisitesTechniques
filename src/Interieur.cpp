#include "Interieur.h"

Interieur::Interieur()
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
bool Interieur::testDirection(Vehicule* v)
{
    char t;
    cout<<"\n********** Tester la direction **********"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatDirection();
    //*etatTest=false;
     return false ;
    }
    return true;
}
bool Interieur::testFrein(Vehicule* v)
{
    char t;
    cout<<"\n********** Tester les freins **********"<<endl;
    t=confirm();
    if(t=='n'){
    v->changeEtatFrein();
    //*etatTest=false;
     return false ;
    }
    return true;
}
Interieur::~Interieur()
{
    //dtor
}
