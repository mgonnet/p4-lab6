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
#include "../dataTypes/DTCombinado.h"
#include "IDiagnostico.h"
#include "../../headers/clases/CategoriaPS.h"

class CDiagnostico : public IDiagnostico
{
private:
	string nombreMedicamentoAlta;
	CategoriaPS* marcado;
	//DTCategoriaPS dtCps;
	string codigoCPS;
	string etiquetaCPS;
	set<DTCombinado> dtCmb;
	string codMarcado;
	string etiqMarcado;
	//DTCombinado marcadoDT;
	set<DTProblemaSalud> setDtps;

public:
	CDiagnostico();

	set<DTCategoriaPS> obtenerCategorias();
	void agregarCategoria(string,string);
	set<DTReprEstandarizada> getReprEstandarizadas();


	bool ingresarDatosMedicamento(string nombre);
	void confirmarAltaMedicamento();

	bool ingresarRepDiag(string codPs, string etiqueta);
	void finProblemasSalud();
	void seleccionarCategoria(string codigo);

	void confirmarAlta();

	~CDiagnostico();
};


#endif /* CDIAGNOSTICO_H_ */
