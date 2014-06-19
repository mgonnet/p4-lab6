/*
 * SesionTest.cpp
 *
 *  Created on: 17/06/2014
 *      Author: matias
 */

#include <limits.h>
#include "gtest-1.7.0/include/gtest/gtest.h"

#include "../headers/clases/Usuario.h"
#include "../headers/dataTypes/DTInfoLogueo.h"
#include "../headers/clases/Logueo.h"
#include "../headers/interfacesYControladores/IUsuario.h"
#include "../headers/interfacesYControladores/CUsuario.h"
#include "../headers/interfacesYControladores/Almacen.h"

class SesionTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		Fecha fecha(21,21,21);
		usuario1=new Usuario("Juan","Perez","4855460",MASCULINO,fecha,true,21,false,true);

		Almacen* alm=Almacen::getInstance();
		alm->addUsuario(usuario1);
	}

	virtual void TearDown()
	{
		Logueo* logueo=Logueo::getInstance();
		delete logueo;
		Almacen* alm=Almacen::getInstance();
		delete alm;
	}

	Usuario* usuario1;
};

TEST_F(SesionTest,IniciarSesionPrimerLogueo)
{
	IUsuario* iUsuario=new CUsuario;  // CUIDADO: debería usar la Fabrica

	iUsuario->comienzoInicioSesion("4855460");
	iUsuario->crearContrasenia("passfrutera");
	iUsuario->asignarSesionUsuario();

	delete iUsuario;

	ASSERT_EQ("passfrutera",usuario1->getContrasenia()); // Se guardo la contrasenia que queria

	Logueo* logueo=Logueo::getInstance();
	ASSERT_EQ(usuario1,logueo->getUsuario()); // Miro que se haya creado el link

	ASSERT_EQ(false,usuario1->getPrimerLogueo()); // Miro que se haya actualizado primerLogueo
}



