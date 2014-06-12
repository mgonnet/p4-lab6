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

class Mensaje;
class Parametro;
class Accion;

using namespace std;

class MedicoNotificable : public Observer
{
private:
	set<Mensaje*> buzon;
	set<Accion*> accionesUpdate;

public:
	//MedicoNotificable() { }

	void	addAccion(Accion*);
	void	rmAccion(Accion*);
	void	update(Parametro*); // Heredada de Observer

	void	addMensaje(Mensaje*);

	set<Mensaje*>	getMensajes();

	//virtual ~MedicoNotificable() { }
};


#endif /* MEDICONOTIFICABLE_H_ */
