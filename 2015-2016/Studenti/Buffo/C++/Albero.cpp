#include <iostream>
#include <stdlib.h>
using namespace std;

struct albero {

    string nodo;
    albero *sx;
    albero *dx;

};

class tree {
    albero *nodo;

public:
    tree() {
        nodo=NULL;
    }

    albero *sx(albero *p) {
        if(!p) return NULL;
        else return p->sx;
    }

    albero *dx(albero *p) {
        if(!p) return NULL;
        else return p->dx;
    }

    albero* setNodo(albero *p, bool b) {
        if(!p) {
            p=new(albero);
            cout<<"Nome nodo:";
            cin>>p->nodo;
            p->sx=NULL;
            p->dx=NULL;
            nodo=p;
            return p;
        } else {
            if(b) {
                p->dx=setNodo(dx(p),b);
                nodo=p;
                return p;
            } else {
                p->sx=setNodo(sx(p),b);
                nodo=p;
                return p;
            }

        }

    }



    albero *get_nodo() {
        return nodo;
    }

    void stampa(albero *p) {

        if(p!=NULL) {
            cout<<p->nodo<<" "<<endl;
            if(p->sx!=NULL){
                   
                    stampa(p->sx);
                    
            }
            if(p->dx!=NULL){
                    
                    stampa(p->dx);
                    
            }

        }

    }


};

int main() {
    tree t1;
    int scelta;
    bool b;
    do {
        cout<<"1. Aggiungi nodo"<<
        endl<<"2. Stampa albero"<<
        endl<<"0. Termina programma"<<
        endl<<":> ";
        cin>>scelta;

        switch(scelta) {
        case 1:
            if(t1.get_nodo()!=NULL) {
                cout<<"0. Sx"<<"   1. Dx"<<
                endl<<":> ";
                cin>>b;
            }
            t1.setNodo(t1.get_nodo(),b);
            cout<<" ---------------- "<<endl<<endl;
            break;
        case 2:

            system("cls");
            t1.stampa(t1.get_nodo());
            cout<<endl;
            break;
        default:
            break;
        }
    } while(scelta!=0);

    return 0;
}
