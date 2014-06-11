/*
 * DTMedico.h
 *
 *  Created on: 09/06/2014
 *      Author: GRUPO_04
 */

#ifndef DTMEDICO_H_
#define DTMEDICO_H_

#include <string>

using namespace std;

class DTMedico
{
public:
	DTMedico(string nombre, string apellido, string ci);

	const string& getApellido() const;
	const string& getCi() const;
	const string& getNombre() const;

private:
	string	nombre;
	string	apellido;
	string	ci;
};


#endif /* DTMEDICO_H_ */
