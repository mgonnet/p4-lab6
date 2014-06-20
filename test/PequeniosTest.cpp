/*
 * PequeñosTest.cpp
 *
 *  Created on: 20/06/2014
 *      Author: matias
 */

#include <limits.h>
#include "gtest-1.7.0/include/gtest/gtest.h"

#include "../headers/clases/FechaSistema.h"
#include "../headers/dataTypes/FechaHora.h"

TEST(FechaSistema,CalculoDeEdad)
{
	Fecha fecha(21,2,1993);
	FechaSistema* fSis=FechaSistema::getInstance();
	fSis->setFechaSistema(Fecha(18,6,2014));

	ASSERT_EQ(21,fecha.calcularEdad());

	Fecha fecha2(21,9,1993);
	ASSERT_EQ(20,fecha2.calcularEdad());

	Fecha fecha3(19,6,1993);
	ASSERT_EQ(20,fecha3.calcularEdad());

	Fecha fecha4(18,6,1993);
	ASSERT_EQ(21,fecha4.calcularEdad());
}




