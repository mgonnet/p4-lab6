/*
 * main.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include <iostream>
#include <set>
#include <stdlib.h>


#include "headers/dataTypes/DTDiagnostico.h"
#include "headers/dataTypes/DTProblemaSalud.h"

using namespace std;

int main()
{
	DTProblemaSalud cosa("gil","gil");
	set<string> cosas;
	cosas.insert("gil");

	DTDiagnostico diag("co","co","cod",cosas);
	string gil=diag.getCodigo();
	cout << gil;
	gil="tu madre";
	cout << gil;
	cout << "Este es un programa que compila";

	return 0;
}

