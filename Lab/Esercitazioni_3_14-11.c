#include <stdio.h>
#define MAX_ELEM 100

int i;
int j;

typedef struct 
{
    int elementi[MAX_ELEM];
    int NumeroElementi;

} Lista;


void LeggiLista(Lista * L){

    int num = 1;
    
    printf("Inserisci gli elementi della lista, per terminare inserire 0\n");
    for (i = 0; i < MAX_ELEM && num != 0; i++)
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
    for (i = 0; i < L->NumeroElementi; i++)
    {
        printf("%d ", L->elementi[i]);
    }
    printf("\n");
    return;
}

int SommaLista(Lista * L){
    int somma = 0;
    for (i = 0; i < L->NumeroElementi; i++)
    {
        somma += L->elementi[i];
    }
    return somma;
}

int TrovaMassimo(Lista * L){
    int max = L->elementi[0];
    for (i = 1; i < L->NumeroElementi; i++){
        if (L->elementi[i] > max)
        max = L->elementi[i];
    }
    return max;
}

int TrovaMinimo(Lista * L){
    int min = L->elementi[0];
    for (i = 1; i < L->NumeroElementi; i++){
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
    for (i = 0; i < L->NumeroElementi; i++)
    {
        for(j = 1; j < L->NumeroElementi; j++){

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
    for (i = pos; i < L->NumeroElementi - 1; i++)
        L->elementi[i] = L->elementi[i + 1];
    L->NumeroElementi--;
    return 1; 
}

//AAAAAAAAAAA DA FINIRE
void StampaDuplicati(Lista L){
    int tst = 0;
    for (i = 0; i < L.NumeroElementi; i++)
    {
        for(j = 0; j < L.NumeroElementi; j++){
            if (L.elementi[i] == L.elementi[j] && i != j){    
                tst = 1;           
                EliminaLista(&L, j);
            }
        }
        if(tst == 1){
            printf("%d\n", L.elementi[i]);
            tst = 0;
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
    scanf("%d", &i);
    printf("Risultato dell' eliminazione: %d", EliminaLista(&lista, i));
    StampaLista(&lista);

    StampaDuplicati(lista);

    return 0;
}