/*
 * DTProblemaSalud.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTPROBLEMASALUD_H_
#define DTPROBLEMASALUD_H_

#include <string>

using namespace std;

class DTProblemaSalud
{
private:
	string	codigo;
	string	etiqueta;

public:
	DTProblemaSalud(string codigo, string etiqueta);

	const string& getCodigo() const;
	const string& getEtiqueta() const;
	bool operator<(DTProblemaSalud) const;
};


#endif /* DTPROBLEMASALUD_H_ */
