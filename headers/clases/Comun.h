/*
 * Comun.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef COMUN_H_
#define COMUN_H_

#include <string>

#include "../../headers/clases/Consulta.h"

using namespace std;

class Comun: public Consulta{

private:
	
	Fecha fechaReserva;

public:
	
	//Creadoras
	Comun(	Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,
			Socio* socio,Fecha fechaReserva );

	//Getters
	Fecha	getFechaReserva();
	
	//Setters
	void	setFechaReserva(Fecha fechaReserva);

	//Operaciones
	void 	create(string ciSocio, string ciMedico,
							Fecha fechaConsulta, Fecha fechaReserva, bool asiste);
	bool			isActiva();
	TipoConsulta	getTipoConsulta();
	//DTReservaA		getDatosReserva();

	~Comun();
};


#endif /* COMUN_H_ */
