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

#include <string>
using namespace std;

class RegistroAR {

public:

		RegistroAR create(Usuario u);
		void linkearUsuario(Usuario u);
		void addLineaRegistroAR(LineaRegistroAR lineaRegistro);
		bool usuarioIS(Usuario u);
		DTUsuarioAR* crearDTUsuarioAR(set<DTLineaRegistro> lineasRegistro);
		set<DTLineaRegistro> listarLineasRegistroAR();
};



#endif /* REGISTROAR_H_ */
