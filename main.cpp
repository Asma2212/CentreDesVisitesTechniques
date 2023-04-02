#include <iostream>
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include"Date.h"
#include"Equipement.h"
#include"Personne.h"
#include"Agent.h"
#include"Client.h"
#include"exception"
using namespace std;

int main()
{
    int esp,cnClient,cl;
    Client clt;
    Agent ag;

    CentreVT C,C1;
    fstream f;
    Equipement E;
    E.ajouterEq(C);
    CentreVT::creer(f);
    f<<&C;
    f.seekg(0);
    f>>&C1;
    cout<<C1;
    f.close();

           /* do{
        cout<<"_________________________"<<endl;
        cout<<"1: Espace Client "<<endl;
        cout<<"2: Espace Agent"<<endl;
        cout<<"3: Espace Admin"<<endl;
        cout<<"_________________________"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>esp ;
    }while(esp>4 && esp<0);
    // ******** ESPACE CLIENT ***********
    if(esp == 1){

         clt.menuClient(c);

    }
    // ******** ESPACE ADMIN ***********
    else
        if(esp==2){

    }
    else*/

    return 0;
}
