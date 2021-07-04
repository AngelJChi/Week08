#include <stdio.h>
#include <string.h>

struct lista_de_correo {
	char nombre[50];		/* nombre del destinatario */
	int direccion;			/* dirección (número de casa) */
	char calle1[50];		/* nombre de la calle */
	char calle2[50];		/* información adicional de la dirección */
	char ciudad[50];		/* ciudad, pueblo */
	char estado[3];			/* dos letras para el estado */
	int cp;				/* codigo postal*/
};

void imprimir_lista(struct lista_de_correo *listac);

int main(void) {

	/* una lista que puede tener hasta 100 entradas */
	struct lista_de_correo lista[100];

	/* rellenar nuestra lista con algunos datos */

	strcpy(lista[0].nombee, "Johnatan Domiguez");
	lista[0].direccion = 123;
	strcpy(lista[0].calle1, "calle 34");
	strcpy(lista[0].ciudad, "Cancun");
	strcpy(lista[0].estado, "QR");
	lista[0].cp = 44132;

	strcpy(lista[1].nombre, "Jaime De la Torre");
	lista[1].direcion = 457;
	strcpy(lista[1].calle1, "Calle luciernagas");
	strcpy(lista[1].ciudad, "Monterrey");
	strcpy(lista[1].estado, "NL");
	lista[1].cp = 98137;

	strcpy(lista[2].nombre, "Jair Benitez");
	lista[2].direccion = 229;
	strcpy(lista[2].calle1, "Francisco Mujica");
	strcpy(lista[2].calle2, "Calle 56");
	strcpy(lista[2].ciudad, "Champeche");
	strcpy(lista[2].estado, "CA");
	lista[2].cp = 97149;

	imprimir_lista(lista);

	return(0);
}

void imprimir_lista(struct lista_de_correo *listac) {

	int i;				/* contador de bucle */

	printf("LISTA DE CORREO\n\n");

	for (i = 0; i < sizeof(listac); ++i) {
		if (strlen(listac[i].nombre) == 0) {
			continue;
		}

		printf("%s\n", listac[i].nombre);
		printf("%d %s\n", mlist[i].direccion, listac[i].calle1);
		if (strlen(listac[i].calle2)) {
			printf("%s\n", mlist[i].street2);
		}
		printf("%s, %s  %d\n\n", listac[i].ciudad, listac[i].estado, listac[i].cp);
	}
	return 0;
}
