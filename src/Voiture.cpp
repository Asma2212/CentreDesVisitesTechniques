#include "Voiture.h"

Voiture::Voiture()
{
    tarif=20.0;
    nbRoues=4;
}

Voiture::Voiture(const Voiture& vt) : Vehicule(vt){
stack<int*> tempStack = vt.visiteEff;
while(!tempStack.empty()){
    this->visiteEff.push(tempStack.top());
    tempStack.pop();
        }
}

Voiture& Voiture::operator=(const Voiture& vt){
stack<int*> tempStack = vt.visiteEff;
if (this != &vt) {
Vehicule::operator=(vt);
while(!visiteEff.empty()){
    delete visiteEff.top();
}
//this->visiteEff1.clean();
while(!tempStack.empty()){
    this->visiteEff.push(tempStack.top());
    tempStack.pop();
}
}
        return *this;
}

void Voiture::affiche(){
    Vehicule::affiche();
      if(!this->visiteEff.empty())
   {
     cout<<"visite effectuee"<<endl;
     while(!this->visiteEff.empty())
     {
         cout<<this->visiteEff.top()<<endl;
         this->visiteEff.pop();
     }
   }
}
void Voiture::saisie(){
   Vehicule::saisie();
}

istream& operator>>(istream& in, Voiture& v)
{
in>>v;
}
ostream& operator<<(ostream& out, Voiture& v)
{
    Vehicule *Veh=&v;
    out<<*Veh;
    if(!v.visiteEff.empty())
   {
     out<<"visite effectuee"<<endl;
     while(!v.visiteEff.empty())
     {
         out<<v.visiteEff.top()<<endl;
         v.visiteEff.pop();
     }
   }
}
stack<int*> Voiture::getVE()
{
    stack<int*> L;
    for(unsigned i=0;this->visiteEff.size();i++)
       {
           L.push(this->visiteEff.top());
           this->visiteEff.pop();
       }
    return L;
}
Voiture::~Voiture()
{
while(!visiteEff.empty()){
    delete visiteEff.top();
}
}
