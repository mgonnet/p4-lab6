/*
 * ProblemaSalud.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef PROBLEMASALUD_H_
#define PROBLEMASALUD_H_

#include <string>
#include <set>

#include "../../headers/dataTypes/DTProblemaSalud.h"

class Diagnostico;
class CategoriaPS;

using namespace std;

class ProblemaSalud
{
private:
	string				codigoPS;
	string				etiqueta;
	set<Diagnostico*>	diagnosticos;
	CategoriaPS*		categoriaPS;

public:
	//Creadores
	ProblemaSalud(string codigoPS,string etiqueta);

	//Getters
	string	getCodigoPS();
	string	getEtiqueta();

	//Setters
	void setCodigoPS(string codigoPS);
	void setEtiqueta(string etiqueta);
	void setCategoriaPS(CategoriaPS*);

	void linkearDiagnostico(Diagnostico diag);
	DTProblemaSalud obtenerDTProblemaSalud();
};


#endif /* PROBLEMASALUD_H_ */
