/*
 * DTCombinado.cpp
 *
 *  Created on: 21/06/2014
 *      Author: eacosta
 */

#include "../../headers/dataTypes/DTCombinado.h"

DTCombinado::DTCombinado(string codigo, string etiqueta, set<DTProblemaSalud> setDtPs):codigo(codigo),etiqueta(etiqueta),setDtPs(setDtPs)
{
	//DTCategoriaPS dt = DTCategoriaPS(codigo, etiqueta);
	//dtCps = DTCategoriaPS(codigo, etiqueta);
	//setDtps = setDtPs;
}

//DTCategoriaPS DTCombinado::getDtCps() const { return dtCps; }
string DTCombinado::getCodigo() const { return codigo; }
string DTCombinado::getEtiqueta() const { return etiqueta; }
set<DTProblemaSalud> DTCombinado::getSetDtps() const { return setDtPs; }
bool DTCombinado::operator<(DTCombinado dtCmb) const {
	return(DTCategoriaPS(codigo,etiqueta) < DTCategoriaPS(dtCmb.getCodigo(),dtCmb.getEtiqueta()));
}






