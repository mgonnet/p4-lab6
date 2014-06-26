/*
 * Almacen.h
 *
 *  Created on: 14/06/2014
 *      Author: matias
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include <set>
#include "../../headers/clases/Medicamento.h"

class CategoriaPS;
class Usuario;

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
	bool	memberMedicamento(string);
	Usuario* findUsuario(string);

	~Almacen();
};

#endif /* ALMACEN_H_ */
