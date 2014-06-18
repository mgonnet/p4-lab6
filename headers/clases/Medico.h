/*
 * Medico.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef MEDICO_H_
#define MEDICO_H_

#include "../../headers/clases/Consulta.h"
#include "../../headers/datatypes/DTConsultaDia.h"
#include <string>
using namespace std;

class Usuario;

class Medico
{
public:


	//operaciones
	Medico create(Usuario u);
	void linkearUsuario(Usuario u);
	void crearLinkEmergencia();
	void destruirLinkConsulta(Consulta c);
	DTMedico getDatosMedico();
	set<DTConsultaDia> obtenerListaConsultas();

};


#endif /* MEDICO_H_ */
