#include <string>

#include "../../headers/clases/CategoriaPS.h"

//Creadoras
CategoriaPS::CategoriaPS(char codigoCPS,string etiqueta): codigoCPS(codigoCPS), etiqueta(etiqueta) { }

//Getters
char 	CategoriaPS::getCodigoCPS() { return codigoCPS; }
string	CategoriaPS::getEtiqueta() { return etiqueta; }

//Setters
void	CategoriaPS::setCodigoCPS(char codigoCPS) { this->codigoCPS=codigoCPS; }
void	CategoriaPS::setEtiqueta(string etiqueta){ this->etiqueta=etiqueta; }
