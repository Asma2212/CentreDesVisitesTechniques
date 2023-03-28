#include "CentreVT.h"
#include "Equipement.h"
#include"Personne.h"
CentreVT::CentreVT()
{
    //ctor
}
ostream& operator<<(ostream& out,CentreVT& C)
{
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
CentreVT::~CentreVT()
{
    //dtor
}

