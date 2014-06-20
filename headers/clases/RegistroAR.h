/*
 * RegistroAR.h
 *
 *  Created on: 11/06/2014
 *      Author: sac
 */

#ifndef REGISTROAR_H_
#define REGISTROAR_H_

#include "../../headers/dataTypes/DTUsuarioAR.h"
#include "../../headers/dataTypes/DTLineaRegistro.h"
#include "../../headers/clases/LineaRegistroAR.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/Administrativo.h"

#include <string>
using namespace std;

class RegistroAR
{
private:
	Usuario* usuario;
	Administrativo* adm;  // CUIDADO: Ver si realmente se uso
	set<LineaRegistroAR*> lineas;

public:

	RegistroAR(Usuario*,Administrativo*);
	void linkearUsuario(Usuario u);
	void addLineaRegistroAR(Fecha,TipoOper);
	bool usuarioIS(Usuario u);
	DTUsuarioAR* crearDTUsuarioAR(set<DTLineaRegistro> lineasRegistro);
	set<DTLineaRegistro> listarLineasRegistroAR();
};



#endif /* REGISTROAR_H_ */
