#include <stdio.h>
#include<stdlib.h>

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


int main () {

    Lista L = NULL;
    Risursiva(&L);
    return 0;
}