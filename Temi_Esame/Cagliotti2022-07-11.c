#include <stdio.h>
#include <stdlib.h>

#define Dim 5
#define MaxCol 256

//per esrczio 2
typedef struct Elemento
{
    int val;
    struct Elemento * prox;
}Elemento;

typedef Elemento * Lista;
//Es 2
Lista Funzione(int matrice[][5], int righe, int colonne){
    int i;
    int j;
    Lista ListaMax = NULL;
    Elemento * ElementoPrecedente = NULL;
    for (i = 1; i < righe - 1; i++)
    {
        for (j = 1; j < colonne - 1; j++)
        {
            int a = matrice[i][j];
            if(matrice[i][j] > matrice[i-1][j] && matrice[i][j] > matrice[i+1][j] && matrice[i][j] > matrice[i][j - 1] && matrice[i][j] > matrice[i][j +1])
            {
                Elemento * EL = malloc(sizeof(Elemento));
                EL->val = matrice[i][j];
                EL->prox = NULL;
                if(ListaMax == NULL){
                    ListaMax = EL;
                    ElementoPrecedente = EL;
                }else{
                    ElementoPrecedente->prox = EL;
                    ElementoPrecedente = EL;
                }
            }
        }
        
    }
    return ListaMax;
    
}

//Es 4
int MatriceBinaria(int matrice[][5]){
    int val = 0;
    int cont = 0;
    int maxcont = 0;
    int posizione = 0;
    int j = 0;
    int maxorder = 0;
    for (int i = 0; i < 5; i++)
    {
        //forse posso usare una solo variabile invece che j e cont
        while (j < 5)
        {
            if(matrice[i][j] == 1)
            {
                cont++;
                if(maxcont <= cont)
                {
                    maxcont = cont;
                    if(cont == 1)
                        posizione = j;  //posizione corrisponde alla colonna in cui iniziano gli 1
                }
            }
            else
                cont = 0;
            
            j++;
        }
        //uso j per una altro scopo
        j = 0;
        for (j = i; j < maxcont + i; j++)
        {
            for (int h = posizione; h < maxcont + posizione; h++)
            {
                if(h < 5 && j < 5 && matrice[j][h] == 1)
                    val++;
            }
        }
        if(val == maxcont*maxcont && maxcont > maxorder){
            maxorder = maxcont;
        }
        val = 0;  
        j = 0;
        maxcont = 0;
    }
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAA comunquen non va se tipo ho una matrice cha ha 11100, 11000, 00000, 00000, 00000 
    //allora piango e non ho voglia di capire come si fa, c'è sicuro un modo più semplice
    if(maxorder > 0)
        return maxorder;
    else
    {
        for (int a = 0; a < 5; a++)
        {
            for (int b = 0; b < 5; b++)
            {
                if(matrice[a][b] == 1)
                    return 1;
            }
            
        }
        
    }
    return 0;
    
}

//Es 3
int Ricorsiva(){
    int next = 0;
    int numero = 0;
    printf("Inserisci un numero, chiudi con negativo\n");
    scanf("%d", &numero);
    printf("\n");
    if(numero >= 0){
        next = Ricorsiva();
    }
    else{
        return numero;
    }
    if(next > numero)
        printf("%d\n", next);

    return numero;

}

//Es 5
typedef struct TipoStudente{
    int matricola;
    float media;
    char tipoLaurea;
}TipoStudente;

typedef struct Studenti
{
    int N;
    TipoStudente elenco[100];
}Studenti;


int main(int argc, char * argv[]){
        
    //ES 4
    /*
    int matrice[5][5] = {
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int order = MatriceBinaria(matrice);

    printf("%d", order);
    */
    //ES 2
    /*
    int matrice[5][5] = {
        {1, 1, 1, 4, 4},
        {0, 8, 0, 6, 0},
        {0, 1, 0, 3, 1},
        {0, 12, 0, 33, 0},
        {0, 8, 0, 0, 0}
    };

    Lista L;
    L = Funzione(matrice, 5, 5);
    */

    //ES 3
    /*
    Ricorsiva();
    */

    //Es 5
    /*
    char * buffer = malloc(sizeof(char) * 17000);
    Studenti studenti;
    studenti.N = 0;

    FILE * file = fopen(argv[1], "r");
    fgets(buffer, 17000, file);

    while (*buffer != '\n'){
        buffer++; //salta (
        sscanf(buffer, "%d", &studenti.elenco[studenti.N].matricola);
        buffer = buffer + 8; //salta 000000)_
        sscanf(buffer, "%f", &studenti.elenco[studenti.N].media);
        buffer = buffer + 6; //salta 11.11_
        studenti.elenco[studenti.N].tipoLaurea = *buffer;
        buffer = buffer + 2;
        studenti.N++;
    }
    for (int i = 0; i < studenti.N; i++)
    {
        printf("(%d) %.2f %c- ", studenti.elenco[i].matricola, studenti.elenco[i].media, studenti.elenco[i].tipoLaurea);
    }
    */
    return 0;
}