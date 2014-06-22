/*
 * Diagnostico.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_

#include <string>
#include <set>

#include "../../headers/dataTypes/DTTratamiento.h"
#include "../../headers/dataTypes/DTDiagnostico.h"

class Diagnostico;
class Tratamiento;
class Farmacologico;
class Quirurgico;
class ProblemaSalud;

using namespace std;

class Diagnostico
{
private:
	string				descripcion;
	set<Tratamiento*>	tratamientos;
	ProblemaSalud*		problemaSalud;
	//Consulta*			consulta;	CUIDADO: ¿Es realmente necesario conocer la consulta en diagnostico?

public:
	//Creadores
	Diagnostico(string descripcion, set<DTTratamiento> datosTratamientos);

	//Getters
	string	getDescripcion();

	//Setters
	void	setDescripcion();

	//Negocio
	DTDiagnostico	getHistorial();
	void			linkearPS(ProblemaSalud ps);
};


#endif /* DIAGNOSTICO_H_ */
