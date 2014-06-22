/*
 * Consulta.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Consulta.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/FechaSistema.h"
#include "../../headers/clases/Diagnostico.h"
#include "../../headers/clases/Medico.h"
#include "../../headers/clases/Socio.h"
#include <stdexcept>

int Consulta::ultimoCodigo = 0;


Consulta::Consulta( Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,Socio* socio):
							fechaConsulta(fechaConsulta),
							horaConsulta(horaConsulta),
							asistio(asistio),
							medico(medico),
							socio(socio)
{
	this->codigo = Consulta::ultimoCodigo++;
}

//Getters
int Consulta::getCodigo(){
	return this->codigo;
}
Fecha Consulta::getFechaConsulta(){
	return this->fechaConsulta;
}
Hora Consulta::getHoraConsulta(){
	return this->horaConsulta;
}
bool Consulta::getAsistioConsulta(){
	return this->asistio;
}

Medico* Consulta::getMedico(){}
Socio*	Consulta::getSocio(){}

//Setters
void Consulta::setCodigo(int codigo){
	this->codigo = codigo;
}
void Consulta::setFechaConsulta(Fecha fechaConsulta){
	this->fechaConsulta = fechaConsulta;
}
void Consulta::setHoraConsulta(Hora horaConsulta){
	this->horaConsulta = horaConsulta;
}
void Consulta::setAsistioConsulta(bool asistio){
	this->asistio = asistio;
}

//Operaciones

DTConsulta Consulta::getHistorialConsultas(){}

DTConsultaDia Consulta::obtenerConsultaDia(Socio* socio){
	FechaSistema* fechaSistema=FechaSistema::getInstance();
	return (DTConsultaDia(fechaSistema->getFechaSistema(),fechaSistema->getHoraSistema(),socio->getCISocio()));
}

bool	Consulta::esDeHoy(){
	FechaSistema* fechaSistema=FechaSistema::getInstance();
	return (fechaSistema->getFechaSistema().esMenorQue(fechaConsulta));
}

void	Consulta::altaDiagnosticos(Diagnostico* dt){
	this->diagnosticos.insert(dt);
}


void	Consulta::crearLinkSocio(Socio* soc){
	this->socio = soc;
}

void	Consulta::crearLinkMedico(Medico* med){
	this->medico = med;
}
void	Consulta::destruirLinkSocio(){
	delete this->socio;
	this->socio = NULL;
}

void	Consulta::destruirLinkMedico(){
	delete this->medico;
	this->medico = NULL;
}

DTMedico Consulta::getDatosSocio()
{
	return socio->getDatosBasicos();
}

Consulta::~Consulta(){}

