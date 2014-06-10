/*
 * Emergencia.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */



#include "../headers/Emergencia.h"
#include "../headers/Consulta.h"
#include "../headers/FechaHora.h"

Emergencia::Emergencia(int codigo,Fecha fechaEmergencia,Hora horaEmergencia, string motivo) : Consulta(codigo, fechaEmergencia, horaEmergencia, true), motivo(motivo){};

//Getters
string	Emergencia::getMotivo(){
	return this->motivo;
}

//Setters
void Emergencia::setMotivo(string motivo){
	this->motivo = motivo;
}




