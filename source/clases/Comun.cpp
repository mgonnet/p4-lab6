/*
 * Comun.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../headers/Comun.h"
#include "../headers/Consulta.h"
#include "../headers/FechaHora.h"

Comun::Comun(int codigo, Fecha fechaComun, Hora horaComun, Fecha fechaReserva) : Consulta(codigo, fechaComun, horaComun,false), fechaReserva(fechaReserva){};

//Getters
	Fecha Comun::getFechaReserva(){
		return this->fechaReserva;
	};

//Setters
    void Comun::setFechaReserva(Fecha fechaReserva){
    	this->fechaReserva = fechaReserva;
    }





