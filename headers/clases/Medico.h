/*
 * Medico.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef MEDICO_H_
#define MEDICO_H_

#include "../../headers/clases/Consulta.h"
#include "../../headers/dataTypes/DTConsultaDia.h"
#include <string>
using namespace std;

class Usuario;
class Consulta;

class Medico
{
private:
	Usuario* usuario;

	set<Consulta*> consultas;

public:

	//operaciones
	Medico(Usuario* u);
	void linkearUsuario(Usuario* u);
	void crearLinkConsulta(Consulta* c);
	void destruirLinkConsulta(Consulta* c);
	DTMedico getDatosMedico();
	set<DTConsultaDia> obtenerListaConsultas();

};


#endif /* MEDICO_H_ */
