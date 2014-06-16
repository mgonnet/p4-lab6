/*
 * Almacen.h
 *
 *  Created on: 14/06/2014
 *      Author: GRUPO_04
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include <set>

class CategoriaPS;
class Usuario;
class Medicamento;

using namespace std;

class Almacen
{
private:
	Almacen();

	static Almacen* instancia;

	set<CategoriaPS*>	categorias;
	set<Usuario*>		usuarios;
	set<Medicamento*>	medicamentos;

public:
	static Almacen* getInstance();

	set<Medicamento*>	getMedicamentos();
	set<Usuario*>		getUsuarios();
	set<CategoriaPS*>	getCategoriasPS();

	void	addMedicamento(Medicamento*);
	void	addUsuario(Usuario*);
	void	addCategoriaPS(CategoriaPS*);

};

#endif /* ALMACEN_H_ */
