#include "Admin.h"

Admin::Admin()
{
    //ctor
}

void Admin::consulterVisite(CentreVT& cvt){
cout<<"la liste des Visites Techniques :"<<endl;
cout<<"vous avez au total "<<cvt.visites.size()<< " visites(s)"<<endl;
for(unsigned int i=0;i<cvt.visites.size();i++)
{
    cout<<"------- Visite NUM"<<i+1<<" -------"<<endl;
    cout<<*cvt.visites[i];
}

}

void Admin::affecterAgentsVisites(CentreVT& cvt){
int nb,j=0;;
nb=nombreAgents(cvt);
if(nb==0)
    cout<<"vous devez avoir au minimum un agent"<<endl;
else{
for(unsigned int i=0;i<cvt.personnes.size();i++)
    if(typeid(*cvt.personnes[i])==typeid(Agent))
        {
            Agent* ag;
           ag=new Agent(static_cast<Agent&>(*cvt.personnes[i]));
            while(ag->getNbVisites()<(cvt.visites.size()/nb)){
                 ag->ajouterVisite(cvt.visites[j]);
                 j++;
                 cvt.personnes[i]=ag;
            }

        }
}
}
//error: invalid use of incomplete type 'class Agent'|
int Admin::nombreAgents(CentreVT& cvt){
int n=0;
for(unsigned int i=0;i<cvt.personnes.size();i++)
    if(typeid(*cvt.personnes[i])==typeid(Agent))
            n++;
return n;
}

void Admin::ajouterAgent(CentreVT& cvt){
char rep;
    do{
        Agent *A=new Agent();
        cin>>*A;
        cvt.personnes.push_back(A);
        cout<<"vous voulez ajouter un autre un agent(o/n)"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}

void Admin::afficherAgents(CentreVT& cvt){
for(unsigned int i=0;i<cvt.personnes.size();i++)
{
    //cout<<new Agent(static_cast<Agent&>(*personnes[i]));
    if(typeid(*cvt.personnes[i])==typeid(Agent))
    {
         Agent* ag=new Agent(static_cast<Agent&>(*cvt.personnes[i]));
        cout<<*ag;
    }

}
}

/*void Admin::ajouterAdmin(CentreVT& cvt){
char rep;
    do{
        Admin *A=new Admin();
        cin>>*A;
        cvt.personnes.push_back(A);
        cout<<"vous voulez ajouter un autre un admin(o/n)"<<endl;
        cin >> rep;
      } while(rep=='o' || rep == 'O');

}*/

Admin::~Admin()
{
    //dtor
}
