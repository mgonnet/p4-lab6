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

class Administrativo
{

private:
	set<RegistroAR*>  registrosAR;
	set<DTUsuarioAR*> datasUsuariosAR;
public:
	//operaciones
	Administrativo create(Usuario u);
	void linkearUsuario(Usuario u);
	void altaUsuario(Usuario u);
	void reactivarUsuario(Usuario u, TipoOper tipo);
	set<DTUsuarioAR*> listarUsuariosAR();
	void addDTUsuarioAR(DTUsuarioAR*);
};


#endif /* ADMINISTRATIVO_H_ */
