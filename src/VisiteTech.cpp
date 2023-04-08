#include "VisiteTech.h"
#include"Test.h"
#include"Exterieur.h"
#include"Interieur.h"

VisiteTech::VisiteTech()
{
    //ctor
}
ostream& operator<<(ostream& out, VisiteTech& V)
{
    out<<"code : "<<V.codeV<<endl;
    out<<"testes"<<endl;
    out<<V.etatExt<<endl;
    out<<V.etatInt<<endl;
          return out;
}
istream& operator>>(istream& in, VisiteTech& V)
{
    cout<<"code"<<endl;
    in>>V.codeV;

}
void VisiteTech::modifierVisite(CentreVT C,string code)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le code de la visite a modifier "<<endl;
    cin>>this->codeV;
    while(i<C.visites.size())
    {
        if(this->codeV==C.visites[i]->codeV)
        {
            cin>>*C.visites[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"visite non trouve !"<<endl;

}
void VisiteTech::saisitEtatExt(Vehicule *V)
{
    Exterieur E;
    if(E.testRoues(V)==true && E.testCarrosserie(V)==true && E.testFeux(V)==true)
        etatExt=true;
    else
        etatExt=false;
}
void VisiteTech::saisiEtatInt(Vehicule *V)
{
    Interieur I;
    if(I.testFrein(V)==true && I.testDirection(V)==true)
            etatInt=true;
    else
        etatInt=false;
}
VisiteTech::~VisiteTech()
{
    //dtor
}
