/*
 * AccionMensaje.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef ACCIONMENSAJE_H_
#define ACCIONMENSAJE_H_

#include "Accion.h"

class AccionMensaje : public Accion
{
	void performAction(MedicoNotificable*,Parametro*);

	virtual ~AccionMensaje();
};

#endif /* ACCIONMENSAJE_H_ */
