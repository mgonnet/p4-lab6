GTEST_DIR = /usr/include/gtest-1.7.0

USER_DIR = .

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = medicoNotificableTest SocioRobadoTest SesionTest PequeniosTest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all: lab6

test : $(TESTS)

clean :
	rm -f $(TESTS) *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


# Tocar solo de aca para abajo

sDT= source/dataTypes
hDT= headers/dataTypes
sC= source/clases
hC= headers/clases
sCI= source/interfacesYControladores
hCI= headers/interfacesYControladores


DT= FechaHora.o DTCategoriaPS.o DTMedico.o DTDiagnostico.o DTConsulta.o DTMedicamento.o DTDiagnosticoAlta.o DTTratamiento.o DTSocio.o DTHistorial.o DTInfoLogueo.o DTProblemaSalud.o DTReprEstandarizada.o DTReservaA.o DTUser.o DTConsultaDia.o DTUsuarioAR.o DTLineaRegistro.o
clases= Quirurgico.o Farmacologico.o Tratamiento.o ProblemaSalud.o CategoriaPS.o ProblemaSalud.o Medicamento.o Almacen.o Parametro.o ParametroAccionMensaje.o Observer.o Mensaje.o MedicoNotificable.o Accion.o AccionMensaje.o Subject.o Socio.o StockAcciones.o Usuario.o Logueo.o FechaSistema.o Administrativo.o RegistroAR.o LineaRegistroAR.o Medico.o Consulta.o  
interControl= CUsuario.o CConsulta.o CDiagnostico.o Factory.o

#DataTypes
DTUser.o : $(USER_DIR)/$(sDT)/DTUser.cpp $(USER_DIR)/$(hDT)/DTUser.h $(USER_DIR)/$(hDT)/Sexo.h $(USER_DIR)/$(hDT)/Rol.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTUser.cpp
	
DTProblemaSalud.o : $(USER_DIR)/$(sDT)/DTProblemaSalud.cpp $(USER_DIR)/$(hDT)/DTProblemaSalud.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTProblemaSalud.cpp

DTReprEstandarizada.o : $(USER_DIR)/$(sDT)/DTReprEstandarizada.cpp $(USER_DIR)/$(hDT)/DTReprEstandarizada.h DTProblemaSalud.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTReprEstandarizada.cpp
	
DTInfoLogueo.o : $(USER_DIR)/$(sDT)/DTInfoLogueo.cpp $(USER_DIR)/$(hDT)/DTInfoLogueo.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTInfoLogueo.cpp
	
FechaHora.o : $(USER_DIR)/$(sDT)/FechaHora.cpp $(USER_DIR)/$(hDT)/FechaHora.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/FechaHora.cpp

DTReservaA.o : $(USER_DIR)/$(sDT)/DTReservaA.cpp $(USER_DIR)/$(hDT)/DTReservaA.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTReservaA.cpp
		
DTCategoriaPS.o : $(USER_DIR)/$(sDT)/DTCategoriaPS.cpp $(USER_DIR)/$(hDT)/DTCategoriaPS.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTCategoriaPS.cpp

DTMedico.o : $(USER_DIR)/$(sDT)/DTMedico.cpp $(USER_DIR)/$(hDT)/DTMedico.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTMedico.cpp
	
DTDiagnostico.o : $(USER_DIR)/$(sDT)/DTDiagnostico.cpp $(USER_DIR)/$(hDT)/DTDiagnostico.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTDiagnostico.cpp
		
DTConsulta.o : $(USER_DIR)/$(sDT)/DTConsulta.cpp $(USER_DIR)/$(hDT)/DTConsulta.h FechaHora.o $(USER_DIR)/$(hDT)/TipoConsulta.h DTMedico.o DTDiagnostico.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTConsulta.cpp
	
DTMedicamento.o : $(USER_DIR)/$(sDT)/DTMedicamento.cpp $(USER_DIR)/$(hDT)/DTMedicamento.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTMedicamento.cpp

DTConsultaDia.o : $(USER_DIR)/$(sDT)/DTConsultaDia.cpp $(USER_DIR)/$(hDT)/DTConsultaDia.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTConsultaDia.cpp
		
DTTratamiento.o : $(USER_DIR)/$(sDT)/DTTratamiento.cpp $(USER_DIR)/$(hDT)/DTTratamiento.h $(USER_DIR)/$(hDT)/TipoTratamiento.h DTMedicamento.o FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTTratamiento.cpp
	
DTDiagnosticoAlta.o : $(USER_DIR)/$(sDT)/DTDiagnosticoAlta.cpp $(USER_DIR)/$(hDT)/DTDiagnosticoAlta.h DTTratamiento.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTDiagnosticoAlta.cpp

DTSocio.o : $(USER_DIR)/$(sDT)/DTSocio.cpp $(USER_DIR)/$(hDT)/DTSocio.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTSocio.cpp
	
DTHistorial.o : $(USER_DIR)/$(sDT)/DTHistorial.cpp $(USER_DIR)/$(hDT)/DTHistorial.h DTConsulta.o DTSocio.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTHistorial.cpp

Parametro.o : $(USER_DIR)/$(sDT)/Parametro.cpp $(USER_DIR)/$(hDT)/Parametro.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/Parametro.cpp
		
ParametroAccionMensaje.o : $(USER_DIR)/$(sDT)/ParametroAccionMensaje.cpp $(USER_DIR)/$(hDT)/ParametroAccionMensaje.h Parametro.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/ParametroAccionMensaje.cpp
	
DTUsuarioAR.o : $(USER_DIR)/$(sDT)/DTUsuarioAR.cpp $(USER_DIR)/$(hDT)/DTUsuarioAR.h DTLineaRegistro.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTUsuarioAR.cpp

DTLineaRegistro.o : $(USER_DIR)/$(sDT)/DTLineaRegistro.cpp $(USER_DIR)/$(hDT)/DTLineaRegistro.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sDT)/DTLineaRegistro.cpp
	
# Clases

Socio.o : $(USER_DIR)/$(sC)/Socio.cpp $(USER_DIR)/$(hC)/Socio.h Consulta.o Subject.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Socio.cpp
	
Consulta.o : $(USER_DIR)/$(sC)/Consulta.cpp $(USER_DIR)/$(hC)/Consulta.h DTConsulta.o DTReservaA.o FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Consulta.cpp
	
Medico.o : $(USER_DIR)/$(sC)/Medico.cpp $(USER_DIR)/$(hC)/Medico.h Consulta.o DTConsulta.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Medico.cpp
	
LineaRegistroAR.o : $(USER_DIR)/$(sC)/LineaRegistroAR.cpp $(USER_DIR)/$(hC)/LineaRegistroAR.h DTLineaRegistro.o FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/LineaRegistroAR.cpp
	
RegistroAR.o : $(USER_DIR)/$(sC)/RegistroAR.cpp $(USER_DIR)/$(hC)/RegistroAR.h DTUsuarioAR.o DTLineaRegistro.o LineaRegistroAR.o Usuario.o Administrativo.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/RegistroAR.cpp
	
Administrativo.o : $(USER_DIR)/$(sC)/Administrativo.cpp $(USER_DIR)/$(hC)/Administrativo.h DTUsuarioAR.o FechaSistema.o RegistroAR.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Administrativo.cpp
	
FechaSistema.o : $(USER_DIR)/$(sC)/FechaSistema.cpp $(USER_DIR)/$(hC)/FechaSistema.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/FechaSistema.cpp

Quirurgico.o : $(USER_DIR)/$(sC)/Quirurgico.cpp $(USER_DIR)/$(hC)/Quirurgico.h FechaHora.o Tratamiento.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Quirurgico.cpp
	
Farmacologico.o : $(USER_DIR)/$(sC)/Farmacologico.cpp $(USER_DIR)/$(hC)/Farmacologico.h Medicamento.o Tratamiento.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Farmacologico.cpp
	
Tratamiento.o : $(USER_DIR)/$(sC)/Tratamiento.cpp $(USER_DIR)/$(hC)/Tratamiento.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Tratamiento.cpp
	
Diagnostico.o : $(USER_DIR)/$(sC)/Diagnostico.cpp $(USER_DIR)/$(hC)/Diagnostico.h Tratamiento.o Farmacologico.o Quirurgico.o ProblemaSalud.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Diagnostico.cpp

CategoriaPS.o : $(USER_DIR)/$(sC)/CategoriaPS.cpp $(USER_DIR)/$(hC)/CategoriaPS.h ProblemaSalud.o DTReprEstandarizada.o DTProblemaSalud.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/CategoriaPS.cpp
	
ProblemaSalud.o : $(USER_DIR)/$(sC)/ProblemaSalud.cpp $(USER_DIR)/$(hC)/ProblemaSalud.h Diagnostico.o CategoriaPS.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/ProblemaSalud.cpp
	
Medicamento.o : $(USER_DIR)/$(sC)/Medicamento.cpp $(USER_DIR)/$(hC)/Medicamento.h Farmacologico.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Medicamento.cpp
	
Almacen.o : $(USER_DIR)/$(sCI)/Almacen.cpp $(USER_DIR)/$(hCI)/Almacen.h Medicamento.o CategoriaPS.o Usuario.o ProblemaSalud.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sCI)/Almacen.cpp
	
StockAcciones.o : $(USER_DIR)/$(sC)/StockAcciones.cpp $(USER_DIR)/$(hC)/StockAcciones.h Accion.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/StockAcciones.cpp
	
Subject.o : $(USER_DIR)/$(sC)/Subject.cpp $(USER_DIR)/$(hC)/Subject.h Observer.o Parametro.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Subject.cpp
	
Observer.o : $(USER_DIR)/$(sC)/Observer.cpp $(USER_DIR)/$(hC)/Observer.h Parametro.o Subject.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Observer.cpp

Mensaje.o : $(USER_DIR)/$(sC)/Mensaje.cpp $(USER_DIR)/$(hC)/Mensaje.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Mensaje.cpp

Accion.o : $(USER_DIR)/$(sC)/Accion.cpp $(USER_DIR)/$(hC)/Accion.h $(USER_DIR)/$(hDT)/Parametro.h MedicoNotificable.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Accion.cpp
	
AccionMensaje.o : $(USER_DIR)/$(sC)/AccionMensaje.cpp $(USER_DIR)/$(hC)/AccionMensaje.h Accion.o $(USER_DIR)/$(hDT)/Parametro.h MedicoNotificable.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/AccionMensaje.cpp
	
MedicoNotificable.o : $(USER_DIR)/$(sC)/MedicoNotificable.cpp $(USER_DIR)/$(hC)/MedicoNotificable.h Mensaje.o Observer.o ParametroAccionMensaje.o Accion.o StockAcciones.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/MedicoNotificable.cpp
	
Logueo.o : $(USER_DIR)/$(sC)/Logueo.cpp $(USER_DIR)/$(hC)/Logueo.h Usuario.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Logueo.cpp	

Usuario.o : $(USER_DIR)/$(sC)/Usuario.cpp $(USER_DIR)/$(hC)/Usuario.h DTInfoLogueo.o  $(USER_DIR)/$(hDT)/Sexo.h FechaHora.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Usuario.cpp
	
#Interfaces Y Controladores

CUsuario.o : $(USER_DIR)/$(sCI)/CUsuario.cpp $(USER_DIR)/$(hCI)/CUsuario.h Usuario.o Almacen.o DTInfoLogueo.o  DTUser.o $(USER_DIR)/$(hCI)/IUsuario.h FechaHora.o Logueo.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sCI)/CUsuario.cpp
	
CConsulta.o : $(USER_DIR)/$(sCI)/CConsulta.cpp $(USER_DIR)/$(hCI)/CConsulta.h $(USER_DIR)/$(hCI)/IConsulta.h DTConsultaDia.o DTConsulta.o DTDiagnostico.o FechaHora.o DTMedico.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sCI)/CConsulta.cpp
	
CDiagnostico.o : $(USER_DIR)/$(sCI)/CDiagnostico.cpp $(USER_DIR)/$(hCI)/CDiagnostico.h $(USER_DIR)/$(hCI)/IDiagnostico.h DTReprEstandarizada.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sCI)/CDiagnostico.cpp
	
Factory.o : $(USER_DIR)/$(sCI)/Factory.cpp $(USER_DIR)/$(hCI)/Factory.h $(USER_DIR)/$(hCI)/CDiagnostico.h $(USER_DIR)/$(hCI)/IDiagnostico.h $(USER_DIR)/$(hCI)/IUsuario.h CConsulta.o CUsuario.o CDiagnostico.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sCI)/Factory.cpp	

#Poner aca los Test
medicoNotificableTest.o : $(USER_DIR)/test/medicoNotificableTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/medicoNotificableTest.cpp

medicoNotificableTest : $(DT) $(clases) $(interControl) medicoNotificableTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SocioRobadoTest.o : $(USER_DIR)/test/SocioRobadoTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/SocioRobadoTest.cpp
	
SocioRobadoTest : $(DT) $(clases) $(interControl) SocioRobadoTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
SesionTest.o : $(USER_DIR)/test/SesionTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/SesionTest.cpp
	
SesionTest : $(DT) $(clases) $(interControl) SesionTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

PequeniosTest.o : $(USER_DIR)/test/PequeniosTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/PequeniosTest.cpp
		
PequeniosTest : $(DT) $(clases) $(interControl) PequeniosTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
#Aca se compila el MAIN
main.o : $(DT) $(clases) main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.cpp

lab6 : main.o $(DT) $(clases) $(interControl)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
# Otras cosas

runtest:
	./medicoNotificableTest
	./SocioRobadoTest
	./SesionTest
	./PequeniosTest