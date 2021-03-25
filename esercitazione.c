/*
Author: Masia Matteo
Date:

esercitazione tpsit
*/

#include <stdlib.h>
#include <stdio.h>

void stampaVettore(float v[], int nA){
    for(int k = 0; k < nA; k++){
        printf("\n%.2f ", v[k]);
    }
}

void contagiClasse(float v[], int dim, float pC){
    v[0] = 1;
    int k = 1;

    for(float sCont = 1; sCont < dim; sCont++){
        sCont = v[k] * pC;
        k++;
    }

    printf("Numero di giorni per contagiare la classe e': %d", k);
    return;
}

void inserisciDati(float *pC, int *d){
    printf("Inserisci la media delle persone contagiate...");
    scanf("%f", pC);

    printf("Inserisci gli alunni della classe...");
    scanf("%d", d);
    return;
}

void main(){
    float pCont;
    int nAlunni;

    inserisciDati(&pCont, &nAlunni);
    float vett[nAlunni];

    contagiClasse(vett, nAlunni, pCont);
    stampaVettore(vett, nAlunni);
}
