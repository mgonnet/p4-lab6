/*
 * Socio.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef SOCIO_H_
#define SOCIO_H_

#include "../../headers/clases/Subject.h"
#include "../../headers/clases/Consulta.h"
#include "../../headers/dataTypes/TipoConsulta.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/clases/FechaSistema.h"




#include <string>
using namespace std;

class Usuario;
class Consulta;

class Socio : public Subject
{
private:
	Usuario* usuario;

	set<Consulta*> consultas;

public:
	void dummy() {}

	//operaciones
	Socio(Usuario* u);
	Socio(); //CUIDADO:
	string getCISocio();
	void linkearUsuario(Usuario* u);
	void darBajarR(string codigo);
	void asistir(string ciMedico, Fecha fechaConsulta);
	void destruirLinkConsulta(Consulta* c);
	void crearLinkConsulta(Consulta* c);
	set<DTReservaA> obtenerReservasActivas();
	set<DTConsulta> getHistorialConsultas();
	void buscarConsulta(DTConsulta c);
	Consulta* getConsulta(int codigo);

	virtual ~Socio();
};


#endif /* SOCIO_H_ */
