#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG_STAT 5
#define LUNG 100

typedef struct data{
    int anno;
    int mese;
    int giorno;
    int ore;
    int min;
    int sec;
}Data;


typedef struct covid{
    Data date;       //data
    char stato[LUNG_STAT];    //stato
    int codReg;         //codice regione
    char nReg[LUNG];    //nome regione
    float lat;          //latitudine
    float longit;         //longitudine
    int nRicSint;       //numero ricoverati con sintomi
    int terapInt;       //numero terapia intensiva
    int totOsped;       //totale persone ospedalizzate
    int isDom;          //tot persone isolamento domiciliare
    int totPos;         //totale positivi
    int varPos;         //variazione totale positivi
    int newPos;         //nuovi positivi
    int dimGuariti;     //numero dimessi guariti
    int morti;          //numero di morti
    int cSosDiagn;      //casi sospetto diagnostico
    int cScreening;     //casi da screening
    int totCasi;        //totale casi
    int tamponi;        //totale tamponi effettuati
    int cTest;          //numero di casi testati
}Covid;

int contaReg(FILE *f){
    char str = (char*)malloc(sizeof(char)*LUNG);
    int ind = 0;

    while(fgets(str, LUNG, f) != NULL){
        ind++;
        free(str);
        str = (char*)malloc(sizeof(char)*LUNG);
    }
    return ind;
}

void leggiFile(FILE *f, Covid *d){
    char* str = (char*)malloc(sizeof(char)*LUNG);
    int ind = 0;
    while(fgets(str, LUNG, f) != NULL){
        (d + ind)->date.anno = atoi(strtok(str, "-\n"));
        (d + ind)->date.mese = atoi(strtok(NULL, "-\n"));
        (d + ind)->date.giorno = atoi(strtok(NULL, "T\n"));
        (d + ind)->date.ore = atoi(strtok(NULL, ":\n"));
        (d + ind)->date.min = atoi(strtok(NULL, ":\n"));
        (d + ind)->date.sec = atoi(strtok(NULL, ",\n"));
        strcpy((d + ind)->stato, strtok(NULL, ",\n"));
        (d + ind)->codReg = atoi(strtok(NULL, ",\n"));
        strcpy((d + ind)->nReg, strtok(NULL, ",\n"));
        (d + ind)->lat = atof(strtok(NULL, ",\n"));
        (d + ind)->longit = atof(strtok(NULL, ",\n"));
        (d + ind)->nRicSint = atoi(strtok(NULL, ",\n"));
        (d + ind)->terapInt = atoi(strtok(NULL, ",\n"));
        (d + ind)->totOsped = atoi(strtok(NULL, ",\n"));
        (d + ind)->isDom = atoi(strtok(NULL, ",\n"));
        (d + ind)->totPos = atoi(strtok(NULL, ",\n"));
        (d + ind)->varPos = atoi(strtok(NULL, ",\n"));
        (d + ind)->newPos = atoi(strtok(NULL, ",\n"));
        (d + ind)->dimGuariti = atoi(strtok(NULL, ",\n"));
        (d + ind)->morti = atoi(strtok(NULL, ",\n"));
        (d + ind)->cSosDiagn = atoi(strtok(NULL, ",\n"));
        (d + ind)->cScreening = atoi(strtok(NULL, ",\n"));
        (d + ind)->totCasi = atoi(strtok(NULL, ",\n"));
        (d + ind)->tamponi = atoi(strtok(NULL, ",\n"));
        (d + ind)->cTest = atoi(strtok(NULL, ",\n"));
        ind++;
    };
    return;
}

int main(){
    FILE *fp;

    if((fp = fopen("data.csv", "r")) == NULL){
        printf("ERROR 404, file not found...");
    }else{
        int nRegioni = contaReg(fp);  //numero di regioni presenti nel file
        fclose(fp);     //chiudo il file perchè è già stato letto fino alla fine (rimette poi il cursore a inizio file)
        Covid* dati = (Covid*)malloc(sizeof(Covid)*nRegioni);    //vettore di strutture covid
        fp = fopen("data.csv", "r");
        leggiFile(fp, dati);
        free(dati);
        fclose(fp);
        return 0;
    }
}