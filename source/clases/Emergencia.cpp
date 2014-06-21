/*
 * Emergencia.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Emergencia.h"



Emergencia::Emergencia(Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,
		Socio* socio,string motivo):
		Consulta(fechaConsulta,horaConsulta,asistio,medico,socio),
		motivo(motivo){}
//Getters
string	Emergencia::getMotivo(){
	return this->motivo;
}

//Setters
void Emergencia::setMotivo(string motivo){
	this->motivo = motivo;
}

TipoConsulta getTipoConsulta(){
    	return EMERGENCIA;
};

Emergencia::~Emergencia() {}

