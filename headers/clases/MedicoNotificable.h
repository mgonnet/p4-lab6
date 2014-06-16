/*
 * MedicoNotificable.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef MEDICONOTIFICABLE_H_
#define MEDICONOTIFICABLE_H_

#include <set>

#include "Observer.h"
#include "StockAcciones.h"

class Subject;
class Mensaje;
class Parametro;
class Accion;

using namespace std;

class MedicoNotificable : public Observer
{
private:
	set<Mensaje*> buzon;

public:
	//MedicoNotificable() { }

	void	update(Subject*,Parametro*); // Heredada de Observer

	void	addMensaje(Mensaje*);

	set<Mensaje*>	getMensajes();

	virtual ~MedicoNotificable();
};


#endif /* MEDICONOTIFICABLE_H_ */
