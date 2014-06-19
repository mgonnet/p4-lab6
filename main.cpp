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

using namespace std;

int main()
{
	Usuario* usuario1;

	Fecha fecha(21,21,21);
	usuario1=new Usuario("Juan","Perez","4855460",MASCULINO,fecha,true,21,false,true);

	Almacen* alm=Almacen::getInstance();
	alm->addUsuario(usuario1);

	IUsuario* iUsuario=new CUsuario;  // CUIDADO: debería usar la Fabrica

	iUsuario->comienzoInicioSesion("4855460");
	iUsuario->crearContrasenia("passfrutera");
	iUsuario->asignarSesionUsuario();

	delete iUsuario;

	cout << "Espero passfrutera: " << usuario1->getContrasenia() << endl; // Se guardo la contrasenia que queria

	Logueo* logueo=Logueo::getInstance();
	cout << logueo->getUsuario()->getNombre() << endl; // Miro que se haya creado el link

	cout << "Espero false: " << usuario1->getPrimerLogueo() << endl; // Miro que se haya actualizado primerLogueo

	delete usuario1;
	return 0;
}

