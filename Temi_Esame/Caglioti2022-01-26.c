#include <stdio.h>
#include<stdlib.h>

//Per esercizio 3
#define Dim 10


#pragma region Es2
typedef struct El
{
    int val;
    struct El * prox;
}El;

typedef El * Lista;

void Risursiva(Lista * L){
    char val = '\0';
    El * elemento = malloc(sizeof(El));
    printf("inserisci il valore\n");
    scanf(" %c", &val);
    printf("\n");

    if(val == '-')
    {
        free(elemento);
        return;
    }
    elemento->val = val;
    elemento->prox = *L;

    (*L) = elemento;
    Risursiva(L);
    return;
}
#pragma endregion

#pragma region Es3
/*Ho messo le dimensione perché sembra che servano da comq ho interpretato il testo,
ma se non volesse che vangano passate, o si usa la dimensione massima per ogni array, ma credo sia
la soluzione sbagliata dato che nell'esempio usa 2 array di dimensione differente, oppure se si sa che gli array
hanno una qualche sorta di carattere terminatore si fanno due for per trovare la lughezza, ma non mi sembra
sia questo il caso*/
int Funzione(int arrayA[], int arrayB[], int dimA , int dimB){ 
    int dimArrayRis = dimA*dimB;
    int arrayRis[dimArrayRis];
    int pos = 0;
    int popular, maxCont, cont;
    for (int i = 0; i < dimB; i++)
    {
        for(int j = 0; j < dimA; j++){
            arrayRis[pos] = arrayB[i] - arrayA[j];
            pos++;
        }
    }

    popular = arrayRis[0];
    maxCont = 0;
    cont = 0;
    for (int i = 0; i < dimArrayRis; i++)
    {
        for (int j = 0; j < dimArrayRis; j++)       
        /*Si potrebbe fare più efficente facendolo partire senza ricontrollare i numeri dietro,
        perché in quel caso quella ricorenza sarebbe già stata controllata, ci vuole poco, ma diventa meno 
        comprensibile e non piace al cagliotti*/
        {
            
            if(arrayRis[i] == arrayRis[j]){
                cont++;
            }
        }
        if(maxCont < cont){
            popular = arrayRis[i];
            maxCont = cont;
        }     
        cont = 0;
    }
    return popular;
}
#pragma endregion

int main (int argc, char *argv[]) {


    //Esercizio 2
    /*
    Lista L = NULL;
    Risursiva(&L);
    return 0;
    */


    //Esercizio 3
    /*
    int arrayA[3] = {1, 2, 3};
    int arrayB[5] = {2, 2 ,2 ,5 ,0};
    int ris = Funzione(arrayA, arrayB, 3, 5);
    */

    //Esercizio 4
    //Presumo che vada messo .txt nel nome, altrimenti andrebbe aggiunto i con strcat, o a mano cercando \0 e aggiungendo da lì
    FILE* file = fopen(argv[1], "w");

    for (int i = 2; i < argc; i++) // - 2 per togliere il nome del programma e il nome del file dal conto
    {
        fprintf(file, "%s", argv[i]);
        if(i != (argc-1)){
            fprintf(file, ",");
        }
    }
    fclose(file);
    



}