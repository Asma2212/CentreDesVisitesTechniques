#include "Equipement.h"
#include"CentreVT.h"

Equipement::Equipement()
{
    //ctor
}
Equipement::Equipement(string a,string b,int c)
{
    rf=a;
    libelle=b;
    quantite=c;
}
/*string Equipement::getref()
{
   return this->rf;
}*/
ostream& operator<<(ostream& out,const Equipement* E)
{
    out<<E->quantite<<endl;
    out<<E->rf<<endl;
    out<<E->libelle<<endl;

    return out;
}
istream& operator>>(istream& in,Equipement* E)
{
    in>>E->quantite;
    in.ignore();
    getline(in,E->rf,'\n');
    getline(in,E->libelle,'\n');
    return in;
}
istream& operator>>(istream& in,Equipement& E)
{
   // cout<<"quantite"<<endl;
    in>>E.quantite;
  //  cout<<"reference"<<endl;
    in.ignore();
    getline(in,E.rf,'\n');
 //   cout<<"libelle"<<endl;
    getline(in,E.libelle,'\n');
    return in;
}
ostream& operator<<(ostream& out,const Equipement& E)
{
  //  out<<"quantite: ";
    out<<E.quantite<<endl;
   // out<<"reference: ";
    out<<E.rf<<endl;
  //  out<<"libelle: ";
    out<<E.libelle<<endl;

    return out;
}


void Equipement::ajouterEq(CentreVT& C)
{
    char rep;
    do{
        Equipement *E=new Equipement();
        cin>>*E;
        C.equipements.push_back(E);
        cout<<"ajouter un equipement"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}
void Equipement::suppEq(string rf,CentreVT& C)
{
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        if(rf==C.equipements[i]->rf)
        {
            C.equipements.erase(C.equipements.begin()+i);
            break;
        }
    }
}
void Equipement::modifierEq(string rf,CentreVT& C)
{
    int i=0;
    bool trouver=false;
    while(i<C.equipements.size()) //modifier la condition de while.
    {
        if(rf==C.equipements[i]->rf)
        {
            cout<<"Donnez la nouvelle valeur du libelle : ";
            cin>>C.equipements[i]->libelle;
            cout<<"Donnez la nouvelle valeur de la quantite : ";
            cin>>C.equipements[i]->quantite;
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"equipement non trouve !"<<endl;

}
Equipement::~Equipement()
{
    //dtor
}
