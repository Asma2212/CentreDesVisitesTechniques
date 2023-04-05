#include "Personne.h"
#include"CentreVT.h"
Personne::Personne(){};
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


Personne::~Personne()
{
    //dtor
}

