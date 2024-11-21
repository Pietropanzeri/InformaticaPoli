#include <stdio.h>
#include <stdlib.h>         //x atoi
#include <string.h>

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

void Calcolatrice( int argc, char* argv[]){

    int tot = 0;
    if(!strcmp(argv[1],"somma")){
        for (int i = 2; i < argc; i++)
        {
            tot += atoi(argv[i]);
        }
        printf("Somma :>> %d\n", tot);
        return;
    }else if (!strcmp(argv[1],"moltiplicazione"))
    {
        tot = 1;
        for (int i = 2; i < argc; i++)
        {
            tot *= atoi(argv[i]);
        }
        printf("Risultato :>> %d\n", tot);
        return;
    }else if (!strcmp(argv[1],"fattoriale"))
    {
        for (int i = 2; i < argc; i++)
        {
            printf("Fattoriale di %d : %d\n", atoi(argv[i]) , Fattoriale(atoi(argv[i])));
        }
        return;
    }else
    {
        printf("scrivi meglio");
    }
    
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



    //OK, QUI SE TOLGO (int argc, char *argv[]) DAL MAIN, FUNZIONA SE METTO _argc E _argv, COMPILA CORRETTAMENTE MA GLI SNIPPETS DANNO ERRORE, QUINDI è BRURTTO DA VEDERE
    //Funziona ma è brutto
    //Calcolatrice(_argc, _argv);

    
    Calcolatrice(argc, argv);

}