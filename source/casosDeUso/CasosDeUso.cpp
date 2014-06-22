/*
 * IniciarSesion.cpp
 *
 *  Created on: 19/06/2014
 *      Author: matias
 */

#include "../../headers/interfacesYControladores/Factory.h"
#include "../../headers/interfacesYControladores/IUsuario.h"
#include "../../headers/interfacesYControladores/IConsulta.h"
#include "../../headers/dataTypes/DTInfoLogueo.h"
#include "../../headers/clases/FechaSistema.h"

#include <string>
#include <stdlib.h>
#include <iostream>
#include <cstdarg>
#include <stdexcept>

using namespace std;

Fecha ingresoFecha();
bool validaPass(string contrasenia);

void cambiarFechaSistema()
{
	FechaSistema* fSis=FechaSistema::getInstance();

	system("clear");
	cout << "CAMBIO DE FECHA SISTEMA" << endl;
	cout << "-----------------------" << endl;
	cout << "La Fecha actual es:" << endl;
	cout << fSis->getFechaSistema();
	Fecha fecha=ingresoFecha();

	fSis->setFechaSistema(fecha);
}

bool iniciarSesion(int argc, ... ){
	va_list p;
	va_start(p,argc);

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
	if(argc==0)
	{
		system("clear");
		cout << "INCIO DE SESION" << endl;
		cout << "---------------" << endl;
		cout << "Ingrese su CI:" << endl;
		cout << "> ";
		getline(cin,ci);
	}
	else
	{
		ci=string(va_arg(p,char *));
		argc--;
	}

	DTInfoLogueo infoLogueo=iU->comienzoInicioSesion(ci);

	if(infoLogueo.getExistencia())
	{
		if(infoLogueo.getAdminPorDefecto())
		{
			do
			{
				if(argc==0)
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Eres el administrativo por defecto." << endl;
					cout << "Por favor ingresa tu contraseña" << endl;
					cout << "> ";
					getline(cin,contrasenia);
				}
				else
				{
					contrasenia=string(va_arg(p,char *));
					argc--;
				}

				contraseniaIncorrecta=iU->ingresarContrasenia(contrasenia);

				if(contraseniaIncorrecta)
				{
					if(argc==0)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Oops. Has ingresado una contraseña incorrecta. ¿Quieres volver a probar? [1/0]" << endl;
						cout << "> ";
						getline(cin,buffer);
					}
					else
					{
						buffer=string(va_arg(p,char *));
						argc--;
					}

					volverAIngresar=(buffer=="1");
				}

			}while(contraseniaIncorrecta && volverAIngresar);

			if(!contraseniaIncorrecta)
			{
				exito=true;
				iU->asignarSesionUsuario();
				if(argc==0)
				{
					system("clear");
					cout << "INCIO DE SESION" << endl;
					cout << "---------------" << endl;
					cout << "Tu sesion ha sido iniciada. Enter para continuar" << endl;
					getline(cin,buffer);
				}
				else
				{
					buffer=string(va_arg(p,char *));
					argc--;
				}
			}
		}
		else // NO es adminPorDefecto
		{
			if(infoLogueo.getPrimerLogueo())
			{
				do
				{
					if(argc==0)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Es la primera vez que inicias sesion. Debes indicar cual será tu contraseña:" << endl;
						cout << "> ";
						getline(cin,contrasenia);
					}
					else
					{
						contrasenia=string(va_arg(p,char *));
						argc--;
					}

					contraseniaInvalida=validaPass(contrasenia);

					if(contraseniaInvalida)
					{
						if(argc==0)
						{
							system("clear");
							cout << "INCIO DE SESION" << endl;
							cout << "---------------" << endl;
							cout << "Oops. Has ingresado una contraseña con un formato no válido. ¿Quieres volver a probar? [1/0]" << endl;
							cout << "> ";
							getline(cin,buffer);
						}
						else
						{
							buffer=string(va_arg(p,char *));
							argc--;
						}
						volverAIngresar=(buffer=="1");
					}
				}while(contraseniaInvalida && volverAIngresar);

				if(!contraseniaInvalida)
				{
					iU->crearContrasenia(contrasenia);
					exito=true;
					iU->asignarSesionUsuario();
					if(argc==0)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Tu contrasenia fue almacenada y tu sesion iniciada. Enter para continuar" << endl;
						getline(cin,buffer);
					}
					else
					{
						buffer=string(va_arg(p,char *));
						argc--;
					}
				}
			}
			else // Es usuario comun y no es el primer logueo
			{
				do
				{
					if(argc==0)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Eres un simple usuario y no es tu primer logueo." << endl;
						cout << "Por favor ingresa tu contraseña" << endl;
						cout << "> ";
						getline(cin,contrasenia);
					}
					else
					{
						contrasenia=string(va_arg(p,char *));
						argc--;
					}
					contraseniaIncorrecta=iU->ingresarContrasenia(contrasenia);

					if(contraseniaIncorrecta)
					{
						if(argc==0)
						{
							system("clear");
							cout << "INCIO DE SESION" << endl;
							cout << "---------------" << endl;
							cout << "Oops. Has ingresado una contraseña incorrecta. ¿Quieres volver a probar? [1/0]" << endl;
							cout << "> ";
							getline(cin,buffer);
						}
						else
						{
							buffer=string(va_arg(p,char *));
							argc--;
						}

						volverAIngresar=(buffer=="1");

					}

				}while(contraseniaIncorrecta && volverAIngresar);

				if(!infoLogueo.isActivo()) //SI ES INACTIVO
				{
					if(argc==0)
					{
						system("clear");
						cout << "INCIO DE SESION" << endl;
						cout << "---------------" << endl;
						cout << "Su usuario está inactivo y no puede loguearse. Enter para continuar" << endl;
						getline(cin,buffer);
					}
					else
					{
						buffer=string(va_arg(p,char *));
						argc--;
					}

				}
				else // ES ACTIVO
					if(!contraseniaIncorrecta)
					{
						exito=true;
						iU->asignarSesionUsuario();
						if(argc==0)
						{
							system("clear");
							cout << "INCIO DE SESION" << endl;
							cout << "---------------" << endl;

							cout << "Tu sesion ha sido iniciada. Enter para continuar" << endl;
							getline(cin,buffer);
						}
						else
						{
							buffer=string(va_arg(p,char *));
							argc--;
						}
					}
			}
		}
	}
	else
	{
		if(argc==0)
		{
			system("clear");
			cout << "INCIO DE SESION" << endl;
			cout << "---------------" << endl;
			cout << "No existe un usuario con esa CI. Enter para continuar" << endl;
			getline(cin,buffer);
		}
		else
		{
			buffer=string(va_arg(p,char *));
			argc--;
		}
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

				cout << "Ingrese la fecha de nacimiento:" << endl;
				fecha=ingresoFecha();

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

void AltaReprEstandarizadaDeDiagnosticos()
{
/*	bool deseaCategorias=true;
	IDiagnostico* iD=Factory::getIDiagnostico();
	string buffer;
	string codigoCat;
	string etiquetaCat;


	while ( deseaCategorias )
	{
		set<DTCategoriaPS> categorias=iD->obtenerCategorias();

		system("clear");
		cout << "ALTA REPRESENTACION ESTANDARIZADA DE DIAGNOSTICO" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Estas son las categorias del sistema:" << endl;

		set<DTCategoriaPS>::iterator it;
		for ( it=categorias.begin() ; it != categorias.end() ; ++it )
			cout << (*it) << endl;
		cout << "Seleccione la categoria de su elección. (Escriba NO para crear una nueva)" << endl;
		cout << "> ";
		getline(cin,buffer);

		if(buffer == "NO") // Usuario no encuentra categoria
		{
			system("clear");
			cout << "ALTA REPRESENTACION ESTANDARIZADA DE DIAGNOSTICO" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Crearemos una nueva categoria:" << endl;
			cout << "Ingrese el codigo:" << endl;
			cout << "> ";
			getline(cin,codigoCat);
			cout << "Ingrese la etiqueta" << endl;
			cout << "> ";
			getline(cin,etiquetaCat);
			iD->agregarCategoria(codigoCat,etiquetaCat);
		}
		else
		{
			if(buffer.size()>1)
				throw invalid_argument("El codigo de categorias tiene una sola letra");
			else
				iD->seleccionarCategoria(buffer);
		}


	}*/
}

void RegistroConsulta(){}
void AltaDiagnosticosDeUnaConsulta(){}
void ObtenerHistorialPaciente(){}
void ListarRepresentacionesEstandarizadas(){}

void ReservaConsulta()
{
	IConsulta* iC=Factory::getIConsulta();
	set<DTMedico> listaMedicos;
	string ciMedico;
	string buffer;
	int hora;
	int minuto;

	system("clear");
	cout << "RESERVAR CONSULTA" << endl;
	cout << "-----------------" << endl;
	cout << "Estos son los medicos del sistema:" << endl;
	listaMedicos = iC->listarMedicos();

	set<DTMedico>::iterator it;
	for ( it = listaMedicos.begin() ; it != listaMedicos.end() ; ++it)
		cout << (*it) << endl;

	cout << "Ingrese la CI del medico de su eleccion:" << endl;
	cout << "> ";
	getline(cin,ciMedico);
	cout << "Ingrese la fecha de consulta:" << endl;
	Fecha fecha=ingresoFecha();
	cout << "Ingrese la hora de consulta:" << endl;
	cout << "> ";
	getline(cin,buffer);
	hora=atoi(buffer.c_str());
	cout << "Ingrese la minuto de consulta:" << endl;
	cout << "> ";
	getline(cin,buffer);
	minuto=atoi(buffer.c_str());
	Hora horaConsulta(hora,minuto);

	iC->reservarConsulta(ciMedico,fecha,horaConsulta);

	system("clear");
	cout << "RESERVAR CONSULTA" << endl;
	cout << "-----------------" << endl;
	cout << "Se ha dado de alta la reserva. Enter para continuar" << endl;
	getline(cin,buffer);


	delete iC;
}

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

Fecha ingresoFecha()
{
	int dia;
	int mes;
	int anio;
	string buffer;

	cout << "Ingrese el dia:" << endl;
	cout << "> ";
	getline(cin,buffer);
	dia=atoi(buffer.c_str());
	cout << "Ingrese el mes:" << endl;
	cout << "> ";
	getline(cin,buffer);
	mes=atoi(buffer.c_str());
	cout << "Ingrese el año:" << endl;
	cout << "> ";
	getline(cin,buffer);
	anio=atoi(buffer.c_str());

	Fecha fecha(dia,mes,anio);
	return fecha;
}
