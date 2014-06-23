/*
 * DTUsuarioAR.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTUsuarioAR.h"

DTUsuarioAR::DTUsuarioAR(string nombre, string apellido, string ci, int edad, bool activo, set<DTLineaRegistro> registros):
nombre(nombre), apellido(apellido), ci(ci), edad(edad), activo(activo), registros(registros) {}

bool DTUsuarioAR::isActivo() const {
	return activo;
}

const string& DTUsuarioAR::getApellido() const {
	return apellido;
}

const string& DTUsuarioAR::getCi() const {
	return ci;
}

int DTUsuarioAR::getEdad() const {
	return edad;
}

const string& DTUsuarioAR::getNombre() const {
	return nombre;
}

set<DTLineaRegistro> DTUsuarioAR::getRegistros(){
	return registros;
}

bool DTUsuarioAR::operator<(DTUsuarioAR dtu) const {
	return(this->ci < dtu.getCi());
}

std::ostream &operator<<( std::ostream &stream,DTUsuarioAR imprimible)
{
	string estado;
	stream	<< "Nombre: " << imprimible.getNombre() << endl
			<< "Apellido: " << imprimible.getApellido() << endl
			<< "CI: " << imprimible.getCi() << endl
	<< "Edad: " << imprimible.getEdad() << endl;
	if (imprimible.isActivo()) {
		estado = "Activo";
	} else {
		estado = "Inactivo";
	}
	stream << "Estado de Actividad: " << estado << endl
	<< "Registros de Alta/Reactivacion: " << endl;
	set<DTLineaRegistro>::iterator it;
	set<DTLineaRegistro> lineas=imprimible.getRegistros();
	for (it = lineas.begin(); it != lineas.end(); ++it)
		stream << (*it) << endl;
	return (stream);
}
