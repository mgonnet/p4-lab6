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
	this->crearLinkMedico(medico);
	this->crearLinkSocio(socio);
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

Medico* Consulta::getMedico(){return medico;}
Socio*	Consulta::getSocio(){return socio;}

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

DTConsulta Consulta::getHistorialConsulta()
{
	DTMedico datosMedico = this->medico->getDatosMedico();
	set<DTDiagnostico> datosDiagnosticos = this->getHistorialDiagnosticos();
	return DTConsulta(this->fechaConsulta, this->getTipoConsulta(), datosMedico, datosDiagnosticos);
}

DTConsultaDia Consulta::obtenerConsultaDia(Socio* socio){
	FechaSistema* fechaSistema=FechaSistema::getInstance();
	return (DTConsultaDia(fechaSistema->getFechaSistema(),fechaSistema->getHoraSistema(),socio->getCISocio()));
}

bool	Consulta::esDeHoy(){
	FechaSistema* fechaSistema=FechaSistema::getInstance();
	return (fechaSistema->getFechaSistema().esMenorQue(fechaConsulta));//CUIDADO: aca va es igual que
}

void	Consulta::altaDiagnosticos(Diagnostico* dt){
	this->diagnosticos.insert(dt);
}

void	Consulta::crearLinkSocio(Socio* soc){
	soc->crearLinkConsulta(this);
}

void	Consulta::crearLinkMedico(Medico* med){
	med->crearLinkConsulta(this);
}
void	Consulta::destruirLinkSocio(){
	socio->destruirLinkConsulta(this);
}

void	Consulta::destruirLinkMedico(){
	medico->destruirLinkConsulta(this);
}

set < DTDiagnostico > Consulta::getHistorialDiagnosticos()
{
	set<DTDiagnostico> datosDiagnosticos;
	set<Diagnostico*>::iterator it;
	for (it = diagnosticos.begin(); it != diagnosticos.end(); ++it) {
		DTDiagnostico datoDiagnostico = (*it)->getHistorial();
		datosDiagnosticos.insert(datoDiagnostico);
	}
	return datosDiagnosticos;
}

set<Diagnostico*> Consulta::getDiagnosticos() {
	return diagnosticos;
}

Consulta::~Consulta()
{
	this->destruirLinkMedico();
	this->destruirLinkSocio();

}

