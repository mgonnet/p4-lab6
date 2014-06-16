################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Accion.o \
../AccionMensaje.o \
../DTCategoriaPS.o \
../DTConsulta.o \
../DTDiagnostico.o \
../DTDiagnosticoAlta.o \
../DTHistorial.o \
../DTInfoLogueo.o \
../DTMedicamento.o \
../DTMedico.o \
../DTProblemaSalud.o \
../DTReprEstandarizada.o \
../DTReservaA.o \
../DTSocio.o \
../DTTratamiento.o \
../DTUser.o \
../FechaHora.o \
../MedicoNotificable.o \
../Mensaje.o \
../Observer.o \
../Parametro.o \
../ParametroAccionMensaje.o \
../Socio.o \
../SocioRobadoTest.o \
../StockAcciones.o \
../Subject.o \
../gtest-all.o \
../gtest_main.o \
../medicoNotificableTest.o 

CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


