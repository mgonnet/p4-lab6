/*
 * DTUser.cpp
 *
 *  Created on: 11/05/2014
 *      Author: matias
 */

#include <iostream>

#include "../../headers/dataTypes/DTUser.h"

using namespace std;

//Constructora
DTUser::DTUser(){}
DTUser::DTUser(string nombre,string apellido,Sexo sexo,int edad,bool activo,set<Rol> roles) : nombre(nombre), apellido(apellido), sexo(sexo),edad(edad),activo(activo)
{
	this->roles=roles;

}

//Sobrecarga de operadores
DTUser DTUser::operator=(DTUser original)
{
	this->nombre=original.nombre;
	this->apellido=original.apellido;
	this->sexo=original.sexo;
	this->edad=original.edad;
	this->activo=original.activo;
	this->roles=original.roles;
	return (*this);
}

//Getters
bool		DTUser::isActivo() { return activo; }
string		DTUser::getApellido() { return apellido; }
int			DTUser::getEdad()  { return edad; }
string		DTUser::getNombre()  { return nombre; }
set<Rol>	DTUser::getRoles()  { return roles; }
Sexo		DTUser::getSexo()  { return sexo; }

//Impresion
ostream &operator<<( ostream &stream,DTUser imprimible) //Misterioso
{
 	stream << "El nombre es: " << imprimible.getNombre() << endl;
	stream << "El apellido es: " << imprimible.getApellido() << endl;
	if(imprimible.getSexo()==MASCULINO)
		stream << "El sexo es: MASCULINO" << endl;
	else
		stream << "El sexo es: FEMENINO" << endl;
	stream << "La edad es: " << imprimible.getEdad() << endl;
	if(imprimible.isActivo())
		cout << "El usuario está activo" << endl;
	else
		cout << "El usuario está inactivo" << endl;
	//stream << "Los roles son: " << imprimible.getRoles(); // CUIDADO:
	return( stream );
}
