#include <stdio.h>
#include <stdlib.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





                                                    NON TESTATO





~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct OBJ{
    int peso;
    int altezza;
    struct OBJ * nextaltezza;
    struct OBJ * nextpeso;
}OBJ;

typedef OBJ * Lista;

void EliminaVal (Lista * L, int h){
    OBJ * Appoggio = NULL;
    OBJ * elementoprecA = (*L);
    OBJ * elementoprecP = (*L);
    int pesoinferiore = elementoprecA->peso;
    if(elementoprecA->altezza != h){
        while (elementoprecA->nextaltezza->altezza != h || elementoprecA->nextaltezza == NULL)
        {
            elementoprecA = elementoprecA->nextaltezza;
            if(elementoprecA->peso <= pesoinferiore){
                pesoinferiore = elementoprecA->peso;
                elementoprecP = elementoprecA;
            }
        }
        if(elementoprecA->nextaltezza == NULL){
            printf("valore non trovato");
            return;
        }
        if(elementoprecP->peso != elementoprecA->nextaltezza->peso){
            while (elementoprecP->nextpeso->peso != elementoprecA->nextaltezza->peso)   
            {           
                elementoprecP = elementoprecP->nextpeso;
            }
            Appoggio = elementoprecA->nextaltezza;
            elementoprecA->nextaltezza = elementoprecA->nextaltezza->nextaltezza;
            elementoprecP->nextpeso = elementoprecP->nextpeso->nextpeso;
            free(Appoggio);
            return;
        }
        else{
            Appoggio = elementoprecA->nextaltezza;
            elementoprecA->nextaltezza = elementoprecA->nextaltezza->nextaltezza;
            free(Appoggio);
            return;
        }


    }else{
        if(elementoprecP->peso != elementoprecA->peso){
            while (elementoprecP->nextpeso->peso != elementoprecA->peso)   
            {           
                elementoprecP = elementoprecP->nextpeso;
            }
            (*L) = elementoprecA->nextaltezza;
            elementoprecP->nextpeso = elementoprecP->nextpeso->nextpeso;
            free(elementoprecA);
            return;
        }
        //Si potrebbe fare un'altra funzione per non ripetre
        (*L) = elementoprecA->nextaltezza;
        free(elementoprecA);
        return;
    }
}

int Ricorsiva(int val){
    if (val < 10)
        return val;
    return val % 10 + Ricorsiva(val/10);
}

char * Esercizio4(char * s1, char * s2){

    int cont = 0;
    char * app = s1;
    while (*app != '\0')
    {
        app++;
        cont++;
    }
    
    char * stringa = malloc(cont + 1);
    char * stringafinale = stringa;
    while (*s1 != '\0')
    {
        if(*s1 != *s2){
            *stringa = *s1;
            stringa++;
        }
        else{
            s2++;
        }
        s1++;
    }
    *stringa = '\0';   
    return stringafinale;
}

int main(int argc, char * argv[]){


    /*
    Lista ListaAltezza;
    //Creazione oggetti a mano per test

    OBJ * oggetto1 = malloc(sizeof(OBJ));
    OBJ * oggetto2 = malloc(sizeof(OBJ));
    OBJ * oggetto3 = malloc(sizeof(OBJ));
    OBJ * oggetto4 = malloc(sizeof(OBJ));

    oggetto1->altezza = 1;
    oggetto1->peso = 4;

    oggetto2->altezza = 2;
    oggetto2->peso = 8;

    oggetto3->altezza = 3;
    oggetto3->peso = 0;

    oggetto4->altezza = 4;
    oggetto4->peso = 5;

    oggetto1->nextaltezza = oggetto2;
    oggetto2->nextaltezza = oggetto3;    
    oggetto3->nextaltezza = oggetto4;
    oggetto4->nextaltezza = NULL;

    oggetto3->nextpeso = oggetto1;
    oggetto1->nextpeso = oggetto4;
    oggetto4->nextpeso = oggetto2;
    oggetto2->nextpeso = NULL;

    ListaAltezza = oggetto1;


    EliminaVal(&ListaAltezza, 3);
    */

    //printf("%d",Ricorsiva(12345));

    //Es4
    char * s = Esercizio4(argv[1], argv[2]);
    FILE * f = fopen(argv[3], "w");
    fprintf(f, s);
    return 0;
}