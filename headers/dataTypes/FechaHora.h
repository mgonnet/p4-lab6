/*
 * FechaHora.h
 *
 *  Created on: 03/05/2014
 *      Author: GRUPO_04
 */

#ifndef FECHAHORA_H_
#define FECHAHORA_H_

#include <time.h>

class Fecha
//DataType Fecha
{
private:
	int	dia;
	int	mes;
	int	anio;

public:
	//Creadores
	Fecha();
	Fecha(int dia,int mes,int anio);

	//Sobrecarga de operadores
	Fecha operator=(Fecha original);

	//Getters
	int getDia();
	int getMes();
	int getAnio();

	bool isCorrecta();
	bool esMenorQue(Fecha fecha);
};

class Hora
//DataType Hora
{
private:
	int	horas;
	int	minutos;

public:
	//Creadoras
	Hora(int horas,int minutos);

	//Getters
	int getHoras();
	int getMinutos();
};


#endif /* FECHAHORA_H_ */
