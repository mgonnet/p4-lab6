/*
 * StockAcciones.cpp
 *
 *  Created on: 14/06/2014
 *      Author: GRUPO_04
 */

#include <stdio.h>

#include "../../headers/clases/StockAcciones.h"

StockAcciones* StockAcciones::instancia=NULL;

StockAcciones::StockAcciones()
{
	StockAcciones::instancia=NULL;
}

StockAcciones* StockAcciones::getInstance()
{
	if(StockAcciones::instancia==NULL)
		StockAcciones::instancia=new StockAcciones();

	return StockAcciones::instancia;
}

void	StockAcciones::performActions(MedicoNotificable* medico,Parametro* param)
{
	set<Accion*>::iterator it;

	for(it=acciones.begin();it!=acciones.end();++it)
	{
		(*it)->performAction(medico,param);
	}

}

void	StockAcciones::addAccion(Accion* accion)
{
	acciones.insert(accion);
}

void	StockAcciones::rmAccion(Accion* accion)
{
	acciones.erase(accion);
}

StockAcciones::~StockAcciones()
{
	StockAcciones::instancia=NULL;
	set<Accion*>::iterator it;
	for(it=acciones.begin();it!=acciones.end();++it)
		delete (*it);
}
