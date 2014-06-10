/*
 * Quirurgico.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */


#include "../headers/Quirurgico.h"

Quirurgico::Quirurgico(string descripcion, Fecha fecha):Tratamiento(descripcion),fecha(fecha){};

//Getters
	Fecha Quirurgico::getFecha(){
		return this->fecha;
	}

//Setters
	void Quirurgico::setFecha(Fecha fecha){
		this->fecha = fecha;
	}



