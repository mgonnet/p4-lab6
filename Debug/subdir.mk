################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Accion.o \
../AccionMensaje.o \
../Administrativo.o \
../Almacen.o \
../CConsulta.o \
../CDiagnostico.o \
../CUsuario.o \
../CategoriaPS.o \
../Consulta.o \
../DTCategoriaPS.o \
../DTConsulta.o \
../DTConsultaDia.o \
../DTDiagnostico.o \
../DTDiagnosticoAlta.o \
../DTHistorial.o \
../DTInfoLogueo.o \
../DTLineaRegistro.o \
../DTMedicamento.o \
../DTMedico.o \
../DTProblemaSalud.o \
../DTReprEstandarizada.o \
../DTReservaA.o \
../DTSocio.o \
../DTTratamiento.o \
../DTUser.o \
../DTUsuarioAR.o \
../Diagnostico.o \
../Factory.o \
../Farmacologico.o \
../FechaHora.o \
../FechaSistema.o \
../LineaRegistroAR.o \
../Logueo.o \
../Medicamento.o \
../Medico.o \
../MedicoNotificable.o \
../Mensaje.o \
../Observer.o \
../Parametro.o \
../ParametroAccionMensaje.o \
../ProblemaSalud.o \
../Quirurgico.o \
../RegistroAR.o \
../Socio.o \
../StockAcciones.o \
../Subject.o \
../Tratamiento.o \
../Usuario.o \
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


