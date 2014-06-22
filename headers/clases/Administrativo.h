/*
 * Administrativo.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef ADMINISTRATIVO_H_
#define ADMINISTRATIVO_H_

#include "../../headers/dataTypes/TipoOper.h"
#include "../../headers/dataTypes/DTUsuarioAR.h"
#include "../../headers/clases/RegistroAR.h"

#include <set>

using namespace std;

class Usuario;
class RegistroAR;

class Administrativo
{

private:
	Usuario*			usuario;
	set<RegistroAR*>	registrosAR;

public:
	//operaciones
	Administrativo(Usuario* u);
	void altaUsuario(Usuario *u);
	void reactivarUsuario(Usuario *u);
	set<DTUsuarioAR*> listarUsuariosAR();
	set<RegistroAR*> getRegistrosAR(); //devuelve coleccion de punteros a RegistroAR asociada a Administrativo

	~Administrativo();
};


#endif /* ADMINISTRATIVO_H_ */
