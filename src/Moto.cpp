#include "Moto.h"

Moto::Moto()
{
    tarif=10.0;
    nbRoues=2;
}

Moto::Moto(const Moto& mt) : Vehicule(mt){
stack<int*> tempStack = mt.visiteEff2;
while(!tempStack.empty()){
    this->visiteEff2.push(tempStack.top());
    tempStack.pop();
        }
}

Moto& Moto::operator=(const Moto& mt){
stack<int*> tempStack = mt.visiteEff2;
if (this != &mt) {
Vehicule::operator=(mt);
while(!visiteEff2.empty()){
    delete visiteEff2.top();
}
//this->visiteEff1.clean();
while(!tempStack.empty()){
    this->visiteEff2.push(tempStack.top());
    tempStack.pop();
}
}
        return *this;
}

void Moto::affiche(){
    Vehicule::affiche();
    if(!this->visiteEff2.empty())
   {
     cout<<"visite effectuee"<<endl;
     while(!this->visiteEff2.empty())
     {
         cout<<this->visiteEff2.top()<<endl;
         this->visiteEff2.pop();
     }
   }
}
istream& operator>>(istream& in, Moto& m)
{
in>>m;
}
stack<int*> Moto::getVE2()
{
    stack<int*> L;
    for(unsigned i=0;this->visiteEff2.size();i++)
       {
           L.push(this->visiteEff2.top());
           this->visiteEff2.pop();
       }
    return L;
}
void Moto::saisie(){
   Vehicule::saisie();
}
Moto::~Moto()
{
while(!visiteEff2.empty()){
    delete visiteEff2.top();
}
}
