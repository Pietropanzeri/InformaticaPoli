#include <stdio.h>
#include <stdlib.h>

typedef struct El{
    int val;
    struct El * prox;
}El;

typedef El * Lista;

int Ricorsiva(Lista *lista, int sommaSuccessivi) {
    if (*lista == NULL) {
        return 0; // Caso base: lista vuota, nessun elemento eliminato
    }

    // Calcola la somma degli elementi successivi
    int nuovaSomma = sommaSuccessivi - (*lista)->val;

    int eliminati = 0;
    if ((*lista)->val < sommaSuccessivi) { // Se il valore è minore della somma degli elementi successivi
        El *daEliminare = *lista;         // Nodo da eliminare
        *lista = (*lista)->prox;          // Avanza il puntatore alla lista
        free(daEliminare);                // Libera il nodo eliminato
        eliminati = 1 + Ricorsiva(lista, nuovaSomma); // Continua con il resto della lista
    } else {
        eliminati = Ricorsiva(&(*lista)->prox, nuovaSomma); // Passa al prossimo nodo
    }

    return eliminati; // Restituisce il numero di elementi eliminati
}


void MatriceMax(int matrice[][5], int righe, int colonne){
    int matriceAppoggio[4][5];;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matriceAppoggio[i][j] = matrice[i][j];
        }  
    }
    int max = 0;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if(matrice[i][j] > max){
                max = matrice[i][j];
            }
        }
        for (int j = 0; j < colonne; j++)
        {
            if(matrice[i][j] != max){
                matrice[i][j] = 0;
            }
        }   
        max = 0;
    }
    
    max = 0;
    for (int j = 0; j < colonne; j++)
    {
        for (int i = 0; i < righe; i++)
        {
            if(matriceAppoggio[i][j] > max){
                max = matriceAppoggio[i][j];
            }
        }
        for (int i = 0; i < righe; i++)
        {
            if(matrice[i][j] != max){
                matrice[i][j] = 0;
            }
        }
        max = 0;
    }
    return;
}

int * Funzione(int array[], int dim){
    int lenght = 1;
    int maxlenght = 0;
    int * primoelemnto = array;
    int * start = array;
    int * appoggio = array;
    int i;
    for (i = 0; i < dim; i++)
    {
        if(array[i] < array[i + 1]){
            lenght++;
        }else if(lenght > maxlenght){
            maxlenght = lenght;
            lenght = 0;
            primoelemnto = start;
            start = appoggio + 1;
        }else{
            lenght = 0;
            start = appoggio + 1;
        }
        appoggio++;
    }
    if(lenght > maxlenght){
        maxlenght = lenght;
        primoelemnto = start;
    }
    printf("Lungh: %d\n", maxlenght);
    for (i = 0; i < maxlenght; i++)
    {
        printf("%d\n",primoelemnto[i]);
    }
    
    return primoelemnto;    
}

//Es 5
typedef struct Animale{
    char ID[10];
    float P;
}Animale;


int main(int argc, char * argv[]){
    /*
    Lista lista = NULL;

    El *el1 = malloc(sizeof(El));
    el1->val = 3;
    lista = el1;

    El *el2 = malloc(sizeof(El));
    el1->prox = el2;
    el2->val = 41;

    El *el3 = malloc(sizeof(El));
    el2->prox = el3;
    el3->val = 11;

    El *el4 = malloc(sizeof(El));
    el3->prox = el4;
    el4->val = 6;

    El *el5 = malloc(sizeof(El));
    el4->prox = el5;
    el5->val = 6;

    El *el6 = malloc(sizeof(El));
    el5->prox = el6;
    el6->val = 2;

    El *el7 = malloc(sizeof(El));
    el6->prox = el7;
    el7->val = 3;

    El *el8 = malloc(sizeof(El));
    el7->prox = el8;
    el8->val = 0;

    El *el9 = malloc(sizeof(El));
    el8->prox = el9;
    el9->val = 1;

    El *el10 = malloc(sizeof(El));
    el9->prox = el10;
    el10->val = -1;

    el10->prox = NULL;

    int sommaTotale = 0;
    Lista temp = lista;
    while (temp != NULL) {
        sommaTotale += temp->val;
        temp = temp->prox;
    }

    Ricorsiva(lista, sommaTotale);
    */
    
    /*
    int matrice[4][5] = {
        {5,12,1,3,2},
        {14,3,24,18,13},
        {8,1,7,12,11},
        {15,10,12,5,9}
    };

    MatriceMax(matrice, 4, 5);
    */
    
    //Es 3
    /*
    int array[10] = {1,2,8,77,99,125,4,5,8,9};
    
    int * punt = Funzione(array, 10);
    int a = *punt;
    */

    //Es 5
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    Animale animale1, animale2;

    while (fscanf(file1, "%s %f", animale1.ID, &animale1.P) == 2 && fscanf(file2, "%s %f", animale2.ID, &animale2.P) == 2) {
        
        int i = 0;
        while (animale1.ID[i] != '\0' && animale2.ID[i] != '\0' && animale1.ID[i] == animale2.ID[i]) {
            i++;
        }

        if (animale1.ID[i] == '\0' && animale2.ID[i] == '\0') {
            printf("%s %.2f\n", animale1.ID, animale1.P - animale2.P);
        }
    }

    fclose(file1);
    fclose(file2);

    return 0;
}