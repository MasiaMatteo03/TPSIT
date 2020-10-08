#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 40

void chiediStringa(char s[]){
    printf("Inserisci la stringa (non inserire numeri)...");
    fflush(stdin);
    scanf("%s", s);
    return;
}

void encoding(char s[], char s2[], int n){   
    int cont = 0;

    for(int k = 0; s[k] != '\0'; k++){
        if(s[k + 1] == s[k]){
            cont++;
        }else{
            strcpy(s, s2);
            cont = 0;
        }
        s2[k] = '\0';
    }
    return;
}

bool isCarattere(char str[], int i){
    return (str);
}

void decoding(char s[], int n){
    int cont = 0;

    for(int k = 0; s[k] != 0; k++){
        if(isCarattere(s[], k) == true){
            scanf("%c", s[k]);
        }else{
            scanf("%d", cont);
        }
    }

}

void main(){
    int scelta;
    char str[LUNG];
    char str2[LUNG];

    chiediStringa(str);

    printf("MENU':\n0 --> Esci\n1 --> Encoding\n2 --> Deconding\nLa tua scelta...");
    scanf("%d", &scelta);

    do{
        switch (scelta){
            case 0:
                break;
            case 1:
                encoding(str, str2, LUNG);
                printf("%s", str2);
                break;
            case 2:
                decoding(str, LUNG);
                break;
    
            default:
                break;
        }
    }while (scelta != 0);
    
    printf("Hai scelto di uscire.");
}