/*
 * CConsulta.cpp
 *
 *  Created on: 18/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/CConsulta.h"

set<DTReservaA>& CConsulta::listarReservasActivas() {}
void CConsulta::darBajaReserva(string codigo) {}
void CConsulta::registrarConsultaComun(string ciMedico, string ciSocio, Fecha fechaConsulta) {}
void CConsulta::registrarConsultaEmergencia(string ciMedico, string ciSocio, string motivo, Fecha fechaConsulta) {}
DTHistorial CConsulta::obtenerHistorialPaciente(string ciSocio) {}
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

set<DTMedico> CConsulta::listarMedicos()
{
	set<DTMedico> lista;
	return lista;
}

void CConsulta::reservarConsulta(string,Fecha,Hora){}

CConsulta::~CConsulta() {}


