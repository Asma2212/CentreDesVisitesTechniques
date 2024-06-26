#include "Equipement.h"

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

Equipement::Equipement(const Equipement& eq){
stack<TimeDate*> tempStack = eq.modeff;
while(!tempStack.empty()){
    this->modeff.push(tempStack.top());
    tempStack.pop();
    }
}

Equipement& Equipement::operator=(const Equipement& q){
stack<TimeDate*> tempStack = q.modeff;
if (this != &q) {
while(!modeff.empty()){
    delete modeff.top();
}
//this->visiteEff1.clean();
while(!tempStack.empty()){
    this->modeff.push(tempStack.top());
    tempStack.pop();
}
}
        return *this;
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
    in>>E->rf;
    in>>E->libelle;
    return in;
}
istream& operator>>(istream& in,Equipement& E)
{
    cout<<"quantite"<<endl;
    in>>E.quantite;
    cout<<"reference"<<endl;
    in.ignore();
    getline(in,E.rf,'\n');
    cout<<"libelle"<<endl;
    getline(in,E.libelle,'\n');
    return in;
}
ostream& operator<<(ostream& out,const Equipement& E)
{
    out<<"quantite: ";
    out<<E.quantite<<endl;
    out<<"reference: ";
    out<<E.rf<<endl;
    out<<"libelle: ";
    out<<E.libelle<<endl;
    stack<TimeDate*> temp = E.modeff;
   if(!temp.empty())
   {
     out<<"modification effectuee"<<endl;
     while(!temp.empty())
     {
         out<<*temp.top()<<endl;
         temp.pop();
     }
   }
    return out;
}


void Equipement::ajouterEq(CentreVT& C)
{
    char rep;
    do{
        Equipement *E=new Equipement();
        cin>>*E;
        C.equipements.push_back(E);
        C.enregistrerEquipement(E);
        cout<<"vous voulez ajouter un autre equipement(taper o pour oui)"<<endl;
        cin >> rep;
      } while(rep =='o' || rep == 'O');

}
void Equipement::suppEq(string rf,CentreVT& C)
{
    for(unsigned i=0;i<C.equipements.size();i++)
    {
        if(rf==C.equipements[i]->rf)
        {
            C.equipements.erase(C.equipements.begin()+i);
            cout<<"suppression terminee"<<endl;
            return;
        }
    }
   // C.reloadEquipement();
    cout<<"reference introuvable"<<endl;
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
            TimeDate* D= new TimeDate();
            *D=D->tempsCourant();
            C.equipements[i]->modeff.push(D);
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver==false)
        cout<<"equipement introuvable !"<<endl;
    else{
        cout<<"modification terminee"<<endl;
        //C.reloadEquipement();
    }
}

void Equipement::afficherEq(CentreVT& C)
{
    if(C.equipements.size()==0) cout<<"liste des equipements est vide"<<endl;
    else {
    cout<<"Vous avez "<<C.equipements.size()<<" equipements"<<endl;
    for(unsigned int i=0;i<C.equipements.size();i++){
            if(C.equipements[i]->rf !=""){
        cout<<"------ Equipement "<<i+1<<" ------- "<<endl;
        cout<<*C.equipements[i];}
    }
    }

}

Equipement::~Equipement()
{
while(!modeff.empty()){
    delete modeff.top();
}
}
