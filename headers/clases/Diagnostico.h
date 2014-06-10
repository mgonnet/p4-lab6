/*
 * Diagnostico.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_

#include <string>

using namespace std;

class Diagnostico
{
private:
	string descripcion;

public:
	//Creadores
	Diagnostico(string descripcion);

	//Getters
	string	getDescripcion();

	//Setters
	void	setDescripcion();
};


#endif /* DIAGNOSTICO_H_ */
