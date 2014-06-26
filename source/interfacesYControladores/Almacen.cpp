/*
 * Almacen.cpp
 *
 *  Created on: 14/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/Almacen.h"
#include "../../headers/clases/CategoriaPS.h"
#include "../../headers/clases/Usuario.h"

#include <stdio.h>

Almacen* Almacen::instancia=NULL;

Almacen::Almacen() { }

Almacen* Almacen::getInstance()
{
	if(instancia==NULL)
		instancia=new Almacen;
	return instancia;
}

set<Medicamento*> Almacen::getMedicamentos() { return medicamentos; }

set<Usuario*> Almacen::getUsuarios() { return usuarios; }

set<CategoriaPS*> Almacen::getCategoriasPS() { return categorias; }

void Almacen::addMedicamento(Medicamento* med) { medicamentos.insert(med); }

void Almacen::addUsuario(Usuario* usu) { usuarios.insert(usu); }

void Almacen::addCategoriaPS(CategoriaPS* catPS) { categorias.insert(catPS); }

bool Almacen::memberMedicamento(string nombre) {
	set<Medicamento*>::iterator it;
	bool encontre = false;
	for(it = medicamentos.begin(); !encontre && (it != medicamentos.end()); ++it) {
		if ((*it)->getNombre() == nombre) {
			encontre = true;
		}
	}
	return encontre;
}

Usuario* Almacen::findUsuario(string ci) {
	set<Usuario*>::iterator it;
	bool encontre = false;
	Usuario* elUsuario;
	for (it = usuarios.begin(); !encontre && (it != usuarios.end()); ++it) {
		if ((*it)->getCi() == ci) {
			encontre = true;
			elUsuario = (*it);
		}
	}
	return elUsuario;
}

Almacen::~Almacen()
{
	//Primero debo vaciar todas las colecciones
	set<Medicamento*>::iterator itMed;
	for( itMed = medicamentos.begin(); itMed != medicamentos.end() ; ++itMed)
		delete (*itMed);

	set<Usuario*>::iterator itUser;
	for ( itUser = usuarios.begin() ; itUser != usuarios.end() ; ++itUser )
		delete (*itUser);

	set<CategoriaPS*>::iterator itCat;
	for ( itCat = categorias.begin() ; itCat != categorias.end() ; ++itCat )
		delete (*itCat);

	//Ahora seteo el Almacen como sin instancia
	instancia = NULL;
}
