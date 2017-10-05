#ifndef SERVER_MEMORYLIST_H
#define SERVER_MEMORYLIST_H

#include <iostream>
#include <stdlib.h>
using namespace std;

/*Se inician los atributos para la lista*/
struct rmRef_h {

    int contador;
    int dato;
    int bytes;
    string key;
    struct rmRef_h *siguiente;
};

/*Se crean los metodos de la lista*/
typedef struct rmRef_h* Tlista;

/*Función que inserta elementos en la lista*/
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

/*Función que busca elementos en la lista*/
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

/*Función que muestra la lista*/
void reportarLista(Tlista lista){
    int i = 0;

    while(lista != NULL){
        cout <<' '<< i+1 <<") " << lista->key << endl;
        lista = lista->siguiente;
        i++;
    }
}

/*Función que elimina elementos en la lista*/
void eliminarElemento(Tlista &lista, int valor, string llave, int largo){
    Tlista p, ant;
    p = lista;

    if(lista!=NULL){
        while(p!=NULL){
            if(p->key==llave && p->dato==valor && p->bytes==largo){
                cout<<"El elemento existe"<<endl;
                if(p==lista)
                    lista = lista->siguiente;
                else
                    ant->siguiente = p->siguiente;

                delete(p);
                cout << "Elemento eliminado" << endl;
                return;
            }
            cout<<"El elemento no existe"<<endl;
            ant = p;
            p = p->siguiente;
        }
    }
    else
        cout<<" Lista vacia..!";
}

/*Función de recolector de basura*/
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
                cout<<"Elemento eliminado por Garbage Collector"<<endl;
                return true;
            }
            ant = p;
            p = p->siguiente;
        }while(p!=NULL);
    }
    else{
        false;}
}

void ordenarLista(Tlista lista){
    Tlista actual , siguiente;
    int contadorAux;
    int datoAux;
    int bytesAux;
    string keyAux;

    actual = lista;
    while(actual->siguiente != NULL){
     siguiente = actual->siguiente;

     while (siguiente != NULL){
         if (actual->dato > siguiente->dato){
             contadorAux = siguiente->contador;
             datoAux = siguiente->dato;
             bytesAux = siguiente->bytes;
             keyAux = siguiente->key;

             siguiente->dato = actual->dato;
             siguiente->key = actual->key;
             siguiente->bytes = actual->bytes;
             siguiente->contador = actual->contador;

             actual->dato = datoAux;
             actual->contador = contadorAux;
             actual->bytes = bytesAux;
             actual->key = keyAux;
         }
         siguiente = siguiente->siguiente;
     }
     actual = actual->siguiente;
    }
    cout<<"\n\n\tLista ordenada..."<<endl;
}

void intercambio(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                intercambio(&arr[j], &arr[j+1]);
}


#endif //SERVER_MEMORYLIST_H
