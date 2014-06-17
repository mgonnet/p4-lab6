/*
 * CConsulta.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef CCONSULTA_H_
#define CCONSULTA_H_

#include "IConsulta.h"
#include <string>
#include <set>
using namespace std;

#include "DTConsultaDia.h"
#include "DTConsulta.h"
#include "DTDiagnostico.h"
#include "TipoTratamiento.h"
#include "FechaHora.h"
#include "DTMedicamento.h"

class CConsulta : public IConsulta{
private:
	set<DTConsulta>& consultas;
	string ci;
	DTConsulta cons;
	string codigoCPS;
	string codigoPS;
	string descripcion;
	DTDiagnostico** diagnosticos;
	TipoTratamiento tipo;
	string descripcionT;
	Fecha fechaT;
	set<DTMedicamento>& medicamentos;

public:
	set<DTReservaA>& listarReservasActivas();
	void darBajaReserva(string codigo);
	void registrarConsultaComun(string ciMedico, string ciSocio, Fecha fechaConsulta);
	void registrarConsultaEmergencia(string ciMedico, string ciSocio, string motivo, Fecha fechaConsulta);
	DTHistorial obtenerHistorialPaciente(string ciSocio);
	const set<DTConsultaDia>& obtenerListaConsultasDia();
	void seleccionarConsulta(string ci);
	const set<DTCategoriaPS>& obtenerListaCategoriaPS();
	const set<DTProblemaSalud>& obtenerListaPSalud(string codigoCPS);
	void seleccionarProblemaSalud(string codigoPS);
	void agregarDescripcionDiagnostico(string descripcion);
	void indicarTipoTratamiento(TipoTratamiento tipo);
	void agregarDatosTQ(string descripcion, Fecha fecha);
	void agregarDatosTF(string descripcion, DTMedicamento** medicamentos);
	void altaTratamiento();
	void confirmarAltaDiagnosticos();
};


#endif /* CCONSULTA_H_ */
