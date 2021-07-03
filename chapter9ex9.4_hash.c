#include <stdio.h>

	int array_hash(char chars[]) {
	int i;
	int hash = 0;

	for (i = 0; i < sizeof(chars); ++i) {
		hash += chars[i];
	}

	return(hash);
}

int main(void) {
	char char_array[] = { 'A', 'b', 'N', 'o' };

	printf("Resultado: %d\n", array_hash(char_array));

	return(0);
}
