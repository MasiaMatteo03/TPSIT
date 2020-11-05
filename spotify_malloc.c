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

void caricaSpotify(FILE *f, Canzone s[]){
    char lettera; //variabile in cui c'è la lettera letta
    char *parola; //vettore di lettere
    parola = (char*) malloc(LUNG * sizeof(char));
    int indice = 0; // indice che serve a capire cosa sto leggendo
    int k = 0; //contatore canzoni
    int kPar = 0;
    while(fscanf(f, "%c" , &lettera) != EOF){//legge lettera
        if(lettera == ','){//controlla se la lettera è = ','
            *(parola + kPar)='\0';//aggiunge alla fine della parola completa '\0'
            /*
            INDICE:
            0-> numero della canzone
            1-> titolo della canzone
            2-> autore della canzone
            */
            switch (indice){
                case 0:
                    (s + k)->numero = k + 1;
                    break;
                case 1:
                    strcpy((s + k)->nome, parola);
                break;
                case 2:
                    strcpy((s + k)->artista, parola);
                break;
            }
            kPar = 0;
           free(parola);  //azzera parola
           parola = (char*) malloc(LUNG * sizeof(char));
            if(indice == 0) //controlla se ho finito di leggere la canzone
                k++;    //incremento contatore canzone
        }else{
            *(parola + kPar) = lettera;   //aggiunge alla fine della parola l'ultima lettera letta
            kPar++;
        }
    }
    return;
}

int main(){
    Canzone *spotify;
    spotify = (Canzone*) malloc(DIM * sizeof(Canzone));
    FILE *fp;

    if((fp = fopen("canzoni.csv", "r")) == NULL){
        printf("Errore...Il file non esiste");
    }else{
        int cnt = 0;
        caricaSpotify(fp, spotify);
        randomSpotify(spotify, DIM);
    }
}
