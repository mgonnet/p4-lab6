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

#include "DTInfoLogueo.h"
#include "DTUser.h"
#include "Rol.h"
#include "Sexo.h"
#include "IUsuario.h"

class CUsuario : public IUsuario {
private:
	string ci;
	string nombre;
	string apellido;
	Fecha fNac;
	set<Rol> roles;
public:
	const set<DTInfoLogueo>& comienzoInicioSesion(string ci);
	bool ingresarContrasenia(string contrasenia);
	void asignarSesionUsuario();
	void crearContrasenia(string contrasenia);
	void cerrarSesion();
	bool iniciarAltaReactivacion(string ci);
	void ingresarDatos(string nombre, string apellido, Sexo sexo, Fecha fNac, const set<Rol>& roles);
	void altaUsuario();
	DTUser pedirDatos();
	void reactivarUsuario();
};



#endif /* CUSUARIO_H_ */
