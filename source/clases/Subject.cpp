/*
 * Subject.cpp
 *
 *  Created on: 11/06/2014
 *      Author: matias
 */

#include "../../headers/clases/Subject.h"
#include "../../headers/dataTypes/Parametro.h"
#include "../../headers/clases/Observer.h"

void	Subject::addObserver(Observer* observador)
{
	this->observadores.insert(observador);
}

void	Subject::rmObserver(Observer* observador)
{
	this->observadores.erase(observador);
}

void	Subject::notifyAll(Parametro* parametro)
{
	set<Observer*>::iterator it;
	for(it=this->observadores.begin();it!=this->observadores.end();++it)
	{
		(*it)->update(this,parametro);
	}
}
