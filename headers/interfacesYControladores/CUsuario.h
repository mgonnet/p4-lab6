/*
 * CUsuario.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef CUSUARIO_H_
#define CUSUARIO_H_


#include <string>
using namespace std;

#include "../../headers/dataTypes/DTInfoLogueo.h"
#include "../../headers/dataTypes/DTUser.h"
#include "../../headers/dataTypes/Rol.h"
#include "../../headers/dataTypes/Sexo.h"
#include "../../headers/interfacesYControladores/IUsuario.h"
#include "../../headers/clases/Usuario.h"

class CUsuario : public IUsuario {
private:
	string ci;
	string nombre;
	string apellido;
	Sexo sexo;
	Fecha fNac;
	int edad;
	set<Rol> roles;

	//Memoria muy interna del controlador
	Usuario* logueante;

public:
	CUsuario();

	DTInfoLogueo comienzoInicioSesion(string ci);
	bool ingresarContrasenia(string contrasenia);
	void asignarSesionUsuario();
	void crearContrasenia(string contrasenia);
	void cerrarSesion();
	bool iniciarAltaReactivacion(string ci);
	void ingresarDatos(string nombre, string apellido, Sexo sexo, Fecha fNac, const set<Rol>& roles);
	void altaUsuario();
	DTUser pedirDatos();
	void reactivarUsuario();

	void crearAdminPorDefecto();
	set<Rol> rolesDelLogueado();

	~CUsuario() {}
};



#endif /* CUSUARIO_H_ */
