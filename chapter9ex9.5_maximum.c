#include <stdio.h>

	int high_water_mark(int valores[]) {
	int marca_alta;		/* valor actual más grande */
	int i;			/*indice dentro del array*/

	marca_alta = 0;

	for (i = 0; i < sizeof(valores); ++i) {
		if (valores[i] > marca_alta) {
			marca_alta = valores[i];
		}
	}

	return marca_alta;
}

int main(void) {
	int valores[] = { 3, 5, 7, 58, 910, 4, 64, 3 };

	printf("Resultado: %d\n", high_water_mark(valores));
	return 0;
}
