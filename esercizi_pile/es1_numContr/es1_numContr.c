/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct numeri{
    int valore;
    struct numeri* next;
}Numeri;

int is_empty(Numeri* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Numeri **head, Numeri *el){
    
    while((cifre / divid) != 0){
        if(is_empty(*head)){
            *head = el;
            el->next = NULL;
        }else{
            el->next = *head;
            *head = el;
        }
    }
}

Numeri* pop(Numeri **head){
    Numeri* ret = *head;

    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void stampa(Numeri **head){
    Numeri *temp;
    temp = pop(*head);

    while(temp != NULL){
        printf("%d", temp->valore);
        free(temp);
        temp = pop(*head);
    }
}

int main(){
    int cifre;
    int divid = 10;
    int element;
    Numeri* num;

    printf("Inserisci i numeri:\n");
    scanf("%d", &cifre);
    
    while((cifre / divid) != 0){
        element = cifre & divid;
        divid = divid * 10;
        push(&num, element;
    }

        stampa(&num);
}