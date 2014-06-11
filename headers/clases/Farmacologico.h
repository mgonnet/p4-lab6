/*
 * Farmacologico.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef FARMACOLOGICO_H_
#define FARMACOLOGICO_H_

#include <string>
#include <set>

#include "../../headers/clases/Tratamiento.h"

class Medicamento;

using namespace std;

class Farmacologico: public Tratamiento{
private:
	Medicamento*	medicamento;

	void dummy() { }
public:
	
	//Creadoras
	Farmacologico(string,set<Medicamento*> medicamentos); // CUIDADO: estan seguro que son muchos medicamentos

	//Getters
	Medicamento*	getMedicamento();

	//Setters
	void	setMedicamento(Medicamento*);
	
	void	linkearMedicamento(Medicamento*);

	virtual ~Farmacologico();
};


#endif /* FARMACOLOGICO_H_ */
