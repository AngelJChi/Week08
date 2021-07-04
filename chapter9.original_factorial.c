#include <stdio.h>

int a, b, fact(int numero) {
	if (numero == 0) {
		return 1;
	}
	
        for (b = a; b > 1; b--){
    	fact = fact * b;

	return(numero * fact(numero - 1));
}

int main(void) {
	printf("fact(numero) es %d = %d\n", a, fact(numero));

	return 0;
}
