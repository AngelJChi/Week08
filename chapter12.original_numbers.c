/********************************************************
* un programa que te ayuda a mantener lalista de las 	*
* personas que has llamado desde tu casa. 		*
********************************************************/

#include <stdio.h>


int main(){

	struct lista_telefonica {
	char nombre[50];
	int direccion;
	char ciudad[50];
	char estado[3];
	int cp;
};

void imnprimir_lista(struct lista_telefonica *listatf);

int main(void) {


	struct lista_telefonica lista[100];



	strcpy(lista[0].nombre, "Alberto Perez");
	lista[0].direccion = Calle 22 por 19 y 24;
	strcpy(lista[0].ciudad, "Merida");
	strcpy(lista[0].estado, "YUC");
	lista[0].cp = 99454;

	strcpy(lista[1].nombre, "Joaquin Gutierrez");
	lista[1].direccion = Almendros 678, por calle 56 entre calle olivos;
	strcpy(lista[1].ciudad, "Guadalajara");
	strcpy(lista[1].estado, "JAL");
	lista[1].cp = 33689;

	strcpy(lista[1].nombre, "Margarita Chan");
        lista[1].direccion = Calle adolfo rosado salas entre 5av y 24 sur.;
        strcpy(lista[1].ciudad, "Chetumal");
        strcpy(lista[1].estado, "QROO");
        lista[1].cp = 77327;

	strcpy(lista[2].nombre, "Alejandro Rodiguez");
	lista[2].direccion = Calle flamingos entre 23 y 21.;
	strcpy(lista[2].ciudad, "Merida");
	strcpy(lista[2].estado, "YUC");
	lista[2].cp = 99123;

	imprimir_lista (lista);

	return 0;
}

void imprimir_lista(struct lista_telefonica *listatf) {

	int i;

	printf("LISTA TELEFONICA\n\n");

	for (i = 0; i < sizeof(listatf); ++i) {
		if (strlen(listatf[i].nombre) == 0) {
			continue;
		}

		printf("%s\n", listatf[i].nombre);
		printf("%d %s\n", listatf[i].direccion, listatf[i],ciudad);
		if (strlen(listatf[i].estado)) {
			printf("%s\n", lista[i].estado);
		}
		printf("%s, %s  %d\n\n", listatf[i].ciudad, listatf[i].estado, listatf[i].cp);
	}

}






	return 0;

}
