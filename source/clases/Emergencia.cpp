/*
 * Emergencia.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */



#include "../../headers/clases/Emergencia.h"
#include "../../headers/clases/Consulta.h"
#include "../../headers/dataTypes/FechaHora.h"

Emergencia::Emergencia(int codigo,Fecha fechaEmergencia,Hora horaEmergencia, string motivo) : Consulta(codigo, fechaEmergencia, horaEmergencia, true), motivo(motivo){};

//Getters
string	Emergencia::getMotivo(){
	return this->motivo;
}

//Setters
void Emergencia::setMotivo(string motivo){
	this->motivo = motivo;
}




