#include "Client.h"

Client::Client()
{
    //ctor
}
void Client::menuClient(CentreVT cvt){
    int cl,c;
        cout<<"\n********Espace Client*******\n"<<endl;
      /*  do{
        cout<<"1: S'authentifier "<<endl;
        cout<<"2: Creer un compte"<<endl;
    cout<<"Tapez votre choix "<<endl;
    cin>>c ;
        if(c == 1)
        try{
        authentifier(cvt);
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

}

void Client::effectuerRes(){
    Reservation r;
    try{
    cin>>r;
    }catch(exception const &e)
    {
            cerr<<"ERREUR: "<<e.what()<<endl;
    }
    this->listRes.push_back(r);
}
Client::~Client()
{
    //dtor
}
