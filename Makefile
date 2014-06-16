GTEST_DIR = /usr/include/gtest-1.7.0

USER_DIR = .

CPPFLAGS += -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = sample1_unittest SocioRobadoTest

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


DT= FechaHora.o DTCategoriaPS.o DTMedico.o DTDiagnostico.o DTConsulta.o DTMedicamento.o DTDiagnosticoAlta.o DTTratamiento.o DTSocio.o DTHistorial.o DTInfoLogueo.o DTProblemaSalud.o DTReprEstandarizada.o DTReservaA.o DTUser.o   
clases= Parametro.o ParametroAccionMensaje.o Observer.o Mensaje.o MedicoNotificable.o Accion.o AccionMensaje.o Subject.o Socio.o StockAcciones.o

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

# Clases

StockAcciones.o : $(USER_DIR)/$(sC)/StockAcciones.cpp $(USER_DIR)/$(hC)/StockAcciones.h Accion.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/StockAcciones.cpp
	
Subject.o : $(USER_DIR)/$(sC)/Subject.cpp $(USER_DIR)/$(hC)/Subject.h Observer.o Parametro.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Subject.cpp

Socio.o : $(USER_DIR)/$(sC)/Subject.cpp $(USER_DIR)/$(hC)/Socio.h Subject.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Socio.cpp
	
Observer.o : $(USER_DIR)/$(sC)/Observer.cpp $(USER_DIR)/$(hC)/Observer.h Parametro.o Subject.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Observer.cpp

Mensaje.o : $(USER_DIR)/$(sC)/Mensaje.cpp $(USER_DIR)/$(hC)/Mensaje.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Mensaje.cpp

Accion.o : $(USER_DIR)/$(sC)/Accion.cpp $(USER_DIR)/$(hC)/Accion.h $(USER_DIR)/$(hDT)/Parametro.h MedicoNotificable.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/Accion.cpp
	
AccionMensaje.o : $(USER_DIR)/$(sC)/AccionMensaje.cpp $(USER_DIR)/$(hC)/AccionMensaje.h Accion.o $(USER_DIR)/$(hDT)/Parametro.h MedicoNotificable.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/AccionMensaje.cpp
	
MedicoNotificable.o : $(USER_DIR)/$(sC)/MedicoNotificable.cpp $(USER_DIR)/$(hC)/MedicoNotificable.h Mensaje.o Observer.o ParametroAccionMensaje.o $(USER_DIR)/$(hC)/Accion.h StockAcciones.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/$(sC)/MedicoNotificable.cpp

#Poner aca los Test
medicoNotificableTest.o : $(USER_DIR)/test/medicoNotificableTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/medicoNotificableTest.cpp

sample1_unittest : $(DT) $(clases) medicoNotificableTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SocioRobadoTest.o : $(USER_DIR)/test/SocioRobadoTest.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/test/SocioRobadoTest.cpp
	
SocioRobadoTest : $(DT) $(clases) SocioRobadoTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	
#Aca se compila el MAIN
main.o : $(DT) $(clases) main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c main.cpp

lab6 : main.o $(DT) $(clases)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	