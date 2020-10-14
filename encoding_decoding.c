#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 100

/*
Author: Moldoveanu Davide
Date: 15-09-2020
Text:encoding e decoding
ES:
*/

void encoding(char f[]){
    int cnt=1;  //parto da 1 perché se no la salto
    printf("Inserisci una frase per poi fare il encoding: ");
    scanf("%s",f);      //inserisco la frase
    for(int k=0;k<strlen(f);k++){       //ciclo il for finchè non finiscono i caratteri inseriti da me
        if(f[k]==f[k+1]){       //controllo se ci sono più di un carattere uguale
            cnt++;              //incremento quanti caratteri uguali adiacenti ci sono
        }else{
            if(cnt!=1){         //se è diverso da 1 stampo il numero di volte che c'è quel carattere, se no stampo il carattere singolo
                printf("%d%c",cnt,f[k]);
                cnt=1;
            }else{
                printf("%c",f[k]);
                cnt=1;
            }
        }
    }
}

void decoding(char f[]){
    printf("Inserisci una frase per poi fare il decoding: ");
    scanf("%s",f);      //inserisco la frase
    int car=0;          //uso una variabile d'appoggio per stampare n volte il carattere, nella variabile inserirò il numero già convertito dall'ascii
    for(int k=0;k<strlen(f);k++){   //ciclo il for finchè non finiscono i caratteri inseriti da me
        if(f[k]>49 & f[k]<58){      //veerifico che sia un numero
            car=f[k]-48;            //transformo il numero letto in ascci in un numero uguale ma non in ascii
            for(int j=1;j<car;j++){     //stampo il carattere n volte di quante volte indica il numero
                printf("%c",f[k+1]);
            }
        }else{
            printf("%c",f[k]);      //stampo solo una volta se non è un numero
        }
    }
}

void main () {

    char frase[LUNG];
    int op=0;

    printf("1 encoding\n2 decoding\n");     //chiedo se voglio fare il decoding o il encoding
    scanf("%d",&op);
    if(op==1){
        encoding(frase);    //funzione encoding
    }else{
        decoding(frase);    //funzione decoding
    }


	printf("\nPremi INVIO per uscire.");
	getch();
}
