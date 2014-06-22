/*
 * CDiagnostico.h
 *
 *  Created on: Jun 11, 2014
 *      Author: eacosta
 */

#ifndef CDIAGNOSTICO_H_
#define CDIAGNOSTICO_H_

#include <set>
#include "IDiagnostico.h"
#include "../dataTypes/DTReprEstandarizada.h"
#include "IDiagnostico.h"

class CDiagnostico : public IDiagnostico
{
private:
	string nombreMedicamentoAlta;

public:
	CDiagnostico();

	set<DTCategoriaPS> obtenerCategorias();
	void agregarCategoria(string,string);
	void seleccionarCategoria(string);
	set<DTReprEstandarizada> getReprEstandarizadas();


	bool ingresarDatosMedicamento(string nombre);
	void confirmarAltaMedicamento();

	~CDiagnostico();
};


#endif /* CDIAGNOSTICO_H_ */
