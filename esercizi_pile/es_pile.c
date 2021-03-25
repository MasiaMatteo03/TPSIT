#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valore;
    struct nodo* next;
}Nodo;

int is_empty(Nodo* head){
    
    if (head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Nodo **head, Nodo *element){

    if (is_empty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){

    Nodo* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}