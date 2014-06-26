/*
 * Diagnostico.cpp
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#include "../../headers/clases/Diagnostico.h"
#include "../../headers/clases/ProblemaSalud.h"
#include "../../headers/clases/CategoriaPS.h"
#include "../../headers/clases/Tratamiento.h"

//Creadoras
Diagnostico::Diagnostico(string descripcion,  set<DTTratamiento> datosTratamientos): descripcion(descripcion) { }

//Getters
string	Diagnostico::getDescripcion() { return descripcion; }

//Setters
void	Diagnostico::setDescripcion() { this->descripcion=descripcion; }

//Negocio
DTDiagnostico
Diagnostico::getHistorial()
{
	set < string > descripcionesTratamientos =
			this->getHistorialTratamientos();
	string codigo1 = this->problemaSalud->getCodigoPS();
	string codigo2 = this->problemaSalud->getCategoriaPS()->getCodigoCPS();
	string codigo;

	codigo=codigo1+codigo2;
	//concat(codigo1, codigo2, codigo); //ni idea como es concat y no tengo
	//compilador. Aca quise decir concaten? codigo1 con codigo2
	//y guardalo en codigo.
	string etiqueta = this->problemaSalud->getEtiqueta();
	return DTDiagnostico(this->descripcion, codigo, etiqueta,
			descripcionesTratamientos);
}

set < string > Diagnostico::getHistorialTratamientos()
{
	set < string > descripcionesTratamientos;
	set<Tratamiento*>::iterator it;
	for (it = tratamientos.begin(); it != tratamientos.end(); ++it) {
		string descripcion = (*it)->getDescripcion();
		descripcionesTratamientos.insert(descripcion);
	}
	return descripcionesTratamientos;
}
