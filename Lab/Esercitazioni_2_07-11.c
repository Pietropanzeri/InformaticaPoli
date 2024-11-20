#include <stdio.h>
#include <string.h>

int main () {

    //ES 4
    /*
    char str1[10];
    char str2[10];

    printf("Inserisci la prima parola\n");
    fgets(str1, sizeof(str1), stdin);

    printf("Inserisci la seconda parola\n");
    fgets(str2, sizeof(str2), stdin);

    printf("Lunghezze: ");
    printf("%d, ", strlen(str1));
    printf("%d\n", strlen(str2));

    printf("Le stringhe sono ");
    if(!strcmp(str1, str2))
        printf("uguali");
    else
        printf("diverse");
    */

   //ES5
    char str1[300];
    char str2[100];
    char str3[100];

    printf("Inserisci le parole\n");
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);
    fgets(str3, sizeof(str3), stdin);

    strcat(str1, str2);
    strcat(str1, str3);
    printf("\n%s\n", str1);
    printf("%d", strlen(str1));





    return 0;
}