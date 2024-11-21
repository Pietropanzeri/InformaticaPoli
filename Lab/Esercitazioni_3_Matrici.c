#include <stdio.h>
#include <string.h>
#define numCol 10
#define numRow 10

void LeggiMatrice(int matrice[][numCol], int righe, int colonne){

    if(righe > numRow)
        righe = numRow;
    if(colonne > numCol)
        colonne = numCol;
    
    printf("Inserisci I valori della matrice: \n");
    for (int i = 0; i < righe; i++)
    {
        printf("Righa %d:\n", i + 1);
        for (int j = 0; j < colonne; j++)
        {
            scanf("%d", &matrice[i][j]);
        }   
    }
    
    return;
}

void StampaMatrice(const int matrice[][numCol], int righe, int colonne){
    
    char separatore[200] = "";
    char separatore2[200] = "";

    for (int i = 0; i < colonne; i++){
        strcat(separatore2, "|---------------");
        strcat(separatore , "----------------");
    }

    strcat(separatore2, "|\n");
    strcat(separatore , "-\n");

    //Stampa
    printf("\n");
    for (int i = 0; i < righe; i++)
    {
        printf("%s", separatore2);
        for (int j = 0; j < colonne; j++)
        {
            printf("|\t%d\t", matrice[i][j]);
        }
        printf("|\n");
    }
    printf("%s\n", separatore2);
    return;
}

int SommaMatrice(const int matrice[][numCol], int righe, int colonne){

    int somma = 0;

    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            somma += matrice[i][j];
        }
        
    }
    
    return somma;

}


int main () {

    int matrice[numRow][numCol];

    LeggiMatrice(matrice, 2, 2);
    StampaMatrice(matrice, 2, 2);
    
    printf("Somma: %d", SommaMatrice(matrice, 2, 2));
    return 0;
}
