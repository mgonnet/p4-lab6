/*
 * Quirurgico.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef QUIRURGICO_H_
#define QUIRURGICO_H_

#include <string>

#include "Tratamiento.h"

class Fecha;
class Diagnostico;

using namespace std;

class Quirurgico: public Tratamiento{

private:
	Fecha fecha;

	void dummy() { }

public:
	
	//Creadoras
	Quirurgico(string descripcion, Fecha fecha, Diagnostico* diag);

	//Getters
	Fecha	getFecha();
	
	//Setters
	void	setFecha(Fecha fecha);

	//Destructor
	virtual ~Quirurgico();
};


#endif /* QUIRURGICO_H_ */
