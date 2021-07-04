#include <stdio.h>

	#include <stdio.h>

void reemplazar(char char_array[]) {
	int i;			/*indice dentro del array*/

	for (i = 0; i < sizeof(char_array); ++i) {
		if (char_array[i] == '-') {
			char_array[i] = '_';
		}
	}
}

int main(void) {
	int i;			/*indice dentro del array*/

	char characteres[] = { 'f', 'o', 'o', '-', 'b', '_', 'r' };
	reemmplazar(characteres);

	for (i = 0; i < sizeof(characteres); ++i) {
		printf("%c\n", characteres[i]);
	}

	return 0;
}
