#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct carte{
    int valore;
    char seme;
    struct carte *next;
};

struct bob{
    struct carte carta;
    struct bob* next;
};

struct alice{
    struct carte carta;
    struct alice* next;
};

bool is_empty(struct carte *punt){
    return punt==NULL;
}

//----------------------------------------------------------------------------------------------------------------
void push(struct carte **head, struct carte *element){

    if (is_empty(*head)){           //if (is_empty(*head) == NULL)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct carte* pop(struct carte **head){

    struct carte* ret = *head;
    if (is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void main(){
    struct carte* pila = NULL;
    struct carte* element = NULL;

    int cont;
    int contMazzo = 0;
    int turno = 0;

    for (cont = 0; cont < 13; cont++){            //for per carte con seme Cuori
        element = (struct carte*)malloc(sizeof(struct carte));
        element->valore = cont;
        push(&pila, element);

        element->seme = 'C';
    }

    for (cont = 0; cont < 13; cont++){            //for per carte con seme Picche
        element = (struct carte*)malloc(sizeof(struct carte));
        element->valore = cont;
        push(&pila, element);

        element->seme = 'P';
    }

    for (cont = 0; cont < 13; cont++){            //for per carte con seme Denari
        element = (struct carte*)malloc(sizeof(struct carte));
        element->valore = cont;
        push(&pila, element);

        element->seme = 'D';
    }

    for (cont = 0; cont < 13; cont++){            //for per carte con seme Fiori
        element = (struct carte*)malloc(sizeof(struct carte));
        element->valore = cont;
        push(&pila, element);

        element->seme = 'F';
    }

    while (contMazzo != 52){
        turno = rand() % 2 + 1;

        switch (turno){
        case 1:
            element = pop(&pila);       //turno prima bob
            push(&bob, element->valore);
            push(&bob, element->seme);

            element = pop(&pila);
            push(&alice, element->valore);
            push(&alice, element->seme);
            break;
        
        case 2:
            element = pop(&pila);       //turno prima alice
            push(&alice, element->valore);
            push(&alice, element->seme);

            element = pop(&pila);
            push(&bob, element->valore);
            push(&bob, element->seme);
            break;
        default:
            break;
        }

        contMazzo = contMazzo + 2;
    }

    while(!is_empty(alice)){
        element = pop(&alice);
        printf("%d", element->valore);
        printf("%c", element->seme);
        free(element);
    }
}