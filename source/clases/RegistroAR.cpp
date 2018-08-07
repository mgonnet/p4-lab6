/*
 * RegistroAR.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/clases/RegistroAR.h"

RegistroAR::RegistroAR(Usuario* u, Administrativo* adm):
	usuario(u),
	adm(adm)
{}

void RegistroAR::addLineaRegistroAR(Fecha fecha,TipoOper tipo)
{
	LineaRegistroAR* nuevaLinea=new LineaRegistroAR(fecha,tipo);
	this->lineasRegistro.insert(nuevaLinea);
}

bool RegistroAR::usuarioIs(Usuario* u) { return this->usuario==u; }

RegistroAR::~RegistroAR()
{
	set<LineaRegistroAR*>::iterator it;
	for ( it = lineasRegistro.begin() ; it != lineasRegistro.end() ; ++it)
		delete (*it);
}

DTUsuarioAR RegistroAR::getDatosUsuarioAR() {
	set<DTLineaRegistro> datosLineaRegistro; //conjunto de elementos que quiero listar para agregar a DTUsuarioAR*
	set<LineaRegistroAR*> lineasRegistro = (this)->getLineasRegistroAR(); //coleccion de punteros a LineaRegistroAR
	set<LineaRegistroAR*>::iterator it; //iterar sobre la coleccion de punteros a LineaRegistroAR
	for (it = lineasRegistro.begin(); it != lineasRegistro.end(); ++it) {
		LineaRegistroAR* lineaRegistro = (*it); //elemento de la coleccion. Puntero a LineaRegistroAR
		datosLineaRegistro.insert(lineaRegistro->getDatosRegistro()); //insertar un datatype de DTLineaRegisro a datosLineaRegistro
	}
	Usuario* usuario = this->getUsuario();
	string nombreUs = usuario->getNombre();
	string apellidoUs = usuario->getApellido();
	string ciUs = usuario->getCi();
	int edadUs = usuario->getEdad();
	bool activoUs = usuario->getActivo();

	return DTUsuarioAR(nombreUs,apellidoUs,ciUs,edadUs,activoUs,datosLineaRegistro);
}

set<LineaRegistroAR*> RegistroAR::getLineasRegistroAR() { return lineasRegistro; }

Usuario* RegistroAR::getUsuario() {
	return usuario;
}
