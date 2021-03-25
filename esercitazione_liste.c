#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct El{
    int valore;
    struct El* next;
};

void stampaLista(struct El* l){
    while (l!=NULL){
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; //ad l viengono assegnati i valori di next per stamparli successivamente
    }
    return;
}

struct EL push(struct El* lista, int n){
    struct El* l1; 
    if (n>=0){
        if (lista==NULL){ //controllo se la lista è vuota
            lista = (struct El*) malloc(sizeof(struct El));//se la stringa è vuota faccio la malloc per un elemento a lista e copio la lista in l
            l1 = lista;
        }else{  //se la lista nn è vuota faccio la malloc per il next di l e lo copio in l
            l1->next = (struct El*) malloc(sizeof(struct El));
            l1 = l->next;
        }
        l1->valore = n; //il numero inserito viene memorizzato in valore di l
        l1->next = NULL; //metto il next di l tutto a NULL
    }
    return l1;
}

int main(){
    int n;
    struct El* lista;
    struct El* l; 
    
    lista=NULL; //setta l'intera lista a NULL

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        l = push(lista, n);
    }while (n>=0);
    

    l=lista; //copio la lista in l
    printf("numeri inseriti: ");

    stampaLista(l);
    
    printf("\n");
    return 0;
}