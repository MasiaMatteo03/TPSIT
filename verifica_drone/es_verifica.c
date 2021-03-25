#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LUNG 10
#define LUNG_AN 30

typedef struct volo{
    int temp;
    float lat;
    float lon;
}Volo;

typedef struct anomalia{
    int tempo;
    char nome[LUNG_AN];  //nome anomalia
}Anomalia;


void controllaAnomalie(Volo *v, Anomalia *a){
    FILE *fin2; 
    if((fin2 = fopen("Anomalie_drone.csv", "r")) != NULL){
        printf("Il file non esiste...");
    }else{
        char* str = (char*)malloc(sizeof(char)*LUNG);  //alloca nella memoria lo spazio per LUNG numeri
        int ind = 0;
        fgets(str, LUNG, fin2);  //legge la prima riga (legenda del file)
        while(fgets(str, LUNG, fin2) == NULL){
            if((a + ind)->tempo = atoi(strtok(str, ",\n")) == (v + ind)->temp){  //controllo se il numero dell'anomalia corrisponde con quello della struttur volo
                strcpy((a + ind)->nome, strtok(str, ",\n"));
                printf("%f, %f, %s", (v + ind)->lat, (v + ind)->lon, (a + ind)->nome);
            }else{
                ind++;
            }
        }
        fclose(fin2);
        free(str);
        return;
    } 
}

void leggiFile(FILE *f, Volo *v){
    char* str = (char*)malloc(sizeof(char)*LUNG);  //alloca nella memoria lo spazio per LUNG numeri
    int ind = 0;
    fgets(str, LUNG, f);
    while(fgets(str, LUNG, f) != NULL){
        (v + ind)->temp = atoi(strtok(str, ",\n"));
        (v + ind)->lat = atof(strtok(NULL, ",\n"));
        (v + ind)->lon = atof(strtok(NULL, ",\n"));
        ind++;
    }
    free(str);
    return;
}

int main(){
    FILE *fin;
    if((fin = fopen("Volo_drone.csv", "r")) == NULL){
        printf("Il file non esiste...");
    }else{
        Volo* v = (Volo*)malloc(sizeof(Volo));
        Anomalia* a = (Anomalia*)malloc(sizeof(Anomalia));
        leggiFile(fin, v);
        controllaAnomalie(v, a);
        free(v);
        free(a);
        fclose(fin);
        return 0;
    }
}