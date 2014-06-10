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

using namespace std;

class DTReprEstandarizada
{
private:
	string					codigoCPS;
	string					nombre;
	set<DTProblemaSalud>	problemasSalud;
};

#endif /* DTREPRESTANDARIZADA_H_ */
