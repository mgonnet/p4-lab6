#include <string>

#include "../../headers/clases/CategoriaPS.h"

//Creadoras
CategoriaPS::CategoriaPS(char codigoCPS,string nombre): codigoCPS(codigoCPS), nombre(nombre) { }

//Getters
char 	CategoriaPS::getCodigoCPS() { return codigoCPS; }
string	CategoriaPS::getNombre() { return nombre; }

//Setters
void	CategoriaPS::setCodigoCPS(char codigoCPS) { this->codigoCPS=codigoCPS; }
void	CategoriaPS::setNombre(string nombre){ this->nombre=nombre; }
