/*
 * Consulta.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <string>

#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTReservaA.h"
#include "../../headers/dataTypes/DTConsulta.h"
#include "../../headers/dataTypes/TipoConsulta.h"

using namespace std;

class Consulta{

private:
	int		codigo;
	Fecha	fechaConsulta;
	Hora	horaConsulta;
	bool	asistio;

public:
	//Creadoras
	Consulta(int codigo,Fecha fechaConsulta,Hora horaConsulta,bool asistio);

	//Getters
	int	    getCodigo();
	Fecha	getFechaConsulta();
	Hora	getHoraConsulta();
	bool	AsistioConsulta();

	//Setters
	void	setCodigo(int codigo);
	void	setFechaConsulta(Fecha fechaConsulta);
	void	setHoraConsulta(Hora horaConsulta);
	void	setAsistioConsulta(bool asistio);

	//Operaciones
	DTReservaA		getDatosReserva();
	DTConsulta		getHistorialConsultas();
	TipoConsulta	getTipoConsulta();
	DTConsulta		obtenerConsultaDia(); //aca deberia ser DTConsultaDia
	bool			isActiva();
	bool			esDeHoy();
	void 			altaDiagnosticos();
	void			crearLinkSocio();
	void			crearLinkMedico();
	void 			destruirLinkSocio();
	void 			destruirLinkMedico();
	void 			generarCodigoConsulta();

};


#endif /* CONSULTA_H_ */
