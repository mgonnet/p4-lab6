/*
 * Consulta.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <string>

#include "../../headers/dataTypes/FechaHora.h"

using namespace std;

class Consulta{

private:
	int		codigo;
	Fecha	fechaConsulta;
	Hora	horaConsulta;
	bool	asistio;

public:
	//Creadoras
	Consulta(int codigo,Fecha fechaConsulta,Hora horaConsulta,bool asistio);

	//Getters
	int	    getCodigo();
	Fecha	getFechaConsulta();
	Hora	getHoraConsulta();
	bool	AsistioConsulta();

	//Setters
	void	setCodigo(int codigo);
	void	setFechaConsulta(Fecha fechaConsulta);
	void	setHoraConsulta(Hora horaConsulta);
	void	setAsistioConsulta(bool asistio);
};


#endif /* CONSULTA_H_ */
