/*
 * StockAcciones.h
 *
 *  Created on: 14/06/2014
 *      Author: GRUPO_04
 */

#ifndef STOCKACCIONES_H_
#define STOCKACCIONES_H_

#include <set>
#include "Accion.h"

using namespace std;

class StockAcciones
{
private:
	StockAcciones();

	static StockAcciones*	instancia;
	set<Accion*> acciones;

public:
	static StockAcciones* getInstance();

	void	performActions(MedicoNotificable*,Parametro*);
	void	addAccion(Accion*);
	void	rmAccion(Accion*);

	~StockAcciones();
};


#endif /* STOCKACCIONES_H_ */
