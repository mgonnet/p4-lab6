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

class DTProblemaSalud;

using namespace std;

class DTReprEstandarizada
{
public:
	DTReprEstandarizada(string codigoCPS,string nombre,set<DTProblemaSalud> problemasSalud);

	const string& getCodigoCps() const;
	const string& getNombre() const;
	const set<DTProblemaSalud>& getProblemasSalud() const;

private:
	string					codigoCPS;
	string					nombre;
	set<DTProblemaSalud>	problemasSalud;
};

#endif /* DTREPRESTANDARIZADA_H_ */
