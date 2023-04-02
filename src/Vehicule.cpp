#include "Vehicule.h"

Vehicule::Vehicule(string matricule,string marque ,int age ,TypeConsommation typeCons ,int nbRoues,bool etatFeux,bool etatFrein,bool etatCarosserie,bool etatDirection)
{
    this->matricule=matricule;
    this->marque=marque ;
    this->age=age ;
    this->typeCons=typeCons ;
    this->nbRoues=nbRoues ;
    this->tarif=10.0;
}
void Vehicule::saisie(){
cin>>*this ;
}
void Vehicule::affiche(){
cout<<*this;
}
ostream& operator<<(ostream& out, Vehicule& v)
{
    cout<<"matricule: ";
    out<<v.matricule<<endl;
    cout<<"marque: ";
    out<<v.marque<<endl;
    cout<<"age: ";
    out<<v.age<<endl;
    cout<<"Type de consommation : ";
    switch(v.typeCons){
    case Diesel : out<<"Diesel"<<endl;break;
    case Electrique : out<<"Electrique"<<endl;break;
    case Essence : out<<"Essence"<<endl;break;
    case Hybride : out<<"Hybride"<<endl;break;
    }
    cout<<"Tarif: ";
    out<<v.tarif<<endl;
    //cout<<"nombre de roues: ";
    //out<<v.nbRoues<<endl;
}
istream& operator>>(istream& in, Vehicule& v)
{
    int t;
    cout<<"entrer votre matricule"<<endl;
    in>>v.matricule;
    cout<<"entrer votre marque"<<endl;
    in>>v.marque;
    cout<<"entrer l'age du vehicule"<<endl;
    in>>v.age;
    //cout<<"entrer le nombre des roues"<<endl;
    //in>>v.nbRoues;
    cout<<"entrer le type de consommation"<<endl;
    do{
        cout<<"\t 1 : Diesel "<<endl;
        cout<<"\t 2 : Electrique "<<endl;
        cout<<"\t 3 : Essence "<<endl;
        cout<<"\t 4 : Hybride "<<endl;
        cin>>t;
        switch(t)
        {
            case 1 : v.typeCons=Diesel;break;
            case 2 : v.typeCons=Electrique;break;
            case 3 : v.typeCons=Essence;break;
            case 4 : v.typeCons=Hybride;break;
        }
    }while(t <0 || t>4);
    return in;
}
ostream& operator<<(ostream& out, Vehicule* v)
{
    cout<<"veh out elli bl *"<<endl;
    out<<v->matricule;
    out<<v->marque;
    out<<v->age;
    out<<v->nbRoues;
    //in>>v->typeCons;

    return out;
}
istream& operator>>(istream& in, Vehicule* v)
{
    string msg;
//    Vehicule v = new Vehicule();
    //cout<<"veh elli bl *"<<endl;
    //in.getline(v->matricule, 100, '\n');
    in>>v->matricule;
    cout<<"mat"<<v->matricule;
    in>>v->marque;
    cout<<"marque"<<v->marque;
    in>>v->age;
    cout<<"age"<<v->age;
   // in>>Diesel;
   // v->typeCons=Diesel;
  // getline(in,msg,'\n');
 //  cout<<"hhhhhh"<<msg;
//    in>>v->typeCons;
    in>>v->nbRoues;
    cout<<"nbRoures"<<v->nbRoues;


    return in;
}

Vehicule::~Vehicule()
{
    //dtor
}
