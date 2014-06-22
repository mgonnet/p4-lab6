/*
 * Medico.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Medico.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/Consulta.h"

Medico::Medico(Usuario* u):
	usuario(u)
{}

DTMedico Medico::getDatosMedico(){
	return this->usuario->getDatosMedico();
}

set<DTMedico> Medico::getDatosPacientes()
{
	set<DTMedico> datosPacientes;

	set<Consulta*>::iterator it;
	for( it = consultas.begin() ; it != consultas.end() ; ++it )
		datosPacientes.insert( (*it)->getDatosSocio() );

	return datosPacientes;
}
