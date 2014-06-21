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
#include "headers/dataTypes/DTReprEstandarizada.h"

using namespace std;

#include <stdio.h>
#include <stdlib.h>

void SetUp();
void TearDown();
int	 PantallaInicial();
void MostrarCasosDeUso();
bool EjecutarCasoDeUso();

using namespace std;

int main()
{
	int opcion=0; // 0 iniciar sesion, 1 Config Fecha Sistema
	SetUp();


	do
	{
		opcion=PantallaInicial();
		if(opcion!=1){
			if ( opcion==2 ) cambiarFechaSistema();
			else if ( iniciarSesion(0,"ROOT","123","\n") )
			{
				bool salir=false;
				while ( !salir )
				{
					MostrarCasosDeUso();
					salir = EjecutarCasoDeUso();
				}
			}
		}
	}while( opcion!=1 );

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
	IUsuario* iU=Factory::getIUsuario();
	iU->liberarMemoria();
	delete iU;
}

int	PantallaInicial()
{
	string dummy;
	system("clear");
	cout << "BIENVENIDO A HOSPITAL PÉCUATRO" << endl;
	cout << "------------------------------" << endl;
	cout << "Presione enter para iniciar sesion o escriba SALIR para salir..." << endl;
	getline(cin,dummy);

	int opcion;
	if (dummy == "SALIR") opcion=1;
	else if ( dummy == "CONFIGFECHASIS") opcion=2;
	else opcion=0;

	return opcion;
}

void MostrarCasosDeUso()
{
	IUsuario* iU=Factory::getIUsuario();
	set<Rol> roles=iU->rolesDelLogueado();

	system("clear");
	cout << "SELECCIONE ACCION" << endl;
	cout << "-----------------" << endl;

	if ( roles.find(ADMIN) != roles.end() )
	{
		cout << "(aru) > Alta/Reactivación Usuario" << endl;
		cout << "(uar) > Usuarios dados de alta y reactivados" << endl;
		cout << "(am)  > Alta Medicamento" << endl;
		cout << "(ard) > Alta Representación estandarizada de Diágnosticos" << endl;
		cout << "(rc)  > Registro Consulta" << endl;
		cout << "(ccd) > Cantidad de Consultas por Categoría Diagnóstico" << endl;
	}

	if ( roles.find(MEDICO) != roles.end() )
	{
		cout << "(adc) > Alta Diagnósticos de una consulta" << endl;
		cout << "(ohp) > Obtener Historial Paciente" << endl;
	}

	if ( roles.find(MEDICO) != roles.end() || roles.find(ADMIN) != roles.end() )
	{
		cout << "(lre) > Listar Representaciones Estandarizadas" << endl;
	}

	if ( roles.find(SOCIO) != roles.end() )
	{
		cout << "(rc)  > Reserva Consulta" << endl;
		cout << "(dc)  > Devolucion Consulta" << endl;
	}

	cout << "(cs) > Cerrar Sesion" << endl;

	cout << "> ";
	delete iU;
}

bool EjecutarCasoDeUso()
{
	bool salir=false;
	string buffer;
	getline(cin,buffer);

	IUsuario* iU=Factory::getIUsuario();
	set<Rol> roles=iU->rolesDelLogueado();

	if ( roles.find(ADMIN) != roles.end() )
	{
		if(buffer == "aru") AltaReactivacionDeUsuarios();
		if(buffer == "uar") UsuariosDadosDeAltaYReactivados();
		if(buffer == "am")  AltaMedicamento();
		if(buffer == "ard") AltaReprEstandarizadaDeDiagnosticos();
		if(buffer == "rc")  RegistroConsulta();
	}

	if ( roles.find(MEDICO) != roles.end() )
	{
		if(buffer == "adc") AltaDiagnosticosDeUnaConsulta();
		if(buffer == "ohp") ObtenerHistorialPaciente();
	}

	if ( roles.find(MEDICO) != roles.end() || roles.find(ADMIN) != roles.end() )
	{
		if(buffer == "lre") ListarRepresentacionesEstandarizadas();
	}

	if ( roles.find(SOCIO) != roles.end() )
	{
		if(buffer == "rc")  ReservaConsulta();
		if(buffer == "dc")  DevolucionConsulta();
	}

	if(buffer == "cs")
	{
		CerrarSesion();
		salir=true;
	}

	delete iU;
	return salir;
}
