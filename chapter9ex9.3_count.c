#include <stdio.h>

	int count(int number, int array[], int length) {


	if (length == 0) {
		return 0;
	}

	if (array[length - 1] == number) {

		return(1 + count(number, array, length - 1));
	} else {
		return(count(number, array, length - 1));
	}
}

int main(void) {
	int resultado;

	int lista_de_numeros1[] = { 45, 37, 45, 37, 45, 36, 45, 37, 45, 38 };
	printf("Quiero: 5\n");
	resultado = count(45, lista_de_numeros1, sizeof(lista_de_numeros1));
	printf("Tiene: %d\n", resultado);

	int lista_de_numeros2[] = { 3, 5, 7, 9, 3, 6, 8, 3, 4, 10, 3, 3, 3, 3, 3, 219437, 3 };
	printf("Quiero: 9\n");
	resultado = count(3, lista_de_numeros2, sizeof(lista_de_numeros2));
	printf("Tiene: %d\n", resultado);

	int lista_de_numeros3[] = { 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 5 };
	printf("Quiero: 10\n");
	resultado = count(5, lista_de_numeros3, sizeof(lista_de_numeros3));
	printf("Tiene: %d\n", resultado);

	int lista_de_numeros4[] = { 1, 8, 8, 8, 8, 8, 9, 8, 8, 8, 8, 8, 1 };
	printf("Quiero: 10\n");
	resultado = count(8, lista_de_numeros4, sizeof(lista_de_numeros4));
	printf("Tiene: %d\n", resultado);

	return(0);
}
