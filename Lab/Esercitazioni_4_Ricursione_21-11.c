#include <stdio.h>
#include <stdlib.h>         //x atoi


typedef struct 
{
    int a;
    int b;

} Tupla;

int Fattoriale(int num){
    if(num == 0)
        return 1;
    return num * Fattoriale(num - 1);
}

int FattorialeNonRicursivo(int num){
    int ris = 1;
    for (int i = 1; i <= num; i++)
    {
        ris *= i;
    }
    return ris;
    
}

void SommaeProdotto(int* n1, int* n2){
    int n = (*n1);
    int nn = (*n2);

    (*n1) = n + nn;
    (*n2) = n * nn;
}

Tupla SommaeProdottoT(int a, int b){
    Tupla ris = {a + b, b * a};
    return ris;
}

int main (int argc, char *argv[]) {

    //FATTORIALE
    //printf("Fattoriale: %d", Fattoriale(atoi(argv[1])));
    //printf("Fattoriale: %d", FattorialeNonRicursivo(5));


    //SOMMAPRODOTTO
    /*int a, b;
    a = atoi(argv[1]); 
    b = atoi(argv[2]);

    SommaeProdotto(&a, &b);

    printf(" :>> %d\n", a);
    printf(" :>> %d\n", b);   */

    /*
    Tupla a = SommaeProdottoT(3, 4); 
    printf(" :>> %d\n", a.a);
    printf(" :>> %d\n", a.b);*/
    
}