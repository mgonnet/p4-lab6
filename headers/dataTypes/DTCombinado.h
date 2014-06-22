/*
 * DTCombinado.h
 *
 *  Created on: 21/06/2014
 *      Author: eacosta
 */

#ifndef DTCOMBINADO_H_
#define DTCOMBINADO_H_

#include <set>
#include "DTCategoriaPS.h"
#include "DTProblemaSalud.h"

using namespace std;

class DTCombinado {
private:
	//DTCategoriaPS dtCps;
	string codigo;
	string etiqueta;
	set<DTProblemaSalud> setDtPs;
public:
	DTCombinado(string, string,set<DTProblemaSalud>);
	//DTCategoriaPS getDtCps() const;
	string getCodigo() const;
	string getEtiqueta() const;
	set<DTProblemaSalud> getSetDtps() const;
	bool operator<(DTCombinado) const;
};





#endif /* DTCOMBINADO_H_ */
