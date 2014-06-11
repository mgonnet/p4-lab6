/*
 * Emergencia.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef EMERGENCIA_H_
#define EMERGENCIA_H_

#include <string>

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/Consulta.h"

using namespace std;

class Emergencia: public Consulta{

private:
	
	string motivo;

public:
	
	//Creadoras
	Emergencia(int codigo,Fecha fechaEmergencia,Hora horaEmergencia,string motivo);

	//Getters
	string	getMotivo();
	
	//Setters
	void	setMotivo(string motivo);

	//Operaciones
		void 	create(string ciSocio, string ciMedico,
								Fecha fechaConsulta, string motivo, bool asiste);
};


#endif /* EMERGENCIA_H_ */
