/*
 * Comun.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef COMUN_H_
#define COMUN_H_

#include <string>

#include "../dataTypes/FechaHora.h"
#include "Consulta.h"

using namespace std;

class Comun: public Consulta{

private:
	
	Fecha fechaReserva;

public:
	
	//Creadoras
	Comun(int codigo,Fecha fechaComun,Hora horaComun, Fecha fechaReserva);

	//Getters
	Fecha	getFechaReserva();
	
	//Setters
	void	setFechaReserva(Fecha fechaReserva);

	//Operaciones
	void 	create(string ciSocio, string ciMedico,
							Fecha fechaConsulta, Fecha fechaReserva, bool asiste);
};


#endif /* COMUN_H_ */
