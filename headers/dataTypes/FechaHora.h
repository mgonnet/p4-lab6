/*
 * FechaHora.h
 *
 *  Created on: 03/05/2014
 *      Author: GRUPO_04
 */

#ifndef FECHAHORA_H_
#define FECHAHORA_H_

#include <iostream>
#include <time.h>

using namespace std;

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
	int getDia() const;
	int getMes() const;
	int getAnio() const;

	bool isCorrecta();
	bool esMenorQue(Fecha fecha) const;
	bool esIgualQue(Fecha fecha);
	int	 calcularEdad();
};

class Hora
//DataType Hora
{
private:
	int	horas;
	int	minutos;

public:
	//Creadoras
	Hora();
	Hora(int horas,int minutos);

	//Getters
	int getHoras();
	int getMinutos();

	Hora operator=(Hora original);
};


std::ostream &operator<<( std::ostream &stream,Fecha imprimible);
std::ostream &operator<<( std::ostream &stream,Hora imprimible);

#endif /* FECHAHORA_H_ */

// pruebistico
