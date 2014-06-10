#include <string>

#include "../headers/Medicamento.h"

//Creadoras
Medicamento::Medicamento(string nombre): nombre(nombre) { }

//Getters
string	Medicamento::getNombre() { return nombre; }

//Setters
void	Medicamento::setNombre(string nombre) { this->nombre=nombre; }
