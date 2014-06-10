/*
 * ProblemaSalud.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef PROBLEMASALUD_H_
#define PROBLEMASALUD_H_

#include <string>

using namespace std;

class ProblemaSalud
{
private:
	int		codigoPS;
	string	etiqueta;

public:
	//Creadores
	ProblemaSalud(int codigoPS,string etiqueta);

	//Getters
	int		getCodigoPS();
	string	getEtiqueta();

	//Setters
	void setCodigoPS(int codigoPS);
	void setEtiqueta(string etiqueta);
};


#endif /* PROBLEMASALUD_H_ */