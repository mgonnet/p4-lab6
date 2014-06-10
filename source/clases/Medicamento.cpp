#include <string>

#include "../../headers/clases/Medicamento.h"

//Creadoras
Medicamento::Medicamento(string nombre): nombre(nombre) { }

//Getters
string	Medicamento::getNombre() { return nombre; }

//Setters
void	Medicamento::setNombre(string nombre) { this->nombre=nombre; }
