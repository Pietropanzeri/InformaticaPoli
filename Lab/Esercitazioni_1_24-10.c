#include <stdio.h>

int main ()
{
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //Hello World


    printf("Hello World");
    

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //LEGGI DATO DA INPUT
    /*
    
    int eta = 0;
    printf("Quanti anni hai?");
    scanf("%d", &eta);
    printf("Hai %d anni", eta);
    
    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //SEI MAGGIORENNE?
    /*

    int eta = 0;
    printf("Quanti anni hai?");
    scanf("%d", &eta);
    if(eta >=  18)
        printf("Sei maggiorenne");
    else
        printf("Non sei maggiorenne");
    
    
    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //STAMPA UN NUM FINO ALL'ETA INSERITA
    /*

    int eta, cont = 0;
    printf("Enter a number: \n");
    scanf(" %d", &eta);
    while (cont <= eta){
        printf("%d\n", cont);
        cont++;
    }
    
    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //ELENCO
    /*

    for (int i = 0; i < 19; i++)
    {
        printf("%d", i);
    }

    */  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //CALCOLA MEDIA
    /*
    
    int val = 1, cont = 0;
    float tot = 0;

    while(val != 0)
    {
        val = 0;
        printf("Inserisci %d numero\n", cont+1);
        scanf("%d", &val);
        cont++;
        tot += val*1.0;
    }
    cont--;

    if(cont != 0)
        printf("La media e': %f", tot/(cont*1.0));
    else
        printf("Hai inserito 0 valori");
        
    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //TRIANGOLI
    /*
    
    int l1 = 0, l2 = 0, l3 = 0;

    printf("Inserisci il primo lato\n");
    scanf("%d", &l1);
    printf("Inserisci il secondo lato\n");
    scanf("%d", &l2);
    printf("Inserisci il terzo lato\n");
    scanf("%d", &l3);

    if(l1 >= l2+l3 || l2 >= l1+l3 || l3 >= l2+l1)
        printf("Dati non validi");
    else if(l1 == l2 && l2 == l3)
        printf("Equilatero");
    else if(l1 == l2 || l3 == l2 || l1 == l3)
        printf("Isoscele");
    else
        printf("Scaleno");    

    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //MIN MAX DI 10
    /*
    float array[10], tot = 0, min = _CRT_INT_MAX , max = 0;
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("Inserisci il %d valore\n", i+1);
        scanf("%f", &array[i]);
    }
    for (i = 0; i < 10; i++)
    {
        if(max < array[i])
            max = array[i];
        if (min > array[i])
            min = array[i];  
        tot += array[i];
    }
    printf("Il massimo e': %f\n", max);
    printf("Il minimo e': %f\n", min);
    printf("La media e' %f", tot/10);
    */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   //MIN MAX
   /*
   int val = 8, i, min = 0, max = 0;
   int cont = 0;
   float tot = 0;

    
    printf("Inserici il primo valore\n");
    scanf("%d", &val);
    //non ho controllato il primo valore
    min = val;
    cont++;

    while (val != 0)
    {
        
        printf("Inserici un valore\n");
        scanf("%d", &val);

        if(val > 0)
        {
            if (val < min)
                min = val;
            if (val > max)
                max = val;
            tot += val;
            cont++;
        }
    }
    
    printf("Il massimo e': %d\n", max);
    printf("Il minimo e': %d\n", min);
    printf("La media e' %f", tot/cont*1.0);   
    */
    return 0;
}