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
					iU->crearContrasenia(contrasenia);
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

	delete iU;
	return exito;
}

void AltaReactivacionDeUsuarios()
{
	bool repetir=true;
	bool repetirRoles=true;
	bool existe;
	bool datosInvalidos=false;
	bool reactivar=false;
	bool cancelarAlta;
	string ci;
	string nombre;
	string apellido;
	string buffer;
	Sexo sexo;

	int dia;
	int mes;
	int anio;
	Fecha fecha;

	set<Rol> roles;

	IUsuario* iU=Factory::getIUsuario();

	DTUser datosUsuario;

	do
	{
		system("clear");
		cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
		cout << "-----------------------------" << endl;
		cout << "Está aquí para dar de alta o reactivar un usuario." << endl;
		cout << "Ingrese la cedula de usuario en cuestion:" << endl;
		cout << "> ";
		getline(cin,ci);

		existe=iU->iniciarAltaReactivacion(ci);

		if(!existe)
		{
			system("clear");
			cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
			cout << "-----------------------------" << endl;
			cout << "No existe un usuario con esa cedula por lo que procederemos con el ALTA:" << endl;
			cancelarAlta=false;
			do
			{
				datosInvalidos = false;
				cout << "Ingrese un nombre:" << endl;
				cout << "> ";
				getline(cin,nombre);

				cout << "Ingrese un apellido:" << endl;
				cout << "> ";
				getline(cin,apellido);

				cout << "Ingrese el sexo [m/f]:" << endl;
				cout << "> ";
				getline(cin,buffer);
				if(buffer=="m")
					sexo=MASCULINO;
				else if(buffer=="f")
					sexo=FEMENINO;
				else
					datosInvalidos=datosInvalidos || true;

				cout << "Ingrese la fecha de nacimiento: el dia:" << endl;
				cout << "> ";
				getline(cin,buffer);
				dia=atoi(buffer.c_str());
				cout << "Ingrese la fecha de nacimiento: el mes:" << endl;
				cout << "> ";
				getline(cin,buffer);
				mes=atoi(buffer.c_str());
				cout << "Ingrese la fecha de nacimiento: el año:" << endl;
				cout << "> ";
				getline(cin,buffer);
				anio=atoi(buffer.c_str());
				fecha=Fecha(dia,mes,anio);
				if(!fecha.isCorrecta())
					datosInvalidos=datosInvalidos || true;

				roles.clear();
				do
				{
					cout << "Ingrese un Rol para el usuario: (ADMIN/MEDICO/SOCIO):" << endl;
					cout << "> ";
					getline(cin,buffer);
					if(buffer=="ADMIN")
						roles.insert(ADMIN);
					else if(buffer=="MEDICO")
						roles.insert(MEDICO);
					else if(buffer=="SOCIO")
						roles.insert(SOCIO);
					else
						datosInvalidos=datosInvalidos || true;
					cout << "Desea ingresar otro ROL: [1/0]" << endl;
					cout << "> ";
					getline(cin,buffer);
					repetirRoles=(buffer=="1");
				}while(repetirRoles && (roles.size()<=2));
				//datosInvalidos=datosInvalidos || roles.hayRepetidos();


				if(datosInvalidos)
				{
					system("clear");
					cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
					cout << "-----------------------------" << endl;
					cout << "Has ingresado algún dato mal." << endl;
					cout << "¿Deseas volver a probar? [1/0]" << endl;
					cout << "> ";
					getline(cin,buffer);
					if(buffer!="1")
					{
						cancelarAlta=true;
					}
				}
				else
					iU->ingresarDatos(nombre,apellido,sexo,fecha,roles);
			}while(datosInvalidos && !cancelarAlta);

			if(!cancelarAlta)
			{
				iU->altaUsuario();
				system("clear");
				cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
				cout << "-----------------------------" << endl;
				cout << "El usuario ha sido dado de alta. Enter para continuar." << endl;
				getline(cin,buffer);
				repetir=false;
			}
			else
			{
				system("clear");
				cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
				cout << "-----------------------------" << endl;
				cout << "Se ha cancelado el alta. Enter para continuar." << endl;
				getline(cin,buffer);
			}
		}
		else // Usuario existe
		{
			datosUsuario=iU->pedirDatos();
			cout << datosUsuario << endl;

			if(datosUsuario.isActivo())
			{
				system("clear");
				cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
				cout << "-----------------------------" << endl;
				cout << "Este usuario ya está dado de alta y además está activo. No hay nada que hacer aquí." << endl;
				cout << "¿Desea probar suerte con otro usuario? [1/0]" << endl;
				cout << "> ";
				getline(cin,buffer);
				repetir=(buffer=="1");
			}
			else //Confirmar la reactivacion
			{
				system("clear");
				cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
				cout << "-----------------------------" << endl;
				cout << "Este usuario está inactivo. ¿Desea reactivarlo? [1/0]" << endl;
				cout << "> ";
				getline(cin,buffer);
				reactivar=(buffer==("1"));

				if(reactivar)
				{
					iU->reactivarUsuario();
					system("clear");
					cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
					cout << "-----------------------------" << endl;
					cout << "EL usuario ha sido reactivado. Enter para continuar." << endl;
					getline(cin,buffer);
					repetir=false;
				}
				else
				{
					system("clear");
					cout << "ALTA/REACTIVACION DE USUARIOS" << endl;
					cout << "-----------------------------" << endl;
					cout << "¿Desea probar suerte con otro usuario? [1/0]" << endl;
					cout << "> ";
					getline(cin,buffer);
					repetir=(buffer=="1");
				}
			}

		}

	}while(repetir);

	delete iU;
}

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
	delete iU;
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
