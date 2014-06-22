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
	set<Medicamento*>::iterator it;

	bool existe = false;
	for(it = medicamentos.begin(); !existe && (it != medicamentos.end()); ++it) {
		if ((*it)->getNombre() == nombre) {
			existe = true;
			this->nombreMedicamentoAlta = nombre;
		}
	}
	return existe;
}

void CDiagnostico::confirmarAltaMedicamento() {}

CDiagnostico::~CDiagnostico(){}



