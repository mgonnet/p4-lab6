/*
 * CDiagnostico.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/CDiagnostico.h"
#include "../../headers/interfacesYControladores/Almacen.h"
#include "../../headers/clases/CategoriaPS.h"
#include "../../headers/clases/ProblemaSalud.h"


CDiagnostico::CDiagnostico(): nombreMedicamentoAlta("") {}

set<DTCategoriaPS> CDiagnostico::obtenerCategorias()
{
	Almacen* alm = Almacen::getInstance();
	set<CategoriaPS*> setCps = alm->getCategoriasPS();
	set<DTCategoriaPS> setDtCps;
	for (set<CategoriaPS*>::iterator it=setCps.begin(); it!=setCps.end(); ++it)
	   {
		   setDtCps.insert((*it)->obtenerCategoria());
	   }
	return setDtCps;
}

void CDiagnostico::agregarCategoria(string codigo,string etiqueta) {
	codMarcado = codigo;
	etiqMarcado = etiqueta;
}

void CDiagnostico::seleccionarCategoria(string){}

set<DTReprEstandarizada> CDiagnostico::getReprEstandarizadas()
{
   set<DTReprEstandarizada> setReprEst;
   Almacen* alm = Almacen::getInstance();
   set<CategoriaPS*> categorias = alm->getCategoriasPS();
   for (set<CategoriaPS*>::iterator it=categorias.begin(); it!=categorias.end(); ++it)
   {
	   set<DTProblemaSalud> propio;
	   setReprEst.insert((*it)->obtenerReprEstandarizada());
   }
   return setReprEst;
}

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

bool CDiagnostico::ingresarRepDiag(string codPS, string etiqueta) {
	bool existe = false;
	DTProblemaSalud dtPs = DTProblemaSalud(codPS,etiqueta);
	if (marcado != NULL){
		set<ProblemaSalud*> setDtPs = marcado->getProbSal();
		for(set<ProblemaSalud*>::iterator it=setDtPs.begin(); it!=setDtPs.end(); ++it){
			if ((*it)->getCodigoPS() == codPS)
				existe = true;
		}

	}
	if (!existe)
		setDtps.insert(dtPs);
	return existe;
}

void CDiagnostico::finProblemasSalud(){
	if (marcado != NULL)
		dtCmb.insert(DTCombinado(marcado->getCodigoCPS(), marcado->getEtiqueta(),setDtps));
	else
		dtCmb.insert(DTCombinado(codMarcado,etiqMarcado,setDtps));
}

void CDiagnostico::confirmarAlta(){
	Almacen* alm = Almacen::getInstance();
	for(set<DTCombinado>::iterator it=dtCmb.begin(); it!=dtCmb.end(); ++it){
		CategoriaPS* catPs = new CategoriaPS((*it).getCodigo(),(*it).getEtiqueta());
		set<DTProblemaSalud> dtPs = (*it).getSetDtps();
		set<ProblemaSalud*> probSal;
		for(set<DTProblemaSalud>::iterator it1=dtPs.begin(); it1!=dtPs.end(); ++it1){
			ProblemaSalud* ps = new ProblemaSalud((*it1).getCodigo(),(*it1).getEtiqueta());
			ps->setCategoriaPS(catPs);
			probSal.insert(ps);
		}
		catPs->setProbSal(probSal);
		alm->addCategoriaPS(catPs);
	}
}

CDiagnostico::~CDiagnostico(){}



