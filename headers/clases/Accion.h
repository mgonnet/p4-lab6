/*
 * Accion.h
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#ifndef ACCION_H_
#define ACCION_H_

class MedicoNotificable;

class Parametro;

class Accion
{
public:
	virtual void performAction(MedicoNotificable*,Parametro*)=0;

	virtual ~Accion();
};


#endif /* ACCION_H_ */
