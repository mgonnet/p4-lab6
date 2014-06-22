/*
 * CConsulta.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef CCONSULTA_H_
#define CCONSULTA_H_

#include <stdexcept>

#include <string>
#include <set>
using namespace std;

#include "../../headers/interfacesYControladores/IConsulta.h"
#include "../../headers/dataTypes/DTInfoLogueo.h"
#include "../../headers/dataTypes/DTUser.h"
#include "../../headers/dataTypes/Rol.h"
#include "../../headers/dataTypes/DTConsultaDia.h"
#include "../../headers/dataTypes/DTConsulta.h"
#include "../../headers/dataTypes/DTDiagnostico.h"
#include "../../headers/dataTypes/TipoTratamiento.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTMedicamento.h"
#include "../../headers/dataTypes/DTMedico.h"
#include "../../headers/interfacesYControladores/Almacen.h"
#include "../../headers/clases/Consulta.h"
#include "../../headers/clases/Comun.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/Logueo.h"


class CConsulta : public IConsulta{
private:
	set<DTConsulta> consultas;
	string ci;
	DTConsulta cons; // CUIDADO: Constructor por defecto
	string codigoCPS;
	string codigoPS;
	string descripcion;
	DTDiagnostico** diagnosticos;
	TipoTratamiento tipo;
	string descripcionT;
	Fecha fechaT;
	set<DTMedicamento> medicamentos;

public:
	set<DTReservaA>& listarReservasActivas();
	void darBajaReserva(string codigo);
	void registrarConsultaComun(string ciMedico, string ciSocio, Fecha fechaConsulta);
	void registrarConsultaEmergencia(string ciMedico, string ciSocio, string motivo, Fecha fechaConsulta);
	DTHistorial obtenerHistorialPaciente(string ciSocio);
	const set<DTConsulta>& obtenerListaConsultasDia();
	void seleccionarConsulta(string ci);
	const set<DTCategoriaPS>& obtenerListaCategoriaPS();
	const set<DTProblemaSalud>& obtenerListaPSalud(string codigoCPS);
	void seleccionarProblemaSalud(string codigoPS);
	void agregarDescripcionDiagnostico(string descripcion);
	void indicarTipoTratamiento(TipoTratamiento tipo);
	void agregarDatosTQ(string descripcion, Fecha fecha);
	//void agregarDatosTF(string descripcion, set<DTMedicamento> medicamentos); // CUIDADO: NO COMPILA Y NI SIQUIERA DICE EL ERROR
	void altaTratamiento();
	void confirmarAltaDiagnosticos();
	set<DTMedico> listarMedicos();
	void reservarConsulta(string ciMedico,Fecha fechaConsulta,Hora horaConsulta);
	virtual ~CConsulta();
};


#endif /* CCONSULTA_H_ */
