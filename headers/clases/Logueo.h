/*
 * Logueo.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef LOGUEO_H_
#define LOGUEO_H_

#include "Usuario.h"

class Logueo
{
private:
	static Logueo* instancia;

	Usuario* logueado;

	Logueo();

public:
	static Logueo* getInstance();

	void logIn(Usuario*);
	void logOut();

	Usuario* getUsuario();

	~Logueo();
};


#endif /* LOGUEO_H_ */
