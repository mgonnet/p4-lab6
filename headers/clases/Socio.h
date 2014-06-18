/*
 * Socio.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef SOCIO_H_
#define SOCIO_H_

#include "../../headers/clases/Consulta.h"
#include <string>
using namespace std;

class Usuario;

class Socio
{

public:


	//operaciones
	Socio create(Usuario u);
	void linkearUsuario(Usuario u);
	void darBajarR(string codigo);
	void asistir(string ciMedico, Fecha fechaConsulta);
	void destruirLinkConsulta(Consulta c);
	void crearLinkEmergencia();
	set<DTReservaA> obtenerReservasActivas();
	set<DTConsulta> getHistorialConsultas();
	void buscarConsulta(DTConsulta c);

};


#endif /* SOCIO_H_ */
