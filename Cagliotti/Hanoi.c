#include <stdio.h>


void hanoi(int n, char part, char dest, char pass){
	if(n != 0){
		hanoi(n-1, part, pass, dest);
		printf("sposta cercio da %c, a %c \n", part, dest);
		hanoi(n-1, pass, dest, part);
	}
}


int main () {

    hanoi(50, 'A', 'C', 'B');
    return 0;
}