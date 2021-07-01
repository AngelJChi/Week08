#include <stdio.h>

int main(){

	int contar_palabras(char frase[]) {
	static int str_idx    = 0;
	static int contador_de_palabras = 0;

	while (frase[str_idx] != '\0') {

		if ((frase[str_idx] == ' ') || (frase[str_idx] == '\n')) {
			++contador_de_palabras;
		}

		++str_idx;
		contar_palabras(frase);
	}

	return contador_de_palabras;
}

	int main(void) {
		int resultado;
		char line[100];

		printf("Ingresa un string: ");
		fgets(line, sizeof(line), stdin);

		resultado = contar_palabras(line);
		printf("Palabras encontradas %d\n", resultado);

	return(0);
}
