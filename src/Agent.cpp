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
void Agent::sinscrire(CentreVT& C)
{
   char rep;
    do{
        Agent *A=new Agent();
        cin>>*A;
        C.personnes.push_back(A);
        cout<<"ajouter un agent"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');
}
void Agent::authentifier(CentreVT& C)
{
    string mdp;
    Agent A;
    int cn;
    char choix;
    bool cnCorr= false;
    bool auth=false;
    while(!auth)
    {
        cout<<"entrez votre cin"<<endl;
        cin>>cn;
        cout<<"entrez votre mot de passe "<<endl;
        cin>>mdp;
        for(unsigned i=0;i<C.personnes.size();i++)
        {
            cnCorr=true;
            if(cn==C.personnes[i]->cn)
            {
                if(mdp.compare(C.personnes[i]->mdp)==0)
                {
                    cout<<"vous etes connecte avec succes "<<endl;
                    auth=true;
                    break;
                }
                else
                {
                    cout<<"mot de passe incorrect !"<<endl;
                    break;
                }
            }
        }
        if(!cnCorr){
            cout<<"cn introuvable !"<<endl;
            cout<<"Taper 'r' pour retourner et 'c' pour continuer"<<endl;
            cin>>choix;
            if((choix == 'r' )|| (choix == 'R'))
                throw MyExceptions("erreur d'authentification");
        }

    }
}
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

