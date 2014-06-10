/*
 * Tratamiento.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef TRATAMIENTO_H_
#define TRATAMIENTO_H_

#include <string>

using namespace std;

class Tratamiento{

private:
	
	string descripcion;

public:
	
	//Creadoras
	Tratamiento(string descripcion);

	//Getters
	string	getDescripcion();
	
	//Setters
	void	setDescripcion(string descripcion);
};


#endif /* TRATAMIENTO_H_ */