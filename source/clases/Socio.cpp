/*
 * Socio.cpp
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#include "../../headers/clases/Socio.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/Consulta.h"
#include <set>

Socio::Socio(Usuario* u):
	usuario(u)
{}

string Socio::getCISocio() { return (this->usuario->getCi()); }

set<DTReservaA> Socio::obtenerReservasActivas()
{
	set<DTReservaA> reservasActivas;
	bool encontre = false;
	set<Consulta*>::iterator it;
	FechaSistema* fSistema = FechaSistema::getInstance();
	for( it=consultas.begin() ; it != consultas.end() && !encontre ; ++it )

		if (fSistema->getFechaSistema().esMenorQue((*it)->getFechaConsulta()))
			{
				TipoConsulta tipo = (*it)->getTipoConsulta();
				if (tipo == COMUN)
				{
					//DTReservaA dtRA = (*it)->getDatosReserva();
					reservasActivas.insert((*it)->getDatosReserva());
				}
			}
	return reservasActivas;
}


void Socio::destruirLinkConsulta(Consulta* c)
{
	consultas.erase(c);
}

void Socio::crearLinkConsulta(Consulta* c)
{
	consultas.insert(c);
}

Consulta* Socio::getConsulta(int codigo)
{
	bool encontre = false;
	Consulta* consultaRetorno;
	set<Consulta*>::iterator it;
	for( it=consultas.begin() ; it != consultas.end() && !encontre ; ++it )
			if ((*it)->getCodigo() == codigo)
			{
				encontre = true;
				consultaRetorno = (*it);
			}
	return consultaRetorno;
}


Socio::~Socio() {}
