#include <stdio.h>

typedef enum {
    rosso,
    blu,
    verde

} Colors;

typedef char string[256];

int main () 
{
    Colors colore = rosso;
    colore++;
    return 0;
}