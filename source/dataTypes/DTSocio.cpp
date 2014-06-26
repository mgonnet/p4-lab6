/*
 * DTSocio.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTSocio.h"

DTSocio::DTSocio(string ci, string nombre, string apellido, Fecha fechaNac) :
ci(ci), nombre(nombre), apellido(apellido), fechaNac(fechaNac) {
}

const string& DTSocio::getCi() const {return ci;}
const string& DTSocio::getNombre() const {return nombre;}
const string& DTSocio::getApellido() const {return apellido;}
const Fecha& DTSocio::getFechaNac() const { return fechaNac; }

std::ostream &operator<<( std::ostream &stream,DTSocio imprimible) {
stream << "CI: " << imprimible.getCi() << endl
<< "Nombre: " << imprimible.getNombre() << endl
<< "Apellido: " << imprimible.getApellido() << endl
<< "Fecha de Nacimiento: " <<imprimible.getFechaNac() << endl;
return (stream);
}
