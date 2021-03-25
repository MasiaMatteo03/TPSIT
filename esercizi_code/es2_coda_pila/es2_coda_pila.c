#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue_node{
    int valore;
    struct queue_node *next;
};

bool is_empty(struct queue_node *punt){
    return punt==NULL;
}

//----------------------------------------------------------------------------------------------------------------
void push(struct queue_node **head, struct queue_node *element){

    if (is_empty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct queue_node* pop(struct queue_node **head){

    struct queue_node* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void enqueue(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    if(is_empty(*head)){
        *head=element;

    }else{
        (*tail)->next=element;
    }

    *tail=element;
    element->next=NULL;
}

struct queue_node * dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    if(*head == NULL){
        *tail = NULL;
    }

    return ret;
}

void caricaCoda(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    char choice;

    do{
        element = (struct queue_node*) malloc (sizeof(struct queue_node));

        printf("Inserisci un numero..."); 
        fflush(stdin);  
        scanf("%d", &element->valore);
        enqueue(head, tail, element);

        printf("Ne vuoi inserire ancora? s,S (si) n,N (no)");
        fflush(stdin); 
        scanf("%c", &choice);
    }while (choice == 's' || choice == 'S');
}

void main(){
    
    struct queue_node *head = NULL;
    struct queue_node *tail = NULL;
    struct queue_node *element = NULL;
    
    struct queue_node *pila = NULL;

    caricaCoda(&head, &tail, element);

    while(!is_empty(head)){
        element = dequeue(&head, &tail);
        push(&pila, element);
    }
    
    while(!is_empty(pila)){
        element = pop(&pila);
        printf("%d ", element->valore);
        free(element);
    }   
}