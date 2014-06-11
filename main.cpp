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

using namespace std;

int main()
{
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

