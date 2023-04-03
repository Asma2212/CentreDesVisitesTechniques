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
    int esp,cnClient,cl,ad;
    Client clt;
    Agent ag;
    Equipement e;
    CentreVT c,C1;
    string rf;
/*
    fstream f;
    Equipement E;
    E.ajouterEq(C);
    CentreVT::creer(f);
    f<<&C;
    f.seekg(0);
    f>>&C1;
    cout<<C1;
    f.close();*/

            do{
        cout<<"_________________________"<<endl;
        cout<<"1: Espace Client "<<endl;
        cout<<"2: Espace Agent"<<endl;
        cout<<"3: Espace Admin"<<endl;
        cout<<"_________________________"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>esp ;
    // ******** ESPACE CLIENT ***********
    if(esp == 1){

         clt.menuClient(c);
         esp=0;

    }
    // ******** ESPACE ADMIN ***********
    else
        if(esp==2){

               do{
             try
            {
        cout<<"_________________________"<<endl;
         cout << "1: rechercher un equipement" <<endl;
         cout <<"2: Consulter la liste des equipements" <<endl;
         cout << "3: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>ad;
         if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(ad)
         {
             case 1:
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 ag.rechEq(rf,c);break;
             case 2 : ag.ConsulterEq(c) ;break;
         }
         }catch(runtime_error& e)
        {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while(ad!=3);
    esp=0;

    }
    else{
            do{
             try
            {
        cout<<"_________________________"<<endl;
         cout << "1: Ajouter un equipement" <<endl;
         cout << "2: modifier un equipement" <<endl;
         cout <<"3: supprimer un equipement"<<endl;
         cout <<"4: Consulter la liste des equipements" <<endl;
         cout << "5: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>ad;
         if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(ad)
         {
             case 1 : e.ajouterEq(c);break;
             case 2 :
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 e.modifierEq(rf,c);break;
             case 3 :
                 cout<<"entrer la reference de l'equipement a modifier"<<endl;
                 cin>>rf;
                 e.suppEq(rf,c);break;
             case 4 : e.afficherEq(c) ;break;
         }
         }catch(runtime_error& e)
        {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while(ad!=5);
    esp=0;
    }

    }while(esp>4 || esp<1);
    return 0;
}
