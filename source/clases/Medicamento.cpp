#include <string>

#include "../../headers/clases/Medicamento.h"
#include "../../headers/clases/Farmacologico.h"

//Creadoras
Medicamento::Medicamento(string nombre,Farmacologico farmacologico): nombre(nombre) { }

//Getters
string	Medicamento::getNombre() { return nombre; }

//Setters
void	Medicamento::setNombre(string nombre) { this->nombre=nombre; }
