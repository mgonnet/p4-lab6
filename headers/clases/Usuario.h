/*
 * Usuario.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>

#include "../../headers/dataTypes/Sexo.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTInfoLogueo.h"

using namespace std;

class Usuario
{
private:
	string	nombre;
	string	ci;
	Sexo	sexo;
	Fecha	fechaNac;
	bool	activo;
	string	contrasenia;
	bool	primerLogueo;
	bool	adminPorDefecto;

public:
	//Creadoras
	Usuario(string nombre,string ci,Sexo sexo,Fecha fechaNac,bool activo);

	//Getters
	string	getNombre();
	string	getCi();
	Sexo	getSexo();
	Fecha	getFechaNac();
	bool	isActivo();

	//Setters
	void	setNombre(string nombre);
	void	setCi(string ci);
	void	setSexo(Sexo sexo);
	void	setFechaNac(Fecha fechaNac);
	void	setActivo(bool activo);
	void	setContrasenia(string contrasenia);

	//Negocio
	DTInfoLogueo	getInfoLogueo();
};


#endif /* USUARIO_H_ */
