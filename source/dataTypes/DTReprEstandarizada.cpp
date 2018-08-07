/*
 * DTReprEstandarizada.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/dataTypes/DTReprEstandarizada.h"
#include "../../headers/dataTypes/DTProblemaSalud.h"

DTReprEstandarizada::DTReprEstandarizada(string codigoCPS,string nombre,set<DTProblemaSalud> problemasSalud):
codigoCPS(codigoCPS),
nombre(nombre),
problemasSalud(problemasSalud) { }


const string& DTReprEstandarizada::getCodigoCps() const { return codigoCPS; }

const string& DTReprEstandarizada::getNombre() const { return nombre; }

set<DTProblemaSalud> DTReprEstandarizada::getProblemasSalud() const {
	return problemasSalud;
}

bool DTReprEstandarizada::operator<(DTReprEstandarizada dtrep) const { return ((*this).codigoCPS<(dtrep.getCodigoCps())); }

std::ostream &operator<<( std::ostream &stream,DTReprEstandarizada imprimible)
{
	stream	<< "Codigo Categoria: " << imprimible.getCodigoCps() << endl
			<< "Etiqueta: " << imprimible.getNombre() << endl;

	set<DTProblemaSalud> pS=imprimible.getProblemasSalud();
	set<DTProblemaSalud>::iterator it;
	for ( it = pS.begin() ; it != pS.end() ; ++it )
		cout << (*it);

	return (stream);
}
