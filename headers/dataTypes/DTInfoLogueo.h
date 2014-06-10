/*
 * DTInfoLogueo.h
 *
 *  Created on: 10/05/2014
 *      Author: Emiliano
 */

#ifndef DTINFOLOGUEO_H_
#define DTINFOLOGUEO_H_

#include <string>

using namespace std;

class DTInfoLogueo {
private:
	bool primerLogueo;
	bool adminPorDefecto;
	bool activo;
	bool usuarioExiste;
public:
	//Constructoras
	DTInfoLogueo();
	DTInfoLogueo(bool primerLogueo, bool adminPorDefecto, bool activo,bool ususarioExiste);

	//Sobrecarga de operadores
	DTInfoLogueo operator=(DTInfoLogueo original);

	//Getters
	bool getExistencia();
	bool isActivo();
	bool getPrimerLogueo();
	bool getAdminPorDefecto();
};

#endif /* DTINFOLOGUEO_H_ */
