#ifndef SERVER_MEMORYLIST_H
#define SERVER_MEMORYLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;

struct rmRef_h {

    int contador;
    int dato;
    int bytes;
    string key;

    struct rmRef_h *siguiente;
};

typedef struct rmRef_h* Tlista;

void insertar(Tlista &lista, int valor, string llave, int largo){

    Tlista t, q = new(struct rmRef_h);
    q->dato = valor;
    q->key = llave;
    q->bytes = largo;
    q->siguiente = NULL;

    if(lista==NULL){
        lista = q;
    }else{
        t = lista;
        while(t->siguiente!=NULL){
            t = t->siguiente;
        }
        t->siguiente = q;
    }

}

void buscarElemento(Tlista lista, int valor, string llave, int largo){
    Tlista q = lista;
    int i = 1, band = 0;
    int contador=0;

    while(q!=NULL){
        if(q->dato==valor && q->key==llave && q->bytes==largo){
            contador+=1;
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->siguiente;
        i++;
    }
    if(band==0)
        cout<<"\n\n No existe la llave solicitada"<< endl;
}

void reportarLista(Tlista lista){
    int i = 0;

    while(lista != NULL){
        cout <<' '<< i+1 <<") " << lista->key << endl;
        lista = lista->siguiente;
        i++;
    }
}


void eliminarElemento(Tlista &lista, int valor, string llave, int largo){
    Tlista p, ant;
    p = lista;

    if(lista!=NULL){
        while(p!=NULL){
            if(p->key==llave){
                if(p==lista)
                    lista = lista->siguiente;
                else
                    ant->siguiente = p->siguiente;

                delete(p);
                cout << "Elemento eliminado" << endl;
                return;
            }
            ant = p;
            p = p->siguiente;
        }
    }
    else
        cout<<" Lista vacia..!";
}

bool garbageCollector(Tlista &lista){
    Tlista p, ant;
    p = lista;

    if(lista!=NULL){
        do{
            if(p->contador<=0){
                if(p==lista){
                    lista = lista->siguiente;
                }else{
                    ant->siguiente = p->siguiente;
                }

                delete(p);
                return true;
            }
            ant = p;
            p = p->siguiente;
        }while(p!=NULL);
    }
    else{
        false;}
}

#endif //SERVER_MEMORYLIST_H
