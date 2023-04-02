#include "Client.h"

Client::Client()
{
    //ctor
}
void Client::menuClient(CentreVT cvt){
    int cl,c;
    Reservation r;
        cout<<"\n********Espace Client*******\n"<<endl;
  /*      do{
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
         do{
        cout<<"_________________________"<<endl;
         cout << "1: effectuer une reservation" <<endl;
         cout << "2: consulter votre liste des reservations" <<endl;
         cout << "3: sortir" << endl;
         cout<<"_________________________"<<endl;
         cin>>cl;
         switch(cl)
         {
             case 1 : effectuerRes();break;
             case 2 : consulterRes();break;
         }
         }while(cl!=3);
}
void Client::sinscrire(CentreVT& c)
{
        cin>>*this;
        c.personnes.push_back(this);
        cout<<"compte creer avec succees"<<endl;
}

void Client::consulterRes(){
    int i;
    Reservation r;
    cout<<"la liste des reservations"<<endl;
for(unsigned int i=0;i<listRes.size();i++)
    cout<<listRes[i];
}

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
bool Client::existDate(Date d,int h)
{
    for(unsigned int i=0;i< listRes.size();i++)
        if((listRes[i].getDate().jour == d.jour )&&(listRes[i].getHeure()==h))//TESTER DATE ET HEURE,
        {
          cout<<"date indisponible"<<endl;
          cout<<"on a une autre réservation la meme date a "<<listRes[i].getHeure()<<endl;
          return true;
        }else
        {
          cout<<"date disponible Vous etes la bienvenue"<<endl;
          cout<<"votre réservation est le "<<d<<" a "<<h<<"H"<<endl;
          return false;
        }

}

void Client::enregistrer(Reservation r)
{
 ofstream Fichier("C:\\Users\\ADMIN\\Desktop\\Client.txt");
 if (!Fichier) cout<<"Erreur Fichier";
 for(unsigned int i=0;i< listRes.size();i++){
 Fichier <<&listRes[i];

 }
Fichier.close() ;
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
