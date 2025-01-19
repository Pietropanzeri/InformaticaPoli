#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Dim 10

#pragma region Es2
typedef struct El{
    int val;
    struct El * prox;
}El;

typedef El * Lista;

Lista func(int array[], int dim){
    Lista L = NULL;
    El * elementoprec = malloc(sizeof(El));
    El * elemento = NULL;
    L = elementoprec;
    int cont = 0;
    for (int i = 0; i < dim - 1; i++)
    {
        cont++;
        if(array[i] != array[i+1])
        {
            elementoprec->val = cont;
            cont = 0;
            elemento = malloc(sizeof(El));
            elementoprec->prox = elemento;
            elementoprec = elemento;
        }
    }

    elementoprec->val = ++cont;
    elementoprec->prox = NULL;
    return L;
}

#pragma endregion


#pragma region Es3
void Funz(Lista * L, int k){

    int numVal = 0, pos = 0;
    El * ElPrecCanc = *L;
    El * Appoggio = *L;
    while (Appoggio->prox != NULL)
    {
        Appoggio = Appoggio->prox;
        numVal++;
    }
    pos = (numVal/2) - k;
    if(pos < 0 || pos > numVal){
        printf("k eccessivo");
        return;
    }

    for (int i = 0; i < pos - 1; i++)   //Si ferma all'elemento precedente rispetto a quello da cancellare
    {
        ElPrecCanc = ElPrecCanc->prox;
    }

    //Ri utilizzo appoggio per non dover creare un'altra variabile
    Appoggio = ElPrecCanc->prox;
    ElPrecCanc->prox = ElPrecCanc->prox->prox;

    free(Appoggio);
    Appoggio = NULL;
    return;
}


#pragma endregion




int main(int argc, char *argv[]){
    
    //Esercizio 2
    /*
    int array[Dim] = {1, 0, 0, 1, 0, 0, 1, 0, 0, 1};
    Lista L = func(array, Dim);
    */


    //Esercizio 3
    //Ho usato L dell'esercizio 2 per non dovrne creare un'altra
    /*
    Funz(&L, 2);
    */


    //Esercizio 4
    int cont = 0;
    char carattere = EOF;
    char buffer[100];

    //Non ho usato switch case perché pensavo non lo avessimo fatto
    //Se serve si possono fare i controlli su quanti campi sono stati passati guardando argc, che deve essere = 4;
    if(strcmp(argv[3], "W") == 0){
        FILE * file = fopen(argv[1], "w");
        fprintf(file, "%s\0", argv[2]);
        fclose(file);
    }
    else if (strcmp(argv[3], "L") == 0){
        FILE * file = fopen(argv[1], "r");
        carattere = fgetc(file);
        while (carattere != EOF)
        {
            cont++;
            carattere = fgetc(file);
        }
        printf("Numero di caratteri: %d", cont);

        fclose(file);
    }
    else{
        printf("Campo non riconosciuto");
    }
    
    return 0;
}
