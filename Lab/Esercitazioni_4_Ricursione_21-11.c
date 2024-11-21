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

int SommaArgs(int argc,char *argv[] ){
    int somma = 0;

    for (int i = 1; i < argc; i++)
        somma += atoi(argv[i]);
    
    return somma;
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
    
    val1 = atoi(argv[1]); 
    val2 = atoi(argv[2]);
    Tupla a = SommaeProdottoT(val1, val2); 

    printf(" :>> %d\n", a.a);
    printf(" :>> %d\n", a.b);*/



    //SommaArgs
    /*
    printf("Somma: %d", SommaArgs(argc, argv));
    */


   
}