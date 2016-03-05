#include <iostream>
using namespace std;

struct tree{
int n;
tree*s;
tree*d;
};

class albero{
private:
    tree*radice;
public:
   albero(){
   radice=NULL;  //radice inizializzata a NULL
   }

   tree*push(char c,tree *p){ //per far ritornare il puntatore // ricorsività
        if(p==NULL){           // controlla se il nodo è vuoto o meno
            p=new(tree);        // se sì, assegna uno spazio in memoria e lo alloca
            cout<<"Numero:";
            cin>>p->n;
            p->s=NULL;                  // inserimento radice
            p->d=NULL;
            radice=p;
          return p;
        }
        else{                       //se la radice è diversa da NULL, si procede all'inserimento dei sottoalberi //rami
            if(c=='d'){
                p->d=push(c,p->d);
                radice=p;
                return p;
            }
            if(c=='s'){                                                     //else main <--
                p->s=push(c,p->s);
                radice=p;
                return p;
            }


        }

    }


    tree*rr(){
    return radice;
    }
};

int main(){
albero a;
int scelta;
char c;
do{
    cout<<endl<<"1. Inserisci"<<endl<<"0. Esci\n";
    cin>>scelta;


    switch(scelta){
case 1:
    if(a.rr()!=NULL){ //mi avverte che ho già completato l'inserimento della radice e mi permette di inserire i sottoalberi
    cout<<"d. Inserisci nel sottoalbero destro"<<" "<<"s. Inserisci nel sottoalbero sinistro\n";
    cin>>c;
    if(c!='d'&& c!='s'){
        cout<<"Codice inserito non valido. Inserire 'd' per inserire nel sottoalbero destro o 's' per inserire nel sottoalbero sinistro\n";
        break;
    }
    }
    a.push(c,a.rr());   //inserimento radice -> ricorsività e inserimento a destra o a sinistra
    break;
    }
    }
    while(scelta!=0);

    return 0;


}







