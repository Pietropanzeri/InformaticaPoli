#include <stdlib.h>
#include <stdio.h>

#define Dim 10


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




int main(){
    int array[Dim] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
    Lista L = func(array, Dim);
    return 0;
}