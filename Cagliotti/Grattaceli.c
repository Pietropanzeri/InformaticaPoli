#include <stdio.h>

int main ()
{
    int i, max = 0;
    int a[12] = {12,45,88,14,99,56,42,71,100,66,98,777};
    int b[12] = {1,0,0,0,0,0,0,0,0,0,0,0};

    for (i = 1; i < 12; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            b[i] = a[i];
        }      
        
    }
    return 0;
}