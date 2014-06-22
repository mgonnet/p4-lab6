/*
 * Consulta.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <string>
#include <set>
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTConsulta.h"
#include "../../headers/dataTypes/DTReservaA.h"
#include "../../headers/dataTypes/DTConsultaDia.h"
#include "../../headers/dataTypes/DTReservaA.h"
#include "../../headers/dataTypes/TipoConsulta.h"
#include "../../headers/clases/FechaSistema.h"

class Diagnostico;
class Usuario;
class Medico;
class Socio;

using namespace std;

class Consulta{

private:
	static int ultimoCodigo;
	int 	codigo;
	Fecha	fechaConsulta;
	Hora	horaConsulta;
	bool	asistio;

	//Links
	set<Diagnostico*> diagnosticos;
	Medico* medico;
	Socio* socio;

public:
	//Creadoras
	Consulta( Fecha fechaConsulta,Hora horaConsulta,bool asistio,Medico* medico,Socio* socio);

	//Getters
	int	    getCodigo();
	Fecha	getFechaConsulta();
	Hora	getHoraConsulta();
	Medico* getMedico();
	Socio*  getSocio();

	//Setters
	void	setCodigo(int codigo);
	void	setFechaConsulta(Fecha fechaConsulta);
	void	setHoraConsulta(Hora horaConsulta);
	void	setAsistioConsulta(bool asistio);

	//Negocio

	virtual 		TipoConsulta getTipoConsulta()=0;
	virtual			DTReservaA getDatosReserva()=0;
	bool			getAsistioConsulta();
	DTConsulta		getHistorialConsultas();
	DTConsultaDia	obtenerConsultaDia(Socio* socio);
	bool			esDeHoy();
	void 			altaDiagnosticos(Diagnostico* dt);
	void			crearLinkSocio(Socio* socio);
	void			crearLinkMedico(Medico* medico);
	void 			destruirLinkSocio();
	void 			destruirLinkMedico();

	virtual ~Consulta();

};


#endif /* CONSULTA_H_ */
