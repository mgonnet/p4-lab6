/*
 * IniciarSesion.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/Factory.h"
#include "../../headers/interfacesYControladores/IUsuario.h"
#include "../../headers/dataTypes/DTInfoLogueo.h"

#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool validaPass(string contrasenia);

bool iniciarSesion(){
	bool exito=false;

	IUsuario* iU=Factory::getIUsuario();

	//Variables Usuadas en iniciar Sesion
	string	buffer;
	bool	contraseniaIncorrecta;
	string	contrasenia;
	bool	volverAIngresar;
	bool	contraseniaInvalida=false;
	string	ci;

	//Inciar Sesion
	system("clear");
	cout << "INCIO DE SESION" << endl;
	cout << "---------------" << endl;
	cout << "Ingrese su CI:" << endl;
	cout << "> ";
	getline(cin,ci);

	DTInfoLogueo infoLogueo=iU->comienzoInicioSesion(ci);

	if(infoLogueo.getExistencia())
	{
		if(infoLogueo.getAdminPorDefecto())
		{
			do
			{
				system("clear");
				cout << "INCIO DE SESION" << endl;
				cout << "---------------" << endl;
				cout << "Eres el administrativo por defecto." << endl;
				cout << "Por favor ingresa tu contraseña" << endl;
				cout << "> ";
				getline(cin,contrasenia);

				contraseniaIncorrecta=iU->ingresarContrasenia(contrasenia);

				if(contraseniaIncorrecta)
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Oops. Has ingresado una contraseña incorrecta. ¿Quieres volver a probar? [1/0]" << endl;
					cout << "> ";
					getline(cin,buffer);
					volverAIngresar=(buffer=="1");
				}

			}while(contraseniaIncorrecta && volverAIngresar);

			if(!contraseniaIncorrecta)
			{
				exito=true;
				iU->asignarSesionUsuario();
				system("clear");
				cout << "INCIO DE SESION" << endl;
				cout << "---------------" << endl;
				cout << "Tu sesion ha sido iniciada. Enter para continuar" << endl;
				getline(cin,buffer);
			}
		}
		else // NO es adminPorDefecto
		{
			if(infoLogueo.getPrimerLogueo())
			{
				do
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Es la primera vez que inicias sesion. Debes indicar cual será tu contraseña:" << endl;
					cout << "> ";
					getline(cin,contrasenia);

					contraseniaInvalida=validaPass(contrasenia);

					if(contraseniaInvalida)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Oops. Has ingresado una contraseña con un formato no válido. ¿Quieres volver a probar? [1/0]" << endl;
						cout << "> ";
						getline(cin,buffer);
						volverAIngresar=(buffer=="1");
					}
				}while(contraseniaInvalida && volverAIngresar);

				if(!contraseniaInvalida)
				{
					exito=true;
					iU->asignarSesionUsuario();
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Tu contrasenia fue almacenada y tu sesion iniciada. Enter para continuar" << endl;
					getline(cin,buffer);
				}
			}
			else // Es usuario comun y no es el primer logueo
			{
				do
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Eres un simple usuario y no es tu primer logueo." << endl;
					cout << "Por favor ingresa tu contraseña" << endl;
					cout << "> ";
					getline(cin,contrasenia);

					contraseniaIncorrecta=iU->ingresarContrasenia(contrasenia);

					if(contraseniaIncorrecta)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Oops. Has ingresado una contraseña incorrecta. ¿Quieres volver a probar? [1/0]" << endl;
						cout << "> ";
						getline(cin,buffer);
						volverAIngresar=(buffer=="1");
					}

				}while(contraseniaIncorrecta && volverAIngresar);

				if(!infoLogueo.isActivo()) //SI ES INACTIVO
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Su usuario está inactivo y no puede loguearse. Enter para continuar" << endl;
					getline(cin,buffer);
				}
				else // ES ACTIVO
					if(!contraseniaIncorrecta)
					{
						exito=true;
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						iU->asignarSesionUsuario();
						cout << "Tu sesion ha sido iniciada. Enter para continuar" << endl;
						getline(cin,buffer);
					}
			}
		}
	}
	else
	{
		system("clear");
		cout << "INCIO DE SESION" << endl;
		cout << "---------------" << endl;
		cout << "No existe un usuario con esa CI. Enter para continuar" << endl;
		getline(cin,buffer);
	}
	//End Iniciar Sesion

	return exito;
}

void AltaReactivacionDeUsuarios(){}
void UsuariosDadosDeAltaYReactivados(){}
void AltaMedicamento(){}
void AltaReprEstandarizadaDeDiagnosticos(){}
void RegistroConsulta(){}
void AltaDiagnosticosDeUnaConsulta(){}
void ObtenerHistorialPaciente(){}
void ListarRepresentacionesEstandarizadas(){}
void ReservaConsulta(){}
void DevolucionConsulta(){}

void CerrarSesion()
{
	IUsuario* iU=Factory::getIUsuario();
	iU->cerrarSesion();
}

bool validaPass(string contrasenia)
{
	bool malCaracter=false;
	int largo=contrasenia.length();
	if(largo>=6 && largo <=9)
	{
		for(int i=0;i<largo;i++)
		{
			if(!((contrasenia[i]>=48 && contrasenia[i]<=57) || (contrasenia[i]>=65 && contrasenia[i]<=90) || (contrasenia[i]>=97 && contrasenia[i]<=122)))
				malCaracter=true;
		}
	}
	else
		malCaracter=true;
	return malCaracter;
}
