/*
 * Usuario.h
 *
 *  Created on: 03/05/2014
 *      Author: matias
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include "../../headers/dataTypes/Sexo.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/DTInfoLogueo.h"
#include "../../headers/dataTypes/DTConsulta.h"
#include "../../headers/dataTypes/DTReservaA.h"
#include "../../headers/dataTypes/DTMedico.h"
#include "../../headers/dataTypes/DTSocio.h"
#include "../../headers/dataTypes/DTUser.h"
#include <string>
using namespace std;

class Medico;
class Administrativo;
class Socio;

class Usuario {

private:
	string	nombre;
	string  apellido;
	string	ci;
	Sexo	sexo;
	Fecha	fechaNac;
	bool	activo;
	string	contrasenia;
	int 	edad;
	bool 	adminPorDefecto;
	bool	primerLogueo;

	//Links
	Administrativo*	administrativo;
	Medico*			medico;
	Socio*			socio;

public:
	//Creadoras
	Usuario(string nombre,string apellido,string ci,Sexo sexo,Fecha fechaNac,bool activo, int edad, bool adminPorDefecto, bool primerLogueo, set<Rol> roles);

	//Getters
	string	getNombre();
	string	getApellido();
	string	getCi();
	Sexo	getSexo();
	Fecha	getFechaNac();
	bool	getActivo();
	string	getContrasenia();
	int		getEdad();
	bool	getAdminPorDefecto();
	bool	getPrimerLogueo();

	Administrativo*	getAdministrativo();
	Medico*			getMedico();
	Socio*			getSocio();

	//Setters
	void	setNombre(string nombre);
	void	setApellido(string apellido);
	void	setCi(string ci);
	void	setSexo(Sexo sexo);
	void	setFechaNac(Fecha fechaNac);
	void	setActivo(bool activo);
	void	setContrasenia(string contrasenia);
	void	setEdad(int edad);
	void	setAdminPorDefecto(bool admin);
	void	setPrimerLogueo(bool logueo);

	//operaciones
	void activar();
	bool idAdminPorDefecto();
	bool isActivo();
	bool isPrimerLogueo();
	bool contraseniaCorrecta();
	DTUser getDatosCompletos();
	DTInfoLogueo getInfoLogueo();
	//DTSocio getDatosBasicos();
	set<DTConsulta> getHistorialConsultas();
	DTMedico getDatosMedico();
	set<DTReservaA> obtenerReservasActivas();
	set<DTConsulta> obtenerListaConsultas(); ///IMPORTANTE!!! DTConsultaDia
	void darBajarR(string codigo);
	void asistir(string ciMedico, Fecha fechaConsulta);
	set<Rol> getRoles();

	//Notificar
	set<DTMedico> getDatosPacientes();
	DTMedico		getDatosBasicos();

	~Usuario();
};


#endif /* USUARIO_H_ */
