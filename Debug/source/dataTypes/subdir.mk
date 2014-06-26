################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/dataTypes/DTCategoriaPS.cpp \
../source/dataTypes/DTCombinado.cpp \
../source/dataTypes/DTConsulta.cpp \
../source/dataTypes/DTConsultaDia.cpp \
../source/dataTypes/DTDiagnostico.cpp \
../source/dataTypes/DTDiagnosticoAlta.cpp \
../source/dataTypes/DTHistorial.cpp \
../source/dataTypes/DTInfoLogueo.cpp \
../source/dataTypes/DTLineaRegistro.cpp \
../source/dataTypes/DTMedicamento.cpp \
../source/dataTypes/DTMedico.cpp \
../source/dataTypes/DTProblemaSalud.cpp \
../source/dataTypes/DTReprEstandarizada.cpp \
../source/dataTypes/DTReservaA.cpp \
../source/dataTypes/DTSocio.cpp \
../source/dataTypes/DTTratamiento.cpp \
../source/dataTypes/DTUser.cpp \
../source/dataTypes/DTUsuarioAR.cpp \
../source/dataTypes/FechaHora.cpp \
../source/dataTypes/Parametro.cpp \
../source/dataTypes/ParametroAccionMensaje.cpp 

OBJS += \
./source/dataTypes/DTCategoriaPS.o \
./source/dataTypes/DTCombinado.o \
./source/dataTypes/DTConsulta.o \
./source/dataTypes/DTConsultaDia.o \
./source/dataTypes/DTDiagnostico.o \
./source/dataTypes/DTDiagnosticoAlta.o \
./source/dataTypes/DTHistorial.o \
./source/dataTypes/DTInfoLogueo.o \
./source/dataTypes/DTLineaRegistro.o \
./source/dataTypes/DTMedicamento.o \
./source/dataTypes/DTMedico.o \
./source/dataTypes/DTProblemaSalud.o \
./source/dataTypes/DTReprEstandarizada.o \
./source/dataTypes/DTReservaA.o \
./source/dataTypes/DTSocio.o \
./source/dataTypes/DTTratamiento.o \
./source/dataTypes/DTUser.o \
./source/dataTypes/DTUsuarioAR.o \
./source/dataTypes/FechaHora.o \
./source/dataTypes/Parametro.o \
./source/dataTypes/ParametroAccionMensaje.o 

CPP_DEPS += \
./source/dataTypes/DTCategoriaPS.d \
./source/dataTypes/DTCombinado.d \
./source/dataTypes/DTConsulta.d \
./source/dataTypes/DTConsultaDia.d \
./source/dataTypes/DTDiagnostico.d \
./source/dataTypes/DTDiagnosticoAlta.d \
./source/dataTypes/DTHistorial.d \
./source/dataTypes/DTInfoLogueo.d \
./source/dataTypes/DTLineaRegistro.d \
./source/dataTypes/DTMedicamento.d \
./source/dataTypes/DTMedico.d \
./source/dataTypes/DTProblemaSalud.d \
./source/dataTypes/DTReprEstandarizada.d \
./source/dataTypes/DTReservaA.d \
./source/dataTypes/DTSocio.d \
./source/dataTypes/DTTratamiento.d \
./source/dataTypes/DTUser.d \
./source/dataTypes/DTUsuarioAR.d \
./source/dataTypes/FechaHora.d \
./source/dataTypes/Parametro.d \
./source/dataTypes/ParametroAccionMensaje.d 


# Each subdirectory must supply rules for building sources it contributes
source/dataTypes/%.o: ../source/dataTypes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


