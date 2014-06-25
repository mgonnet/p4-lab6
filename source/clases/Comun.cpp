/*
 * Comun.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Consulta.h"
#include "../../headers/clases/Comun.h"
#include "../../headers/clases/Medico.h"



Comun::Comun(Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,
		Socio* socio,Fecha fechaReserva):
		Consulta(fechaConsulta,horaConsulta,asistio,medico,socio),
		fechaReserva(fechaReserva){}

//Getters
Fecha Comun::getFechaReserva(){
	return this->fechaReserva;
}

//Setters
void Comun::setFechaReserva(Fecha fechaReserva){
	this->fechaReserva = fechaReserva;
}

//Operaciones
bool	Comun::isActiva(){
	FechaSistema* fSis=FechaSistema::getInstance();
	return (fSis->getFechaSistema().esMenorQue(this->getFechaConsulta()));
}
TipoConsulta	Comun::getTipoConsulta(){ return COMUN;}

DTReservaA	Comun::getDatosReserva(){ return DTReservaA(this->getCodigo(),this->getFechaConsulta(),this->getHoraConsulta(),this->getFechaReserva(),this->getMedico()->getDatosMedico()); }

Comun::~Comun(){}


