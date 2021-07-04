#include <stdio.h>

#define MINUTOS_POR_HORA (60)
#define MINUTOS_POR_DIA (MINUTOS_POR_HORA * 24)



int mapa_mensual[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0 };

/* define mapa de tiempo */

struct datetime {
	int year;
	int mes;
	int dia;
	int hora;
	int minuto;
};

/* prototipos */

int es_leap_year(int year);
int obtener_delta(int mes_de_inicio, int dia_de_inicio, int mes_final, int dia_final, int year);
int dia_delta(int inicio, int final, int mes);
int minutos_delta(int hora_de_inicio, int minuto_de_inicio, int hora_final, int minuto_final);



int main(void) {


	int total;

	/* fechas de inicio y final */

	struct datetime incio;
	inicio.year = 2006;
	mes.inicio = 12;
	day.inicio = 29;
	hora.inicio = 20;
	minuto.inicio = 3;

	struct datetime final;
	final.year = 2009;
	mes.final = 1;
	dia.final = 8;
	hora.final = 9;
	minuto.final = 20;


	int resultado;
	int este_year;



	if (final.year - incio.year > 1) {


		este_year = final.year - 1;
		while (este_year > inicio.year) {

			total += 365;

			if (es_leap_year(este_year)) {

				++total;
			}

			--este_year;
		}

		/* calcula fecha de inicio de year hasta la fecha de fin de year */
		resultado = obtener_delta(mes.inicio, dia.inicio, 12, 31, inicio.year);
		total += resultado;

		/* calcula 1 enero hasta la fecha de fin de year */
		resultado = obtener_delta(1, 1, mes.inicio, dia.final, final.year);
		total += resultado;

		/* convierte dias a minutos */
		total *= MINUTOS_POR_DIA;

		/* calcula minutos libres en le dia de inicio */
		total += minutos_delta(hora.inicio, minuto.inicio, 23, 59);

		/* calcula minutos libres en el dia final */
		total += minutos_delta(0, 0, hora.final, minuto.final);

	} else if (final.year - inicio.year == 1) {
		/* years adyacentes */

		/* calcula la fecha de inicio de year hasta la fecha de fin de year */
		resultado = obtener_delta(mes.inicio, dia.inicio, 12, 31, inicio.year);
		total += resultado;

		/* calcula  1 enero hasta la fecha de fin de year */
		resultado = obtener_delta(1, 1, mes.final, dia.final, final.year);
		total += resultado;

		/* convierte dias a minutos */
		total *= MINUTOS_POR_DIA;

		/* calcula minutos libres en el dia de inicio */
		total += minutos_delta(hora.inicio, minuto.inicio, 23, 59);

		/* calcula minutos libres en el dia final */
		total += minutes_delta(0, 0, hora.final, minuto.final);

	} else if (final.year == inicio.year) {
		/* mismo year */

		resultado = obtener_delta(mes.inicio, dia.inicio, mes.final, dia.final, inicio.year);
		total += resultado;

		/* convierte dias a minutos */
		total *= MINUTOS_POR_DIA;

		/* calcula los minutos libres en dia de inicio */
		total += minutos_delta(hora.inicio, minuto.inicio, 23, 59);

		/* calcula los minutos libres en el dia final */
		total += minutos_delta(0, 0, hora.final, minuto.final);

	} else {
		printf("ERROR: Problema indefinido.\n");
		printf("       puede que fecha.final es antes que la fecha.inicio?\n");
	}

	printf("\n** DELTA: %d minutos\n", total);
	return 0;
}

/**********************************************************************
 * es_leap_year(year)
 *
 * Determina si un year dado es un leap year (matematicamente).
 *
 * Returns true (1) if so, false (0) if not.
 **********************************************************************/

int es_leap_year(int year) {

	int flag = 0;


	if (year % 4 == 0) {
		flag = 1;


		if (year % 100 == 0) {
			if (year % 400 != 0) {
				flag = 0;
			}
		}
	}

	return flag;
}



int obtener_delta(int inicio_de_mes, int dia_de_inicio, int mes_final, int dia_final, int year) {

	int delta = 0;

	int resultado;
	int este_mes;

	if (mes_final - mes_de_inicio > 1) {


		este_mes = mes_final - 1;
		while (este_mes  > mes_de_inicio) {

			delta += mapa_mensual[este_mes];

			if (es_leap_year(year) && (este_mes == 2)) {
				++delta;

			}

			--este_mes;
		}

		/* calcula dias en el mes de inicio */
		resultado = (mapa_mensual[mes_de_inicio] - dia_de_inicio + 1);
		delta += resultado;

		/* dias del mes de finalizacion no. es apto para simplificar y agregar al total */
		delta += dia_final;

	} else if (mes_final - mes_de_inicio == 1) {
		/* los meses de inicio y finbal son adyacentes */

		/* calcula dias en el mes de inicio */
		result = (mapa_mensual[mes_de_inicio] - dia_de_inicio + 1);
		delta += resultado;

		/* dias del mes de finalizacion no. es apto para simplificar y agregar al total */
		delta += dia_final;

	} else if (mes_final == mes_de_inicio) {
		/* es el mismo mes */

		resultado = dia_delta(dia_de_inicio, dia_final, mes_de_inicio);
		delta = resultado;

	} else {
		printf("ERROR: nunca llegar a este codigo\n");
	}

	return delta;
}

/************************************************************************
 * dia_delta - obten una cantidad entre dos dias (dentro de un mes)	*
 *									*
 * Returns int numero de dias.						*
 ***********************************************************************/

int dia_delta(int inicio, int final, int mes) {

	int delta;

	/* asegurese que no esta fuera de los limites */
	if (end > mapa_mensual[mes]) {
		printf("ERROR: fuera de los limites (solo %d dias de este mes)\n", mapa_mensual[mes]);
	}


	delta = final - inicio + 1;

	return delta;
}

/************************************************************************
 * minutos_delta - obten la cantidad de minutos entre hora de 		*
 *inicio/minuto y la hora final/minuto. Esto es usado para calcular los *
 *minutos en los dias de inciio y finalizacion, los cuales no son dias 	*
 *completos								*
 ***********************************************************************/

int minutos_delta(int hora_de_inicio, int minuto_de_inicio, int hora_final, int minuto_final) {

	int delta;
	int esta_hora;
	int resultado;

	delta = 0;

	printf("DEBUG: minutos_delta(%d,%d,%d,%d)\n",
			hora_de_inicio, minuto_de_inicio, hora_final, minuto_final);

	/* asegurese que no está fuera de los limites */
	if ((hora_de_inciio < 0) || (hora_de_inicio > 23)) {
		printf("ERROR: %d fuera de los limites (la hora debe ser 0-23)\n", hora_de_inicio);
	}
	if ((hora_final < 0) || (hora_final > 23)) {
		printf("ERROR: %d fuera de los limites (la hora debe ser 0-23)\n", hora_final);
	}
	if ((minuto_de_inicio < 0) || (minuto_de_inicio > 59)) {
		printf("ERROR: %d fuera de los limites (el minuto deben ser 0-59)\n", minuto_de_inicio);
	}
	if ((minuto_final < 0) || (minuto_final > 59)) {
		printf("ERROR: %d fuera de los limites (el minuto debe ser 0-59)\n", minuto_final);
	}

	printf("DEBUG: incio=%d:%d final=%d:%d\n",
			hora_de_inicio, minuto_de_inicio, hora_final, minuto_final);

	if (hora_final - hora_de_inicio > 1) {
		/* hay horas completas en el medio, calulalas*/
		printf("DEBUG: llenando horas completas\n");

		esta_hora = hora_final - 1;
		while (esta_hora > hora_de_inicio) {
			printf("DEBUG: agregado 60 minutos por hora %d\n", esta_hora);
			delta += MINUTOS_POR_HORA;
			--esta_hora;
		}

		/* calculaminutos en la hora de incio */
		printf("DEBUG: agregando %d para la hora de inicio\n", MINUTOS_POR_HORA - minuto_de_inicio);
		delta += (MINUTOS_POR_HORA - minuto_de_inicio);

		/* calcula minutos en la hora de finalizacion */
		printf("DEBUG: agregando %d para la hora de finalizacion\n", minuto_final + 1);
		delta += (minuto_final + 1);

	} else if (hora_final - hora_de_inicio == 1) {
		/* estas son horas adyacentes */
		printf("DEBUG: horas adyacentes\n");

		/* calcula minutos en la hora de inicio */
		printf("DEBUG: ahrehando %d para la hora de inicio\n", MINUTOS_POR_HORA - minuto_de_inicio);
		delta += (MINUTOS_POR_HORA - minuto_de_inicio);

		/* calcula minutos en la hora de finalizacion */
		printf("DEBUG: agregando %d para la hora de finalizacion\n", minuto_final);
		delta += minuto_final;

	} else if (hora_final == _hora_de_inicio) {
		/* misma hora, solo calcula minutos */
		printf("DEBUG: dentro de la misma hroa\n");
		printf("DEBUG: agregando %d minutos\n", minuto-final - minuto_de_inicio + 1);
		delta = minuto_final - minuto_de_inicio + 1;

	} else {
		printf("ERROR: no deberia llegar ahi. es hora_final < hora_de_inicio?\n");
	}

	printf("DEBUG: minutos_delta() returns %d\n", delta);
	return delta;

}
