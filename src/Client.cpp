#include "Client.h"

Client::Client()
{
    //ctor
}


void Client::menuClient(CentreVT* cvt){
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
recuperer(cvt);
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
             case 1 : effectuerRes(cvt);break;
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
void Client::authentifier(CentreVT& C)
{
    string email,mdp;
    char choix;
    bool emailCorr= false;
    bool auth=false;
    while(!auth)
    {
        cout<<"entrez votre email"<<endl;
        cin>>email;
        cout<<"entrez votre mot de passe "<<endl;
        cin>>mdp;
        for(unsigned i=0;i<C.personnes.size();i++)
        {
            emailCorr=true;
            if(email.compare(C.personnes[i]->getEmail())==0)
            {
                if(mdp.compare(C.personnes[i]->getmdp())==0)
                {
                    cout<<"vous etes connecte avec succes "<<endl;
                    auth=true;
                    break;
                }
                else
                {
                    cout<<"mot de passe incorrect !"<<endl;
                    break;
                }
            }
        }
        if(!emailCorr){
            cout<<"email introuvable !"<<endl;
            cout<<"Taper 'r' pour retourner et 'c' pour continuer"<<endl;
            cin>>choix;
            if((choix == 'r' )|| (choix == 'R'))
                throw MyExceptions("erreur d'authentification");
        }

    }
}
void Client::modifierD(CentreVT& C)
{
    int i=0;
    bool trouver=false;
    cout<<"entrez le cin de la personne a modifier "<<endl;
    cin>>this->cn;
    while(i<C.personnes.size()) //modifier la condition de while.
    {
        if(this->cn==C.personnes[i]->getcn())
        {
            cin>>*C.personnes[i];
            trouver=true;
            break;
        }
        i+=1;
    }
    if(trouver=false)
        cout<<"personne non trouve !"<<endl;

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

void Client::effectuerRes(CentreVT* cvt){
    Reservation* r=new Reservation();
    VisiteTech* v;
    try{
    do{
    cin>>*r;
    }while(existDate(r->getDate(),r->getHeure()));

    }catch(exception const &e)
    {
            cerr<<"ERREUR: "<<e.what()<<endl;
    }
    v=cvt->ajouterVisite(r);
    MapVisites.ajouterElement(r->getCodeR(),*v);
    listRes.push_back(*r);
    enregistrer(*r);
}

//******************** SUPPRIMER UNE RESERVATION *************************** //

void Client::supprimerRes()
{
    int cd;
    if(listRes.size()==0) cout<<"vous n'avez pas des reservations"<<endl;
    else{
    cout<<"Entrer le code du reservation a supprimer"<<endl;
    cin>>cd;
    for(int i=0;i<listRes.size();i++)
    {
        if(listRes[i].getCodeR()==cd)
        {
            listRes.erase(listRes.begin()+i);
            reload();
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

void Client::creer(fstream &f)
{
 f.open("C:\\Users\\ADMIN\\Desktop\\Client.txt",ios::in | ios::out | ios::trunc);
 if (!f) cout<<"Erreur Fichier";
}


void Client::enregistrer(Reservation r)
{
 ofstream Fichier("C:\\Users\\ADMIN\\Desktop\\Client.txt",ios::app);
 if (!Fichier) cout<<"Erreur Fichier";
 Fichier<<&r;
Fichier.close();
}

void Client::recuperer(CentreVT* cvt)
{
 ifstream Fichier("C:\\Users\\ADMIN\\Desktop\\Client.txt",ios::app);
 if (!Fichier) cout<<"Le fichier n'existe pas ";

 while(1)
 {
 Reservation* r=new Reservation();
   Fichier>>r;
   if(Fichier.eof()) break;
//Fichier>>ws;
//r.getDate().affiche();
cvt->ajouterVisite(r);
 listRes.push_back(*r);
}
cvt->consulterVisite();
Fichier.close() ;
}
void Client::reload()
{
fstream f;
 creer(f);
 f.clear();

for(unsigned int i=0;i<listRes.size();i++)
 {
   f<<&listRes[i];
}
f.close() ;
}

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
template<class K, class V>
void ElementsMap<K, V>::ajouterElement(const K& cle, const V& valeur) {
    elements.insert(make_pair(cle, valeur));
}
Client::~Client()
{
    //dtor
}
