/*
 * DTUsuarioAR.h
 *
 *  Created on: 14/06/2014
 *      Author: Admin
 */

#ifndef DTUSUARIOAR_H_
#define DTUSUARIOAR_H_

#include "../../headers/dataTypes/DTLineaRegistro.h"
#include <string>
#include <set>
using namespace std;

class DTUsuarioAR {
public:
	bool isActivo() const;
	const string& getApellido() const;
	const string& getCi() const;
	int getEdad() const;
	const string& getNombre() const;
	const set<DTLineaRegistro>& getRegistros() const;

private:
	string nombre;
	string apellido;
	string ci;
	int edad;
	bool activo;
	set<DTLineaRegistro> registros;
};



#endif /* DTUSUARIOAR_H_ */
