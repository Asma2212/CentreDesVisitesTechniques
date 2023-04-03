#include "Agent.h"
#include "Equipement.h"
#include"CentreVT.h"
Agent::Agent()
{
    //ctor
}
istream& operator>>(istream& in,Agent& A)
{
    Personne *P=&A;
    in>>*P;
    cout<<"poste :";
    getline(in,A.poste);
    cout<<"remplir la table des visites"<<endl;
    char rep;
    do{VisiteTech *V=new VisiteTech();
        in>>*V;
        A.listVisites.push_back(V);
        cout<<"ajouter une visite "<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');
}
//ostream& operator<<(ostream&, Agent&);
void Agent::ConsulterEq(CentreVT& C)
{
    for(unsigned i=0;i<C.equipements.size();i++)
        cout<<C.equipements[i]<<'\t';
}
Equipement& Agent::rechEq(string rf, CentreVT& C)
{
    Equipement E("","",0);
    bool trouver=false;
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        if(rf==C.equipements[i]->rf)
        {
            return *C.equipements[i];
            trouver=true;
            break;
        }
    }
    if(trouver==false)
    {
        cout<<"equipement introuvable !"<<endl;
        return E;
    }
}
Agent::~Agent()
{
    //dtor
}

