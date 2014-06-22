/*
 * CDiagnostico.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/CDiagnostico.h"
#include "../../headers/interfacesYControladores/Almacen.h"


CDiagnostico::CDiagnostico(): nombreMedicamentoAlta("") {}

set<DTCategoriaPS> CDiagnostico::obtenerCategorias(){}
void CDiagnostico::agregarCategoria(string,string){}
void CDiagnostico::seleccionarCategoria(string){}
set <DTReprEstandarizada> CDiagnostico::getReprEstandarizadas(){}

bool CDiagnostico::ingresarDatosMedicamento(string nombre) {

	Almacen* alm = Almacen::getInstance();
	set<Medicamento*> medicamentos = alm->getMedicamentos();
	bool existe = alm->memberMedicamento(nombre);
	if (!existe) { this->nombreMedicamentoAlta = nombre; }
	return existe;
}

void CDiagnostico::confirmarAltaMedicamento() {

	Medicamento* nuevoMedicamento = new Medicamento(this->nombreMedicamentoAlta);
	Almacen* alm = Almacen::getInstance();
	alm->addMedicamento(nuevoMedicamento); //ya esta implementado en Almacen.cpp
}


CDiagnostico::~CDiagnostico(){}



