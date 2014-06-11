/*
 * DTCategoriaPS.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTCATEGORIAPS_H_
#define DTCATEGORIAPS_H_

#include <string>

using namespace std;

class DTCategoriaPS
{
private:
	string	codigoCPS;
	string	etiqueta;

public:
	DTCategoriaPS(string codigoCPS,string etiqueta);

	string	getCodigoCPS();
	string	getEtiqueta();
};

#endif /* DTCATEGORIAPS_H_ */
