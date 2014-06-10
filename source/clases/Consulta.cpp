/*
 * Consulta.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */



#include "../../headers/clases/Consulta.h"

Consulta::Consulta(int codigo,Fecha fechaConsulta,Hora horaConsulta,bool asistio): codigo(codigo), fechaConsulta(fechaConsulta), horaConsulta(horaConsulta), asistio(asistio) { }

//Getters
	int Consulta::getCodigo(){
		return this->codigo;
	};
	Fecha Consulta::getFechaConsulta(){
		return this->fechaConsulta;
	};
    Hora Consulta::getHoraConsulta(){
    	return this->horaConsulta;
    }
    bool Consulta::AsistioConsulta(){
    	return this->asistio;
    };

//Setters
	void Consulta::setCodigo(int codigo){
		this->codigo = codigo;
	};
	void Consulta::setFechaConsulta(Fecha fechaConsulta){
		this->fechaConsulta = fechaConsulta;
	};
	void Consulta::setHoraConsulta(Hora horaConsulta){
		this->horaConsulta = horaConsulta;
	};
	void Consulta::setAsistioConsulta(bool asistio){
		this->asistio = asistio;
	};



