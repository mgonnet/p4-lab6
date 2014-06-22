#include <string>

#include "../../headers/clases/CategoriaPS.h"
#include "../../headers/dataTypes/DTProblemaSalud.h"
#include "../../headers/clases/ProblemaSalud.h"
#include "../../headers/dataTypes/DTReprEstandarizada.h"
#include "../../headers/dataTypes/DTCategoriaPS.h"

//Creadoras
CategoriaPS::CategoriaPS(string codigoCPS,string etiqueta): codigoCPS(codigoCPS), etiqueta(etiqueta) { }

//Getters
string 	CategoriaPS::getCodigoCPS() { return codigoCPS; }
string	CategoriaPS::getEtiqueta() { return etiqueta; }
set<ProblemaSalud*> CategoriaPS::getProbSal() { return problemasSalud; }

//Setters
void	CategoriaPS::setCodigoCPS(string codigoCPS) { this->codigoCPS=codigoCPS; }
void	CategoriaPS::setEtiqueta(string etiqueta) { this->etiqueta=etiqueta; }
void	CategoriaPS::setProbSal(set<ProblemaSalud*> probSal) { this->problemasSalud = probSal; }

DTReprEstandarizada	CategoriaPS::obtenerReprEstandarizada() {

	string codCPS = codigoCPS;
	string etiq = etiqueta;
	set <DTProblemaSalud> setProbSal;
	for(set<ProblemaSalud*>::iterator it=problemasSalud.begin(); it!=problemasSalud.end(); ++it){
		DTProblemaSalud probSal = (*it)->obtenerDTProblemaSalud();
		setProbSal.insert(probSal);
	}
	return DTReprEstandarizada(codCPS,etiq,setProbSal);
}

DTCategoriaPS CategoriaPS::obtenerCategoria() {
	return DTCategoriaPS(codigoCPS,etiqueta);
}
