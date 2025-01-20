#include <stdio.h>

#define Dim 5

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


int main(){
    
    int matrice[5][5] = {
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int order = MatriceBinaria(matrice);

    printf("%d", order);

    return 0;
}