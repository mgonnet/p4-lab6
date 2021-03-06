/*
 * CConsulta.cpp
 *
 *  Created on: 18/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/CConsulta.h"
#include <set>
#include <stdexcept>


void CConsulta::registrarConsultaComun(string ciMedico, string ciSocio, Fecha fechaConsulta) {}
void CConsulta::registrarConsultaEmergencia(string ciMedico, string ciSocio, string motivo, Fecha fechaConsulta) {}

DTHistorial CConsulta::obtenerHistorialPaciente(string ciSocio) {
	Almacen* alm = Almacen::getInstance();
	Usuario* usuario = alm->findUsuario(ciSocio);
	/*Ac? habr?a que tirar una excepcion si usuario==null que te diga que
el usuario con cedula ci no pertenece al sistema, o se puede asumir
que la cedula pertenece al sistema?*/
	DTSocio datosSocio = usuario->getDatosBasicos();
	set<DTConsulta> datosConsultas = usuario->getHistorialConsultas();
	return DTHistorial(datosSocio, datosConsultas);
}

const set<DTConsulta>& CConsulta::obtenerListaConsultasDia() {}
void CConsulta::seleccionarConsulta(string ci) {}
const set<DTCategoriaPS>& CConsulta::obtenerListaCategoriaPS() {}
const set<DTProblemaSalud>& CConsulta::obtenerListaPSalud(string codigoCPS) {}
void CConsulta::seleccionarProblemaSalud(string codigoPS) {}
void CConsulta::agregarDescripcionDiagnostico(string descripcion) {}
void CConsulta::indicarTipoTratamiento(TipoTratamiento tipo) {}
void CConsulta::agregarDatosTQ(string descripcion, Fecha fecha) {}
//void agregarDatosTF(string descripcion, set<DTMedicamento> medicamentos) {}
void CConsulta::altaTratamiento() {}
void CConsulta::confirmarAltaDiagnosticos() {}

set<DTMedico> CConsulta::listarMedicos(){

	set<DTMedico> datosMedicos;
	Usuario* usuario;
	Almacen* alm=Almacen::getInstance();
	set<Usuario*> usuarios = alm->getUsuarios();
	set<Usuario*>::iterator it;
	for ( it = usuarios.begin() ; it != usuarios.end(); ++it ){
		set<Rol> roles = (*it)->getRoles();
		if ( roles.find(MEDICO) != roles.end())
		{	usuario = (*it);
		datosMedicos.insert(usuario->getDatosMedico());
		}
	}
	return datosMedicos;
}

void CConsulta::reservarConsulta(string ciMedico,Fecha fechaConsulta,Hora horaConsulta){

	bool encontre = false;
	Usuario* usuario;
	Almacen* alm=Almacen::getInstance();
	set<Usuario*> usuarios = alm->getUsuarios();
	set<Usuario*>::iterator it;
	for( it=usuarios.begin() ; it != usuarios.end() && !encontre ; ++it )
		if ( (*it)->getCi() == ciMedico )
		{
			encontre = true;
			usuario = (*it);
		}

	if(!encontre) throw invalid_argument("En IUsuario::pedirDatos: No existe medico con la ci indicada");

	Logueo* log=Logueo::getInstance();
	Usuario* u=log->getUsuario();
	set<Rol> roles = (u)->getRoles();

	if (roles.find(SOCIO) == roles.end()) throw invalid_argument("No hay un SOCIO logueado actualmente.");

	FechaSistema* fSis=FechaSistema::getInstance();
	new Comun(fechaConsulta,horaConsulta,false,usuario->getMedico(),u->getSocio(),fSis->getFechaSistema());
	//se genera una nueva instacia de Consulta Comun linkeada con sus respectivos medico y socio
}

set<DTReservaA> CConsulta::listarReservasActivas(){

	Logueo* log=Logueo::getInstance();
	Usuario* u=log->getUsuario();
	set<Rol> roles = (u)->getRoles();

	if (roles.find(SOCIO) == roles.end()) throw invalid_argument("No hay un SOCIO logueado actualmente.");

	return u->obtenerReservasActivas();
}

void CConsulta::darBajaReserva(int codigo)
{
	Consulta* cons;
	Logueo* log=Logueo::getInstance();
	Usuario* u=log->getUsuario();
	set<Rol> roles = (u)->getRoles();

	if (roles.find(SOCIO) == roles.end()) throw invalid_argument("No hay un SOCIO logueado actualmente.");

	cons = u->getSocio()->getConsulta(codigo);
	delete cons;
}

CConsulta::~CConsulta() {}


