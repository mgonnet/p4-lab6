/*
 * DTMedicamento.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTMEDICAMENTO_H_
#define DTMEDICAMENTO_H_

#include <string>

using namespace std;

class DTMedicamento
{
public:
	DTMedicamento(string nombre);

	const string& getNombre() const;

private:
	string	nombre;
};


#endif /* DTMEDICAMENTO_H_ */
