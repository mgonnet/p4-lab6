/*
 * Almacen.cpp
 *
 *  Created on: 14/06/2014
 *      Author: GRUPO_04
 */

#include "../../headers/clases/Almacen.h"
#include "../../headers/clases/CategoriaPS.h"
#include "../../headers/clases/Usuario.h"
#include "../../headers/clases/Medicamento.h"

#include <stdio.h>

Almacen* Almacen::instancia=NULL;

Almacen::Almacen() { }

set<Medicamento*> Almacen::getMedicamentos() { return medicamentos; }

set<Usuario*> Almacen::getUsuarios() { return usuarios; }

set<CategoriaPS*> Almacen::getCategoriasPS() { return categorias; }

void Almacen::addMedicamento(Medicamento* med) { medicamentos.insert(med); }

void Almacen::addUsuario(Usuario* usu) { usuarios.insert(usu); }

void Almacen::addCategoriaPS(CategoriaPS* catPS) { categorias.insert(catPS); }
