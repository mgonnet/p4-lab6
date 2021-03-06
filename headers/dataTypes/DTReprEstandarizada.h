/*
 * DTReprEstandarizada.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTREPRESTANDARIZADA_H_
#define DTREPRESTANDARIZADA_H_

#include <string>
#include <set>
#include <iostream>

class DTProblemaSalud;

using namespace std;

class DTReprEstandarizada
{
public:
	DTReprEstandarizada(string codigoCPS,string nombre,set<DTProblemaSalud> problemasSalud);

	const string& getCodigoCps() const;
	const string& getNombre() const;
	set<DTProblemaSalud> getProblemasSalud() const;
	bool operator<(DTReprEstandarizada) const;

private:
	string					codigoCPS;
	string					nombre;
	set<DTProblemaSalud>	problemasSalud;
};

std::ostream &operator<<( std::ostream &stream,DTReprEstandarizada imprimible);

#endif /* DTREPRESTANDARIZADA_H_ */
