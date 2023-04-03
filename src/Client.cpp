#include "Client.h"

Client::Client()
{
    //ctor
}
void Client::menuClient(CentreVT cvt){
    int cl,c;
        cout<<"\n********Espace Client*******\n"<<endl;
/*        do{
        cout<<"1: S'authentifier "<<endl;
        cout<<"2: Creer un compte"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>c ;
        if(c == 1)
        try{
        authentifier(cvt);
        //cin>>*this;
        break;
        }catch(MyExceptions e){}
    else
        if(c == 2)
            try{
         sinscrire(cvt);
         break ;
        }catch(exception const &e)
        {
            cerr<<"ERREUR: "<<e.what()<<endl;
        }
    }while(this);*/
cout << "Bienvenue Cher Client "<<getNomP()<<endl;
//recuperer();
//consulterRes();
//cout<<*this;
    //do{
    do{
    try
    {
        cout<<"_________________________"<<endl;
         cout << "1: Effectuer une reservation" <<endl;
         cout << "2: Annuler une reservation" <<endl;
         cout << "3: Consulter votre liste des reservations" <<endl;
         cout << "4: Se deconnecter" << endl;
         cout<<"_________________________"<<endl;
         cin>>cl;
        if(!cin) throw runtime_error("Vous devez entrer un entier");
                 switch(cl)
         {
             case 1 : effectuerRes();break;
             case 2 : supprimerRes();break;
             case 3 : consulterRes();break;
         }

    }catch(runtime_error& e)
    {
        cerr<<e.what()<<endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    }while(cl!=4);

}
void Client::sinscrire(CentreVT& c)
{
        cin>>*this;
        c.personnes.push_back(this);
        cout<<"compte creer avec succees"<<endl;
}

//******************** AFFICHER LES RESERVATIONS *************************** //

void Client::consulterRes(){
    int i;
    cout<<"la liste des reservations"<<endl;
    cout<<"vous avez au total "<<listRes.size()<< " reservation(s)"<<endl;
for(unsigned int i=0;i<listRes.size();i++)
{
    cout<<"------- RESERVATION NUM"<<i+1<<" -------"<<endl;
    cout<<listRes[i];
}

}

//******************** EFFECTUER UNE RESERVATION *************************** //

void Client::effectuerRes(){
    Reservation r ;
    try{
    do{
    cin>>r;
    }while(existDate(r.getDate(),r.getHeure()));

    }catch(exception const &e)
    {
            cerr<<"ERREUR: "<<e.what()<<endl;
    }
    listRes.push_back(r);
    //enregistrer(r);
}

//******************** SUPPRIMER UNE RESERVATION *************************** //

void Client::supprimerRes()
{
    int cd;
    if(listRes.size()==0) cout<<"vous n'avez pas des reservations"<<endl;
    else{
    cout<<"Entrer le code du reservation a supprimer"<<endl;
    cin>>cd;
    for(unsigned int i=0;i<listRes.size();i++)
    {
        if(listRes[i].getCodeR()==cd)
        {
            listRes.erase(listRes.begin()+i);
            cout<<"suppression effectuer avec sucees"<<endl;
            return;
        }

    }
    cout<<"code introuvable"<<endl;
    }
}


bool Client::existDate(Date d,int h)
{
    for(unsigned int i=0;i< listRes.size();i++)
        if((listRes[i].getDate() == d )&&(listRes[i].getHeure()==h))//TESTER DATE ET HEURE,
        {
          cout<<"date indisponible"<<endl;
          cout<<"on a une autre réservation la meme date a "<<listRes[i].getHeure()<<" H"<<endl;
          return true;
        }else
        {
          cout<<"date disponible Vous etes la bienvenue"<<endl;
          cout<<"votre réservation est le "<<d<<" a "<<h<<"H"<<endl;
          return false;
        }

}


//******************** FICHIER *************************** //
/*
void Client::enregistrer(Reservation r)
{
 ofstream Fichier("C:\\Users\\ADMIN\\Desktop\\Client.txt");
 if (!Fichier) cout<<"Erreur Fichier";
 for(unsigned int i=0;i< listRes.size();i++){
 Fichier<<&listRes[i];
 }
Fichier.close();
}

void Client::recuperer()
{
 ifstream Fichier("C:\\Users\\ADMIN\\Desktop\\Client.txt");
 if (!Fichier) cout<<"Le fichier n'existe pas il sera cree lors de l'enregistrement";
 Reservation r;
 //while(!Fichier.eof())
 //{
     try{
   Fichier>>&r;
//Fichier>>ws;
   r.getDate().affiche();
 listRes.push_back(r);
 }catch(exception const &e)
 {
     cerr<<"exceeption"<<e.what()<<endl;
 }

 //}
Fichier.close() ;
}
*/
//******************** SURCHARGE DES OPERATEURS *************************** //

ostream& operator<<(ostream& out, Client& c)
{
    out<<c;
     for(unsigned int i=0;i< c.listRes.size();i++)
        out<<c.listRes[i];

}
istream& operator>>(istream& in, Client& c)
{
    in>>c;
    for(unsigned int i=0;i< c.listRes.size();i++)
        in>>c.listRes[i];
}

Client::~Client()
{
    //dtor
}
