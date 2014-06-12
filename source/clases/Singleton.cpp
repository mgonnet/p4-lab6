/*
 * Singleton.cpp
 *
 *  Created on: 12/06/2014
 *      Author: matias
 */

#include <stdio.h>

#include "../../headers/clases/Singleton.h"


Singleton::Singleton() { }

Singleton* Singleton::getInstance()
{
	if(Singleton::instancia==NULL)
		Singleton::instancia=new Singleton();

	return Singleton::instancia;
}

Singleton::~Singleton() { }



