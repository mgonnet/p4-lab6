/*
 * Quirurgico.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef QUIRURGICO_H_
#define QUIRURGICO_H_

#include <string>

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/Tratamiento.h"

using namespace std;

class Quirurgico: public Tratamiento{

private:
	
	Fecha fecha;

public:
	
	//Creadoras
	Quirurgico(string descripcion, Fecha fecha);

	//Getters
	Fecha	getFecha();
	
	//Setters
	void	setFecha(Fecha fecha);
};


#endif /* QUIRURGICO_H_ */
