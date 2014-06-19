/*
 * FechaHora.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/FechaHora.h"
#include <stdexcept>

using namespace std;

// --------------- Fecha --------------- //
//Creadoras
Fecha::Fecha() :dia(0),mes(0),anio(0) { }
Fecha::Fecha(int dia,int mes,int anio): dia(dia),mes(mes),anio(anio){}

//Sobrecarga de operadores
Fecha Fecha::operator=(Fecha original)
{
	this->dia=original.dia;
	this->mes=original.mes;
	this->anio=original.anio;
	return (*this);
}
//Getters
int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

bool Fecha::isCorrecta(){
	int dia_a;
	int mes_a;
	int anio_a;
	struct tm *tiempo;
	time_t fecha_sistema;
    time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	anio_a=tiempo->tm_year + 1900;
	mes_a=tiempo->tm_mon + 1;
	dia_a=tiempo->tm_mday;
	if ((dia > 31) || (dia < 1)){
		return false;
	}
	if ((mes > 12) || mes < 1){
		return false;
	}
	if ((mes== 2) && (dia > 28)){
		return false;
	}

	if ((dia > 30) && ((mes == 4) || (mes == 6)
			|| (mes == 9)|| (mes == 11))){
		return false;
	}
	return (*this).esMenorQue(Fecha(dia_a,mes_a,anio_a));
}

bool Fecha::esMenorQue(Fecha fecha){
	return ((anio < fecha.getAnio()) 
		    || ((anio == fecha.getAnio()) && (mes < fecha.getMes()))
            || ((anio == fecha.getAnio()) && (mes == fecha.getMes()) && (dia <= fecha.getDia())));
}

int	Fecha::calcularEdad()
{
	/*FechaSistema* fSis=FechaSistema::getInstance();
	Fecha fechaSistema=fSis->getFecha();

	int edad=fechaSistema->getAnio() - this->getAnio();
	if ( this->getMes() >= fechaSistema->getMes() )
	{
		if ( !(this->getMes == fechaSistema->getMes() && this->getDia > fechaSistema->getDia()) ) {}
		edad--;
	}*/
}

// --------------- Hora --------------- //
//Creadoras
Hora::Hora(int horas,int minutos): horas(horas), minutos(minutos) { }

//Getters
int Hora::getHoras() { return horas; }
int Hora::getMinutos() { return minutos; }
