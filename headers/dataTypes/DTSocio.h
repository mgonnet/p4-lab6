/*
 * DTSocio.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTSOCIO_H_
#define DTSOCIO_H_

#include <string>

#include "FechaHora.h"

using namespace std;

class DTSocio
{
private:
	string	ci;
	string	nombre;
	string	apellido;
	Fecha	fechaNac;
public:
	DTSocio(string ci, string nombre, string apellido, Fecha fechaNac);
	const string& getCi() const;
	const string& getNombre() const;
	const string& getApellido() const;
	const Fecha& getFechaNac() const;
};

std::ostream &operator<<(std::ostream &stream, DTSocio imprimible);

#endif /* DTSOCIO_H_ */
