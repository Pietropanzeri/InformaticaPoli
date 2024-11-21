#include <stdio.h>
#define MAX_ELEM 100
typedef struct 
{
    int elementi[MAX_ELEM];
    int NumeroElementi;

} Lista;


void LeggiLista(Lista * L){

    int num = 1;
    
    printf("Inserisci gli elementi della lista, per terminare inserire 0\n");
    for (int i = 0; i < MAX_ELEM && num != 0; i++)
    {
        printf("Inserisci elemento %d: ", i);
        scanf("%d", &num);
        L->elementi[i] = num;
        L->NumeroElementi++;
    }

    L->NumeroElementi--;
    return;
}

void StampaLista(Lista * L){

    printf("\nLista: ");
    for (int i = 0; i < L->NumeroElementi; i++)
    {
        printf("%d ", L->elementi[i]);
    }
    printf("\n");
    return;
}

int SommaLista(Lista * L){
    int somma = 0;
    for (int i = 0; i < L->NumeroElementi; i++)
    {
        somma += L->elementi[i];
    }
    return somma;
}

int TrovaMassimo(Lista * L){
    int max = L->elementi[0];
    for (int i = 1; i < L->NumeroElementi; i++){
        if (L->elementi[i] > max)
        max = L->elementi[i];
    }
    return max;
}

int TrovaMinimo(Lista * L){
    int min = L->elementi[0];
    for (int i = 1; i < L->NumeroElementi; i++){
        if (L->elementi[i] < min)
        min = L->elementi[i];
    }
    return min;
}

float CalcoloMedia(Lista * L){
    int somma = SommaLista(L);
    return (somma*1.0)/L->NumeroElementi;
}

void OrdinaLista(Lista *L ){
    int temp;
    for (int i = 0; i < L->NumeroElementi; i++)
    {
        for(int j = 1; j < L->NumeroElementi; j++){

            if (L->elementi[j] < L->elementi[j - 1]){
                temp = L->elementi[j];
                L->elementi[j] = L->elementi[j - 1];
                L->elementi[j - 1] = temp;
            }

        }
    }
    return;
}

int EliminaLista(Lista * L, int pos){
    if (pos < 0 || pos >= L->NumeroElementi) 
        return 0;
    for (int i = pos; i < L->NumeroElementi - 1; i++)
        L->elementi[i] = L->elementi[i + 1];
    L->NumeroElementi--;
    return 1; 
}

void StampaDuplicati(Lista* L){
    
    int rip = 0;

    printf("Valori ripetuti:\n");
    for (int i = 0; i < L->NumeroElementi; i++)
    {
        for (int j = i + 1; j < L->NumeroElementi; j++)
        {
            if(L->elementi[i] == L->elementi[j])
                rip++;
        }
        if(rip == 1)
            printf("%d\n", L->elementi[i]);
        rip = 0;
    }
    return;
}

void EliminaDuplicati(Lista* L){

    int rip = 0;

    for (int i = 0; i < L->NumeroElementi; i++)
    {
        for (int j = i + 1; j < L->NumeroElementi; j++)
        {
            if(L->elementi[i] == L->elementi[j]){
                EliminaLista(L, j);
               j--;
            }
        }       
    }
    
    return; 
}

int main () {

    Lista lista;
    lista.NumeroElementi = 0;

    LeggiLista(&lista);

    StampaLista(&lista);

    printf("Somma: %d\n", SommaLista(&lista));

    printf("Massimo: %d\n", TrovaMassimo(&lista));
    printf("Minimo: %d\n", TrovaMinimo(&lista));
    printf("Media: %f\n", CalcoloMedia(&lista));

    OrdinaLista(&lista);
    printf("Lista Ordinata:");
    StampaLista(&lista);

    printf("Che elemento vuoi eliminare? ");
    int i = 0;

    scanf("%d", &i);
    printf("Risultato dell' eliminazione: %d", EliminaLista(&lista, i));
    StampaLista(&lista);

    StampaDuplicati(&lista);

    //Valori Eliminati
    EliminaDuplicati(&lista);

    StampaLista(&lista);

    return 0;
}