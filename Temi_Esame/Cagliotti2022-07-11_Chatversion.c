#include <stdio.h>
#include <stdlib.h>

#define N 5 // Dimensione della matrice

int findLargestSquare(int matrix[N][N]) {
    int largestSquare[N][N]; // Matrice ausiliaria per calcolare le dimensioni dei quadrati
    int maxSize = 0; // Variabile per memorizzare la dimensione massima trovata

    // Inizializza la matrice ausiliaria
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || j == 0) {
                // Per la prima riga e la prima colonna, il valore è lo stesso della matrice originale
                largestSquare[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                // Trova il minimo tra i tre valori vicini
                int minVal = largestSquare[i-1][j]; // Sopra
                if (largestSquare[i][j-1] < minVal) {
                    minVal = largestSquare[i][j-1]; // Sinistra
                }
                if (largestSquare[i-1][j-1] < minVal) {
                    minVal = largestSquare[i-1][j-1]; // Diagonale superiore sinistra
                }

                // Calcola il valore attuale aggiungendo 1
                largestSquare[i][j] = 1 + minVal;
            } else {
                largestSquare[i][j] = 0; // Se è 0, non può far parte di un quadrato
            }

            // Aggiorna la dimensione massima se necessario
            if (largestSquare[i][j] > maxSize) {
                maxSize = largestSquare[i][j];
            }
        }
    }

    return maxSize;
}

int main() {
    // Dichiarazione della matrice binaria
    int matrix[N][N] = {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1}
    };

    // Trova l'ordine della più grande sottomatrice quadrata
    int maxSquare = findLargestSquare(matrix);

    // Stampa il risultato
    printf("L'ordine della più grande sottomatrice quadrata di soli 1 è: %d\n", maxSquare);

    return 0;
}
