/*
 * Emergencia.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef EMERGENCIA_H_
#define EMERGENCIA_H_

#include <string>
using namespace std;

#include "../../headers/clases/Consulta.h"
#include "../../headers/clases/Medico.h"

class Emergencia: public Consulta{

private:
	string motivo;

public:
	//Creadoras
	Emergencia(	Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,
				Socio* socio,string motivo );

	//Getters
	string	getMotivo();

	//Setters
	void	setMotivo(string motivo);

	//Operaciones
	TipoConsulta	getTipoConsulta();
	DTReservaA		getDatosReserva();

	~Emergencia();
};


#endif /* EMERGENCIA_H_ */
