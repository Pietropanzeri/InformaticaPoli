#include <stdio.h>
#include <stdlib.h>

typedef struct EL { 
        int info;
        struct EL * prox;

        int (*Pop)(struct EL**);
        void (*Push)(struct EL**, int val);
        void (*VisualizzaEliminaPila)(struct EL**);
}ElemDiLista;

typedef ElemDiLista * ListaDiElem;


int Pop(ListaDiElem * testa){
    if(*testa == NULL)
        return 0;
    ElemDiLista * app;
    *testa = app;

    *testa = (*testa)->prox;
    int val = app->info;
    free(app);
    return val;
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

void VisualizzaEliminaPila(ListaDiElem * testa){
    StampaListaPlus(*testa, "-----\nUltima Stampa Della Lista prima di Eliminare:");
    EliminaLista(&(*testa));
}

void Push(ListaDiElem * testa, int val){
    if(*testa == NULL)
        return;

    ElemDiLista * elemento = malloc(sizeof(ElemDiLista));
    if(val != 0)
    {
        elemento->info = val;
        elemento->prox = *testa;
        elemento->Pop = Pop;
        elemento->Push = Push;
        elemento->VisualizzaEliminaPila = VisualizzaEliminaPila; 
        *testa = elemento;
    }
}

void InserimentoValori(ListaDiElem * testa){
    int ins = 4;
    ElemDiLista * corrente = *testa;
    printf("Inserisci i valori che vuoi inserire nella lista, termina con 0\n");
    
    printf("Inserisci:\n");
    scanf("%d", &ins);
    while (ins != 0)
    {
        ElemDiLista * elemento = malloc(sizeof(ElemDiLista));
        if(elemento == NULL)
        {
            printf("Errore nell'allocazione della memoria\n");
            return;
        }
        elemento->info = ins;
        elemento->prox = NULL;
        elemento->Pop = Pop;
        elemento->Push = Push;
        elemento->VisualizzaEliminaPila = VisualizzaEliminaPila;  

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
        printf("Inserisci:\n");
        scanf("%d", &ins);
    }
    
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

    while (current->prox != NULL && current->prox->info != num )
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
    nuovo->Pop = Pop;
    nuovo->Push = Push;
    nuovo->VisualizzaEliminaPila = VisualizzaEliminaPila;  
    current->prox = nuovo;
    StampaListaPlus(*testa,  "-----");    
}

int main (int argc, char *argv[]) {

    ListaDiElem Lista = NULL; 

    InserimentoValori(&Lista);
    StampaListaPlus(Lista, "-----");
    
    printf("Valore da eliminare?\n");
    int val;
    scanf("%d", &val);
    EliminaNum(&Lista, val);

    InserisciInLista(&Lista, 9, 2);

    Lista->Push(&Lista, 5);
    StampaListaPlus(Lista, "-----");

    printf("Rimosso il: %d\n", Lista->Pop(&Lista));
    StampaListaPlus(Lista, "-----");

    Lista->VisualizzaEliminaPila(&Lista);

    StampaListaPlus(Lista, "-----");

    return 0;
}