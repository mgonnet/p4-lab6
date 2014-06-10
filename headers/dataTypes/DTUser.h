#ifndef DTUSER_H_
#define DTUSER_H_

#include <string>
#include <set>

#include "Sexo.h"
#include "Rol.h"
//Agregar ROLES en constructor



using namespace std;

class DTUser
{
private:
	string		nombre;
	string		apellido;
	Sexo		sexo;
	int			edad;
	bool		activo;
	set<Rol>	roles;

public:
	//Constructora
	DTUser(string nombre,string apellido,Sexo sexo,int edad,bool activo,set<Rol> roles);

	//Sobrecarga de operadores
	DTUser		operator=(DTUser original);

	//Getters
	bool		isActivo();
	string		getApellido();
	string		getCi();
	string		getNombre();
	set<Rol>	getRoles();
	Sexo 		getSexo();
	int			getEdad();
};

std::ostream &operator<<( std::ostream &stream,DTUser imprimible);

#endif /* DTUSER_H_ */
