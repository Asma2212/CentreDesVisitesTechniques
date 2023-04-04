#include "Personne.h"
#include"CentreVT.h"

ostream& operator<<(ostream& out, Personne& P)
{
    cout<<"cin: ";
    out<<P.cn<<endl;
    cout<<"nom et prenom: ";
    out<<P.nom<<" "<<P.prenom<<endl;
    cout<<"numero de telephone: ";
    out<<P.numTel<<endl;
    cout<<"date de naissance: ";
    out<<P.dateNaiss;
    cout<<"email: ";
    out<<P.email<<endl;
    cout<<"mot de passe: ";
    out<<P.mdp<<endl;
    return out;

}
istream& operator>>(istream& in, Personne& P)
{
    cout<<"cin"<<endl;
    in>>P.cn;
    cout<<"nom et prenom"<<endl;
    in.ignore(); //check
    getline(in,P.nom,'\n');
    getline(in,P.prenom,'\n');
   /* cout<<"numero de telephone"<<endl;
    in>>P.numTel;
    cout<<"date de naissance"<<endl;
    in>>P.dateNaiss;*/
    cout<<"email"<<endl;
    in.ignore();
    getline(in,P.email,'\n');
    cout<<"mots de passe"<<endl;
    getline(in,P.mdp,'\n');
    return in;

}

void Personne::modifierD(CentreVT& C)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le cin de la personne a modifier "<<endl;
    cin>>this->cn;
    while(i<C.personnes.size()) //modifier la condition de while.
    {
        if(this->cn==C.personnes[i]->cn)
        {
            cin>>*C.personnes[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"personne non trouve !"<<endl;

}
Personne::~Personne()
{
    //dtor
}

