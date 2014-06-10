hDT=headers/dataTypes
sDT=source/dataTypes
objDir=obj

all: lab6

lab6: main.o FechaHora.o
	g++ main.o $(objDir)/FechaHora.o -o lab6

main.o: main.cpp
	g++ -c main.cpp

DTCategoriaPS.o: $(hDT)/DTCategoriaPS.h $(sDT)/DTCategoriaPS.cpp
	g++ -c source/dataTypes/DTCategoriaPS.cpp -o obj/DTCategoriaPS.o

DTConsulta.o: $(hDT)/DTConsulta.h $(sDT)/DTConsulta.cpp FechaHora.o DTMedico.o DTDiagnostico.o DTMedico.o DTDiagnostico.o DTDiagnostico.o TipoConsulta.
	g++ -c source/dataTypes/DTConsulta.cpp -o obj/DTConsulta.o

DTDiagnostico.o: $(hDT)/DTDiagnostico.h $(sDT)/DTDiagnostico.cpp
	g++ -c source/dataTypes/DTDiagnostico.cpp -o obj/DTDiagnostico.o

DTDiagnosticoAlta.o: $(hDT)/DTDiagnosticoAlta.h $(sDT)/DTDiagnosticoAlta.cpp $(hDT)/DTTratamiento.h $(sDT)/DTTratamiento.cpp
	g++ -c source/dataTypes/DTDiagnosticoAlta.cpp -o obj/DTDiagnosticoAlta.o

DTHistorial.o: $(hDT)/DTHistorial.h $(sDT)/DTHistorial.cpp $(hDT)/DTConsulta.h $(sDT)/DTConsulta.cpp $(hDT)/DTSocio.h $(sDT)/DTSocio.cpp
	g++ -c source/dataTypes/DTHistorial.cpp -o obj/DTHistorial.o

DTInfoLogueo.o: $(hDT)/DTInfoLogueo.h $(sDT)/DTInfoLogueo.cpp
	g++ -c source/dataTypes/DTInfoLogueo.cpp -o obj/DTInfoLogueo.o

DTMedicamento.o: $(hDT)/DTMedicamento.h $(sDT)/DTMedicamento.cpp
	g++ -c source/dataTypes/DTMedicamento.cpp -o obj/DTMedicamento.o

DTMedico.o: $(hDT)/DTMedico.h $(sDT)/DTMedico.cpp
	g++ -c source/dataTypes/DTMedico.cpp -o obj/DTMedico.o

DTProblemaSalud.o: $(hDT)/DTProblemaSalud.h $(sDT)/DTProblemaSalud.cpp
	g++ -c source/dataTypes/DTProblemaSalud.cpp -o obj/DTProblemaSalud.o

DTReprEstandarizada.o: $(hDT)/DTReprEstandarizada.h $(sDT)/DTReprEstandarizada.cpp
	g++ -c source/dataTypes/DTReprEstandarizada.cpp -o obj/DTReprEstandarizada.o

DTReservaA.o: $(hDT)/DTReservaA.h $(sDT)/DTReservaA.cpp $(hDT)/FechaHora.h $(sDT)/FechaHora.cpp
	g++ -c source/dataTypes/DTReservaA.cpp -o obj/DTReservaA.o

DTSocio.o: $(hDT)/DTSocio.h $(sDT)/DTSocio.cpp $(hDT)/FechaHora.h $(sDT)/FechaHora.cpp
	g++ -c source/dataTypes/DTSocio.cpp -o obj/DTSocio.o

DTTratamiento.o: $(hDT)/DTTratamiento.h $(sDT)/DTTratamiento.cpp $(hDT)/TipoTratamiento.h $(hDT)/DTMedicamento.h $(sDT)/DTMedicamento.cpp
	g++ -c source/dataTypes/DTTratamiento.cpp -o obj/DTTratamiento.o

FechaHora.o: $(hDT)/FechaHora.h $(sDT)/FechaHora.cpp
	g++ -c $(sDT)/FechaHora.cpp -o $(objDir)/FechaHora.o

