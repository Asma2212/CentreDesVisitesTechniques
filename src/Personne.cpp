#include "Admin.h"
#include "Client.h"
#include "Personne.h"
Personne::Personne(){};

Personne::Personne(const Personne& p)
    {
    cn=p.cn;
    email=p.email;
    mdp=p.mdp;
    nom=p.nom;
    prenom=p.prenom;
    numTel=p.numTel;
    dateNaiss=p.dateNaiss;
        for (unsigned i = 0; i < p.professions.size(); ++i) {
            professions[i] = new string(*p.professions[i]);
        }
    }

Personne& Personne::operator=(const Personne& p) {
if (this != &p) {
    cn = p.cn;
    email = p.email;
    mdp = p.mdp;
    nom = p.nom;
    prenom = p.prenom;
    numTel = p.numTel;
    dateNaiss = p.dateNaiss;
    for (unsigned i = 0; i < p.professions.size(); ++i)
        professions[i] = new string(*p.professions[i]);
    }
    return *this;
    }

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
    /*in.ignore(); //check
    getline(in,P.nom,'\n');
    getline(in,P.prenom,'\n');*/
    in>>P.nom;
    in>>P.prenom;
   /* cout<<"numero de telephone"<<endl;
    in>>P.numTel;
    cout<<"date de naissance"<<endl;
    in>>P.dateNaiss;*/
    cout<<"email"<<endl;
    /*in.ignore();
    getline(in,P.email,'\n');*/
    in>>P.email;
    cout<<"mots de passe"<<endl;
    //getline(in,P.mdp,'\n');
    in>>P.mdp;
    return in;

}

ostream& operator<<(ostream& out, Personne* p)
{
    //enregistrer dans fichier
if(typeid(*p)==typeid(Admin))
{
    out<<"Admin"<<endl;
    //out<<new Admin(static_cast<Admin&>(*p))<<endl;
}
else
    if(typeid(*p)==typeid(Agent))
    {
        out<<"Agent"<<endl;;
        //out<<new Agent(static_cast<Agent&>(*p))<<endl;
    }

    else
    {
        out<<"Client"<<endl;
        //out<<new Client(static_cast<Client&>(*p))<<endl;
    }

    out<<p->cn<<endl;
    out<<p->email<<endl;
    out<<p->mdp<<endl;
    out<<p->nom<<endl;
    out<<p->prenom<<endl;
    out<<p->numTel<<endl;
    out<<&p->dateNaiss;


    return out;
}

istream& operator>>(istream& in, Personne* p)
{
    string ch;
    int i;
    in>>p->cn;
    in>>p->email;
    in>>p->mdp;
    in>>p->nom;
    in>>p->prenom;
    in>>p->numTel;
    in>>p->dateNaiss;

    return in;
}


Personne::~Personne()
{
for (unsigned i = 0; i < professions.size(); ++i)
    delete professions[i];
}

