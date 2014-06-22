/*
 * IUsuario.h
 *
 *  Created on: Jun 10, 2014
 *      Author: eacosta
 */

#ifndef IUSUARIO_H_
#define IUSUARIO_H_

#include <string>
#include <set>
#include "../../headers/dataTypes/DTInfoLogueo.h"
#include "../../headers/dataTypes/Sexo.h"
#include "../../headers/dataTypes/FechaHora.h"
#include "../../headers/dataTypes/Rol.h"
#include "../../headers/dataTypes/DTUser.h"

using namespace std;

class IUsuario {
public:
	virtual DTInfoLogueo comienzoInicioSesion(string ci) = 0;
	virtual bool ingresarContrasenia(string contrasenia) = 0;
	virtual void asignarSesionUsuario() = 0;
	virtual void crearContrasenia(string contrasenia) = 0;
	virtual void cerrarSesion() = 0;
	virtual bool iniciarAltaReactivacion(string ci) = 0;
	virtual void ingresarDatos(string nombre, string apellido, Sexo s, Fecha fNac, const set<Rol>& roles) = 0;
	virtual void altaUsuario() = 0;
	virtual DTUser pedirDatos() = 0;
	virtual void reactivarUsuario() = 0;

	virtual void crearAdminPorDefecto()=0;
	virtual set<Rol> rolesDelLogueado()=0;

	virtual void liberarMemoria()=0; // CUIDADO: Tendria que ir en algún lugar más neutral
	virtual ~IUsuario() {}
 };



#endif /* IUSUARIO_H_ */
