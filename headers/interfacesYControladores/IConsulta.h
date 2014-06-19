/*
 * IConsulta.h
 *
 *  Created on: Jun 10, 2014
 *      Author: eacosta
 */

#ifndef ICONSULTA_H_
#define ICONSULTA_H_

#include <string>
#include <set>

#include "../dataTypes/DTReservaA.h"
#include "../dataTypes/DTHistorial.h"
#include "../dataTypes/DTConsulta.h"
#include "../dataTypes/DTCategoriaPS.h"
#include "../dataTypes/DTProblemaSalud.h"
#include "../dataTypes/FechaHora.h"
#include "../dataTypes/DTMedicamento.h"
#include "../dataTypes/TipoTratamiento.h"

using namespace std;

class IConsulta {
public:
	virtual const set<DTReservaA>& listarReservasActivas() = 0;
	virtual void darBajaReserva(string codigo) = 0;
	virtual void registrarConsultaComun(string ciMedico, string ciSocio, Fecha fechaConsulta) = 0;
	virtual void registrarConsultaEmergencia(string ciMedico, string ciSocio, string motivo, Fecha fechaConsulta) = 0;
	virtual DTHistorial obtenerHistorialPaciente(string ciSocio) = 0;
	virtual const set<DTConsulta>& obtenerListaConsultasDia() = 0;
	virtual void seleccionarConsulta(string ci) = 0;
	virtual const set<DTCategoriaPS>& obtenerListaCategoriaPS() = 0;
	virtual const set<DTProblemaSalud>& obtenerListaPSalud(string codigoCPS) = 0;
	virtual void seleccionarProblemaSalud(string codigoPS) = 0;
	virtual void agregarDescripcionDiagnostico(string descripcion) = 0;
	virtual void indicarTipoTratamiento(TipoTratamiento tipo) = 0;
	virtual void agregarDatosTQ(string descripcion, Fecha fecha) = 0;
	//virtual void agregarDatosTF(string descripcion, set<DTMedicamento> medicamentos) = 0; // CUIDADO: NO COMPILA Y NI SIQUIERA DICE EL ERROR
	virtual void altaTratamiento() = 0;
	virtual void confirmarAltaDiagnosticos() = 0;
	virtual ~IConsulta() {}
};




#endif /* ICONSULTA_H_ */
