/*
 * Factory.cpp
 *
 *  Created on: 17/06/2014
 *      Author: eacosta
 */

#include "../../headers/interfacesYControladores/Factory.h"
#include "../../headers/interfacesYControladores/CUsuario.h"
#include "../../headers/interfacesYControladores/CDiagnostico.h"
#include "../../headers/interfacesYControladores/CConsulta.h"

IUsuario* Factory::getIUsuario() { return new CUsuario(); }
IDiagnostico* Factory::getIDiagnostico() { return new CDiagnostico(); }
// IConsulta* Factory::getIConsulta() { return new CConsulta(); } // CUIDADO: Es un viaje incluir CConsulta, prova compilar


