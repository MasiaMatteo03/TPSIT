#include <stdio.h>
#include <stdlib.h>

#define LUNG 100
#define DIM 16

                            //________________________IL PROGRAMMA NN STAMPA LE CANZONI________________________

typedef struct canzone{     //strutture canzone
    int numero;
    char nome[LUNG];
    char artista[LUNG];
}Canzone;

void randomSpotify(Canzone sp[], int d){    //genera canzoni casuali prese dal file
    int vett[d];
    int num;
    srand(time(NULL));

    for(int k = 0; k < d; k++){
        vett[k] = k; //assegna a vett[0] = 0, vett[1] = 1 ecc...
    }

    for(int j = 0; j < d; j++){
        do{
            num = rand() % d + 1;
        }while(num == vett[j]);        //controlla che il numero uscito nn sia nel vettore
        vett[j] = num;
        if(num == sp[j].numero){
            printf("%s, %s", sp[j].nome, sp[j].artista);   //stampo nome e artista della canzone
        }
    }
    return;
}

void caricaSpotify(FILE *f, Canzone s[], int *d){
    char lettera; //variabile in cui c'è la lettera letta
    char parola[LUNG]; //vettore di lettere
    int indice = 0; // indice che serve a capire cosa sto leggendo
    while(fscanf(f, "%c" , &lettera) != EOF){//legge lettera
        if(lettera == ','){//controlla se la lettera è = ','
            parola[strlen(parola)]='\0';//aggiunge alla fine della parola completa '\0'
            /*
            INDICE:
            0-> numero della canzone
            1-> titolo della canzone
            2-> autore della canzone
            */
            switch (indice){
                case 0:
                    s[*d].numero = (*d) + 1;
                    break;
                case 1:
                    strcpy(s[*d].nome, parola);
                break;
                case 2:
                    strcpy(s[*d].artista, parola);
                break;
            }
            indice = (indice + 1 ) %3;  //incremento indice
            memset(&parola[0], 0, sizeof(parola));  //azzera parola
            if(indice == 0) //controlla se ho finito di leggere la canzone
                *d = *d + 1;    //incremento contatore canzone
        }else{
            parola[strlen(parola)] = lettera;   //aggiunge alla fine della parola l'ultima lettera letta
        }
    }
    return;
}

int main(){
    Canzone spotify[DIM];
    FILE *fp;

    if((fp = fopen("canzoni.csv", "r")) == NULL){
        printf("Errore...Il file non esiste");
    }else{
        int cnt = 0;
        caricaSpotify(fp, spotify, &cnt);
        randomSpotify(spotify, DIM);
    }
}
