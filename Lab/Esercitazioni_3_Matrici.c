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

void MassimoPerRiga(const int matrice[][numCol], int righe, int colonne, int massimo[]){
     
    printf("Max di ogni riga: \n");

    for (int i = 0; i < righe; i++)
    {
        int max = matrice[i][0];
        for (int j = 0; j < colonne; j++)
        {
            if(max < matrice[i][j])
                max = matrice[i][j];
        }
        printf("Riga %d:\n", i);
        printf("Massimo: %d\n", max);
        massimo[i] = max;
    }
    return;
}

void TraspostaMatrice(const int matrice[][numCol], int trasposta[][numRow], int righe, int colonne){

    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            trasposta[j][i] = matrice[i][j];
        }
    }
    return;
}

//FUNZIONA ANCHE PER LE NON QUADRATE PERCHE' HO VOLGIA CHE LO FACCIA
int ProdottoRigaColonna(const int matrice[][numCol], int righe, int colonne, int riga, int colonna){
    int somma = 0, col = 0, row = 0;

    for (int i = 0; i < righe; i++)
    {
        row = i;
        col = i;

        if(i >= colonne)
            col = 0;
        if(i >= righe)
            row = 0;
            
        somma += matrice[riga][col] * matrice[row][colonna];    
    }

    return somma;
}

int main () {

    int matrice[numRow][numCol];
    int trasposta[numCol][numRow];
    int max[numCol];

    int row = 3;
    int col = 4;


    LeggiMatrice(matrice, row, col);
    StampaMatrice(matrice, row, col);
    
    printf("Somma: %d", SommaMatrice(matrice, row, col));

    MassimoPerRiga(matrice, row, col, max);

    TraspostaMatrice(matrice, trasposta, row, col);
    StampaMatrice(trasposta, col, row);

    printf("Prodotto riga colonna: %d", ProdottoRigaColonna(matrice, row, col, 1, 1));

    return 0;
}
