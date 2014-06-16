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

	static int frutaMagica;
	static StockAcciones*	instancia;
	set<Accion*> acciones;

public:
	static StockAcciones* getInstance();

	void	performActions(MedicoNotificable*,Parametro*);
	void	addAction(Accion*);
	void	rmAction(Accion*);
};


#endif /* STOCKACCIONES_H_ */
