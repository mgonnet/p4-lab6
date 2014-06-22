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
	set<LineaRegistroAR*> lineasRegistro; //pseudoatributo

public:

	RegistroAR(Usuario*,Administrativo*);
	void linkearUsuario(Usuario u);
	void addLineaRegistroAR(Fecha,TipoOper);
	bool usuarioIs(Usuario* u);
	set<DTLineaRegistro> listarLineasRegistroAR();

	set<LineaRegistroAR*> getLineasRegistroAR(); //devuelve coleccion de punteros de LineaRegistroAR asociada a RegistroAR
	DTUsuarioAR* getDatosUsuarioAR(); //devuelve datatype de DTUsuarioAR

	Usuario* getUsuario();

	~RegistroAR();
};



#endif /* REGISTROAR_H_ */
