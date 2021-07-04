#include <stdio.h>

int begins(char string1[], char string2[]) {
	int i = 0;

	while (1) {
		
		/*Si llegamos al final de la cadena de prueba sin devolver false, 
		*entonces los bits anteriores deben coincidir. Return true.*/

		if (string1[ i ] == '\0') {
			return(1);
		}

		/* Si encontramos una falta de coincidencia, return false. De lo contrario, sigue adelante. */
		if (string1[i] != string2[i]) {
			return(0);
		}

		++i;
	}
}

int main(void) {

	if (begins("fodo", "foobar")) {
		printf("coinciden!\n");
	} else {
		printf("no coinciden.\n");
	}

	return(0);
}







