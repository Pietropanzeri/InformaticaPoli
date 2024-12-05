#include <stdio.h>
#include <stdlib.h>

typedef struct EL { 
        int info;
        struct EL * prox;
}ElemDiLista;

typedef ElemDiLista * ListaDiElem;

void InserimentoValori(ListaDiElem * testa){
    int ins = 4;
    ElemDiLista * corrente = *testa;
    printf("Inserisci i valori che vuoi inserire nella lista, termina con 0\n");
    while (ins != 0)
    {
        ins = ins-1;
        printf("Inserisci:\n");
        //scanf("%d", &ins);
        ElemDiLista * elemento = malloc(sizeof(ElemDiLista));
        if(elemento == NULL)
        {
            printf("Errore nell'allocazione della memoria\n");
            return;
        }
        elemento->info = ins;
        elemento->prox = NULL;

        if(*testa == NULL)
        {
            *testa = elemento;
            corrente = *testa;
        }
        else
        {
            corrente->prox = elemento;
            corrente = corrente->prox;
        }
    }
    
}

void StampaLista(ListaDiElem testa){
    if(testa == NULL){
        return;
    }
    printf(":>> %d\n", testa->info);
    StampaLista(testa->prox); 
}

void StampaListaPlus(ListaDiElem testa, char * s){
    
    printf("%s\n", s);
    StampaLista(testa);
}

void EliminaLista(ListaDiElem * testa){
    ElemDiLista * current = (*testa);
    if (current == NULL) {
        return; 
    }

    EliminaLista(&(current->prox));        
    free(current);
    *testa = NULL;
    return;
}

void EliminaNum(ListaDiElem * testa, int num){
    ElemDiLista * current = *testa;

    if(current->info == num)
    {
        ElemDiLista * app = *testa;
        *testa = (*testa)->prox;
        free(app);    
        StampaListaPlus(*testa, "-----");
        return;
    }

    while (current->prox != NULL && current->prox->info != num)
        current = current->prox;
    
    if(current->prox == NULL)
    {
        printf("\nERRORE NELL'ELIMINAZIONE\n");
        return;
    }
    
    ElemDiLista * app = current->prox;
    current->prox = current->prox->prox;
    free(app);    
    StampaListaPlus(*testa, "-----");
}

void InserisciInLista(ListaDiElem * testa, int val, int index){
    ElemDiLista * current = *testa;
    if((*testa) == NULL)
    {
        printf("Index out of bounds");
        return;
    }

    for (int i = 0; i < index; i++)
    {
        if(current == NULL){
            printf("Index out of bounds");
            return;
        }
        current = current->prox;
    }
    ElemDiLista * nuovo = malloc(sizeof(ElemDiLista));
    nuovo->info = val;
    nuovo->prox = current->prox;
    current->prox = nuovo;
    StampaListaPlus(*testa,  "-----");    
}

//Esercizio 5 da fare

int main (int argc, char *argv[]) {

    ListaDiElem Lista = NULL; 

    InserimentoValori(&Lista);
    StampaListaPlus(Lista,  "-----");
    
    EliminaNum(&Lista, 0);

    InserisciInLista(&Lista, 9, 2);

    EliminaLista(&Lista);

    return 0;
}