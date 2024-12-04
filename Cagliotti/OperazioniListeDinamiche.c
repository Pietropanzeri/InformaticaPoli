#include <stdio.h>
#include <stdlib.h>

typedef struct EL { 
        int info;
        struct EL * prox;
}ElemDiLista;

typedef ElemDiLista * ListaDiElem;

//Per esserre più chiaro:
//ListaDiELem e ElemDiLista vengono usati entrambi nel codice, ma non hano differenza
//sono solo per avere un idea più chiara leggendo, quando si usa ListaDiElem è per indicare il puntatore alla lista, 
//quando si usa ElemDiLista si vuole indicare un singolo nodo.
//(Unica differenza è che non esiste Lista.info)

//N.B. che Lista->info esiste ed indica il primo valore

ElemDiLista* CreaNodo(int valore){
   ElemDiLista * punt = malloc(sizeof(ElemDiLista));

    if (punt == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return NULL;  // Termina il programma se la memoria non può essere allocata
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
    if(testa == NULL){
        printf("AOOOO e' VOTA");
        return;
     }
    
    ElemDiLista* corrente = testa;
    int i = 0;
    while (corrente != NULL)
    {
        printf("Valore %d : %d\n", i, corrente->info);
        i++;
        corrente = corrente->prox;
    }    
}

void StampaListaPlus(ListaDiElem testa, char * s){
    StampaLista(testa);
    printf("%s", s);
}

ListaDiElem EliminaNodo(ListaDiElem testa, ElemDiLista * daEliminare){
    
    ElemDiLista* corrente = testa;
    
    if(daEliminare == corrente){
        ElemDiLista * punt = corrente->prox;
        free(corrente);
        return punt;
    }

    while (corrente->prox != daEliminare)
        corrente = corrente->prox;
    
    ElemDiLista * punt = corrente->prox;
    corrente->prox = corrente->prox->prox;
    free(punt);
    return testa;
}

ListaDiElem EliminaNodoPosizione(ListaDiElem testa, int indice){
    
    ElemDiLista* corrente = testa;
    
    if(indice == 0){
        ElemDiLista * punt = corrente->prox;
        free(corrente);
        return punt;
    }

    for (int i = 0; i < indice - 1; i++)
    {
        corrente = corrente->prox;
    }
    
    ElemDiLista * punt = corrente->prox;
    corrente->prox = corrente->prox->prox;
    free(punt);
    return testa;
}

ListaDiElem AggiungiNodoConPosizione(ListaDiElem testa, int pos, int valore){
    
    ElemDiLista* nuovoNodo = CreaNodo(valore);
    ElemDiLista* corrente = testa;

    if(pos == 0){
        nuovoNodo->prox = corrente;
        return nuovoNodo;
    }

    for (int i = 0; i < pos - 1; i++){
        
        if(corrente->prox != NULL)
            corrente = corrente->prox;
    }


    nuovoNodo->prox = corrente->prox;
    corrente->prox = nuovoNodo; 
    return testa;   
}

ListaDiElem EliminaLista(ListaDiElem testa){
    ElemDiLista * current = testa;
    if (current == NULL) {
        return NULL; 
    }

    EliminaLista(current->prox);
    free(current); 
    return NULL;
}

void Inverti(ElemDiLista * el1, ElemDiLista * el2){
    int val = el1->info;
    el1->info = el2->info;
    el2->info = val;
}

void OrdinaListaBubble(ListaDiElem testa){
    ElemDiLista * punti = testa;

    for (punti = punti->prox; punti != NULL; punti = punti->prox)
    {
        for (ElemDiLista * punt = testa; punt->prox != NULL; punt = punt->prox)
        {
            if(punti->info < punt->info)
                Inverti(punti, punt);
        }
    }
    
}

ListaDiElem InsertSort(ListaDiElem testa, int val){
    ElemDiLista * el = CreaNodo(val);
    OrdinaListaBubble(testa);
    ElemDiLista * punt = testa;
    if(punt->info >= el->info || testa == NULL){
        el->prox = testa;
        return el;
    }

    while (punt->prox != NULL && punt->prox->info < el->info){        
        punt = punt->prox;
    }
    if(punt->prox == NULL)
    {
        punt->prox = el;
        return testa;
    }
    el->prox = punt->prox;
    punt->prox = el;  
    return testa;  
}

void InvertiListaVoid(ListaDiElem * testa) {
    if (*testa == NULL || (*testa)->prox == NULL) {
        return;
    }

    ListaDiElem nuovaTesta = (*testa)->prox;
    InvertiListaVoid(&nuovaTesta);

    (*testa)->prox->prox = *testa;
    (*testa)->prox = NULL;

    (*testa) = nuovaTesta;
}

ListaDiElem InvertiLista(ListaDiElem testa) {
    if (testa == NULL || testa->prox == NULL) {
        return testa;
    }

    ListaDiElem  nuovaTesta = InvertiLista(testa->prox);

    testa->prox->prox = testa;
    testa->prox = NULL;

    return nuovaTesta;
}


int main (int argc, char *argv[]) {

    ListaDiElem Lista = CreaNodo(1);

    AggiungiNodo(2, Lista);
    AggiungiNodo(-2, Lista);
    AggiungiNodo(5, Lista);
    AggiungiNodo(77, Lista);
    AggiungiNodo(9, Lista);
    AggiungiNodo(3, Lista);
    StampaListaPlus(Lista, "------------\nEliminaNodo\n");

    Lista = EliminaNodo(Lista, Lista->prox->prox->prox);
    Lista = EliminaNodoPosizione(Lista, 0);

    StampaListaPlus(Lista, "------------\nAggiunta di 88\n");


    Lista = AggiungiNodoConPosizione(Lista, 0, 88);
    StampaListaPlus(Lista, "------------\nOrdina\n");

    OrdinaListaBubble(Lista);
    StampaListaPlus(Lista, "------------\nInset con posizione\n");

    Lista = InsertSort(Lista, 0);
    StampaListaPlus(Lista, "------------\nInvertiListaVoid\n");

    InvertiListaVoid(&Lista);
    StampaListaPlus(Lista, "------------\nInvertiLista\n");

    Lista = InvertiLista(Lista);
    StampaListaPlus(Lista, "------------\nEliminaLista\n");

    Lista = EliminaLista(Lista);
    StampaLista(Lista);

    return 0;
}