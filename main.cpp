/*
 * main.cpp
 *
 *  Created on: 10/06/2014
 *      Author: matias
 */

#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>



#include "headers/clases/Accion.h"
#include "headers/clases/AccionMensaje.h"
#include "headers/dataTypes/ParametroAccionMensaje.h"
#include "headers/clases/MedicoNotificable.h"
#include "headers/clases/Mensaje.h"
#include "headers/dataTypes/FechaHora.h"
#include "headers/clases/Socio.h"
#include "headers/clases/StockAcciones.h"
#include "headers/clases/Logueo.h"
#include "headers/interfacesYControladores/IUsuario.h"
#include "headers/interfacesYControladores/CUsuario.h"
#include "headers/interfacesYControladores/Almacen.h"
#include "headers/clases/Usuario.h"
#include "headers/CasosDeUso.h"
#include "headers/interfacesYControladores/Factory.h"

using namespace std;

#include <stdio.h>
#include <stdlib.h>

// Ejemplo extraido de Snippets Zone: http://snippets.dzone.com/posts/show/2734
// Compilarlo con $ gcc -o clear clear.c y mover a /usr/bin

void SetUp();
void TearDown();
bool PantallaInicial();

int main(int argc, char *argv[])
{
	SetUp();

	while( PantallaInicial() )
	{
		if ( iniciarSesion() )
		{
			// HACER ALGO
		}
	}

	TearDown();

	return 0;
}

void SetUp()
{
	IUsuario* iU=Factory::getIUsuario();
	iU->crearAdminPorDefecto();
	delete iU;
}

void TearDown()
{

}

bool	PantallaInicial()
{
	string dummy;
	system("clear");
	cout << "BIENVENIDO A HOSPITAL PÉCUATRO" << endl;
	cout << "------------------------------" << endl;
	cout << "Presione enter para iniciar sesion o escriba SALIR para salir..." << endl;
	getline(cin,dummy);

	return !(dummy == "SALIR");
}
