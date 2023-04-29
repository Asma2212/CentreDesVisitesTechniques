#include "Test.h"

Test::Test()
{
    //ctor
}
void Test::ajouterEtatTest(string nom,bool* e){
etatsTest.insert(pair<string,bool*>(nom, e));
}
void Test::modifierEtat(string nom){

}
void Test::supprimerEtat(string nom){
}
void Test::affichierEtats(){
    multimap<string, bool*>::iterator it;
    if(etatsTest.size()==0)
        cout<<"Vous n'avez pas encore fait la visite"<<endl;
    else{
    for (it = etatsTest.begin(); it != etatsTest.end(); ++it) {
        cout <<"\t etat "<<it->first <<" : "<<it->second<<endl;
    }
    }
}
bool Test::getEtatFinal(){
    bool etatFinal = true;
        multimap<string, bool*>::iterator it;
    cout << "\n Les etats de votre vehicule Apres la visite: \n";
    for (it = etatsTest.begin(); it != etatsTest.end(); ++it) {
        cout <<"\t etat "<<it->first <<" : "<<it->second<<endl;
        if(*it->second == false)
            etatFinal = false;
    }
    return etatFinal;


}
Test::~Test()
{
    //dtor
}
