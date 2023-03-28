#include "Agent.h"
#include "Equipement.h"
#include"CentreVT.h"
Agent::Agent()
{
    //ctor
}
void Agent::ConsulterEq(CentreVT& C)
{
    cout<<C;
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
        cout<<"equipement non trouve !"<<endl;
        return E;
    }
}
Agent::~Agent()
{
    //dtor
}

