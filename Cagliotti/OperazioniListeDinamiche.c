#include <stdio.h>
#include <stdlib.h>

typedef struct EL { 
        int info;
        struct EL * prox;
}ElemDiLista;

typedef ElemDiLista * ListaDiElem;

ElemDiLista* CreaNodo(int valore){
   ElemDiLista * punt = malloc(sizeof(ElemDiLista));

    if (punt == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        exit(1);  // Termina il programma se la memoria non può essere allocata
    }
    punt->info = valore;
    punt->prox = NULL;  // Il prossimo nodo è NULL (fine della lista)
    return punt;

}

void AggiungiNodo(int valore, ListaDiElem testa){
    ElemDiLista* nuovoNodo = CreaNodo(valore);
    if (testa == NULL) {
        testa = nuovoNodo;  // Se la lista è vuota, il nuovo nodo diventa la testa
        return;
    }

    ElemDiLista* corrente = testa;
    // Ricerca dell'ultimo elemento
    while (corrente->prox != NULL) {    
        corrente = corrente->prox;  // Vai all'ultimo nodo
    }
    corrente->prox = nuovoNodo;  // Aggiungi il nuovo nodo alla fine
}

void StampaLista(ListaDiElem testa){
    if(testa == NULL)
        return;
    
    ElemDiLista* corrente = testa;
    int i = 0;
    while (corrente != NULL)
    {
        printf("Valore %d : %d\n", i, corrente->info);
        i++;
        corrente = corrente->prox;
    }    
}

ListaDiElem EliminaNodo(ListaDiElem testa, ElemDiLista * daEliminare){
    
    ElemDiLista* corrente = testa;
    
    if(daEliminare == corrente){
        testa = corrente->prox;
        return testa;
    }

    while (corrente->prox != daEliminare)
        corrente = corrente->prox;
    
    corrente->prox = corrente->prox->prox;

    return corrente;

}

ListaDiElem AggiungiNodoConPosizione(ListaDiElem testa, int pos, int valore){
    
    ElemDiLista* nuovoNodo = CreaNodo(valore);
    ElemDiLista* corrente = testa;

    if(pos == 0){
        nuovoNodo->prox = corrente;
        testa = nuovoNodo;
        return testa;
    }

    for (int i = 0; i < pos - 1; i++){
        
        if(corrente->prox != NULL)
            corrente = corrente->prox;
    }


    nuovoNodo->prox = corrente->prox;
    corrente->prox = nuovoNodo;    

    return testa;

}

int main (int argc, char *argv[]) {

    /*ElemDiLista * punt = malloc(sizeof(ElemDiLista));

    punt->info = 1;
    
    ElemDiLista * punt2 = malloc(sizeof(ElemDiLista));

    punt->prox = punt2;

    punt2->prox = NULL;

    punt2->info = 2;*/

    ListaDiElem Lista = CreaNodo(1);

    AggiungiNodo(2, Lista);
    AggiungiNodo(3, Lista);
    AggiungiNodo(4, Lista);
    AggiungiNodo(5, Lista);
    Lista = EliminaNodo(Lista, Lista->prox);
    Lista = AggiungiNodoConPosizione(Lista, 1, 33);

    StampaLista(Lista);


    return 0;
}