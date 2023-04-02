#include "CentreVT.h"
#include "Equipement.h"
#include"Personne.h"
#include"Client.h"
CentreVT::CentreVT()
{
    //ctor
}
void CentreVT::creer(fstream &f)
{    f.open( "C:\CentreVT.txt", ios ::out| ios ::in |ios ::trunc) ;
     if( !(f.is_open()))
        exit(-1);
}
ostream& operator<<(ostream& out,CentreVT& C)
{
    out<<C.nom<<endl;
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        out<<*C.equipements[i]<<endl;
    }
    for(unsigned i=0;i<C.personnes.size();i++)
    {
        out<<*C.personnes[i]<<endl;
    }
    return out;
}
ostream& operator<<(ostream& out,CentreVT* C)
{
    out<<C->nom<<endl;
     for (int i=0; i<C->equipements.size(); i++)
            out<<*C->equipements[i]<<endl;


     for(int i=0;i<C->personnes.size();i++)
        {
            if(typeid(*C->personnes[i])==typeid(Personne))
                    out<<"1"<<*C->personnes[i]<<endl;
       /*   else if(typeid(*C->personnes[i])==typeid(Agent))
                    out<<"2"<<static_cast<Agent&>(*C->personnes[i])<<endl;
            else if(typeid(*C->personnes[i])==typeid(Client))
                    out<<"3"<<static_cast<Client&>(*C->personnes[i])<<endl;*/
        }
    /* for(int i=0;i<C->visites.size();i++)
        out<<*c.visites[i]<<endl;*/
     return out;
}
istream& operator>>(istream& in,CentreVT* C)
{   int choix;
    in.seekg(0);
    getline(in,C->nom,'\n');
    int i=0;
    while(1)
    {
        if(in.eof())break;
        Equipement * E = new Equipement() ;
        in>>*E;
        C->equipements.push_back(E);
    //    i+=1;
    }
   /* while(1)
    {
        in>>choix;
        if(in.eof()) break;
        if(choix==1)
        {
            Personne *P=new Personne();
            in>>*P;
            C->personnes.push_back(P);
        }
      /*if(choix==2)
        {
            Agent *A=new Agent();
            in>>*A;
            C->personnes.push_back(A);
        }
        if(choix==3)
        {
            Client *Cl=new Client();
            in>>*Cl;
            C->personnes.push_back(Cl);
        }*/
    //}
    return in;
}

CentreVT::~CentreVT()
{
    //dtor
}

