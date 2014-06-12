################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/clases/Accion.cpp \
../source/clases/AccionMensaje.cpp \
../source/clases/Administrativo.cpp \
../source/clases/CategoriaPS.cpp \
../source/clases/Comun.cpp \
../source/clases/Consulta.cpp \
../source/clases/Diagnostico.cpp \
../source/clases/Emergencia.cpp \
../source/clases/Farmacologico.cpp \
../source/clases/Logueo.cpp \
../source/clases/Medicamento.cpp \
../source/clases/Medico.cpp \
../source/clases/MedicoNotificable.cpp \
../source/clases/Mensaje.cpp \
../source/clases/Observer.cpp \
../source/clases/ProblemaSalud.cpp \
../source/clases/Quirurgico.cpp \
../source/clases/Singleton.cpp \
../source/clases/Socio.cpp \
../source/clases/Subject.cpp \
../source/clases/Tratamiento.cpp \
../source/clases/Usuario.cpp 

OBJS += \
./source/clases/Accion.o \
./source/clases/AccionMensaje.o \
./source/clases/Administrativo.o \
./source/clases/CategoriaPS.o \
./source/clases/Comun.o \
./source/clases/Consulta.o \
./source/clases/Diagnostico.o \
./source/clases/Emergencia.o \
./source/clases/Farmacologico.o \
./source/clases/Logueo.o \
./source/clases/Medicamento.o \
./source/clases/Medico.o \
./source/clases/MedicoNotificable.o \
./source/clases/Mensaje.o \
./source/clases/Observer.o \
./source/clases/ProblemaSalud.o \
./source/clases/Quirurgico.o \
./source/clases/Singleton.o \
./source/clases/Socio.o \
./source/clases/Subject.o \
./source/clases/Tratamiento.o \
./source/clases/Usuario.o 

CPP_DEPS += \
./source/clases/Accion.d \
./source/clases/AccionMensaje.d \
./source/clases/Administrativo.d \
./source/clases/CategoriaPS.d \
./source/clases/Comun.d \
./source/clases/Consulta.d \
./source/clases/Diagnostico.d \
./source/clases/Emergencia.d \
./source/clases/Farmacologico.d \
./source/clases/Logueo.d \
./source/clases/Medicamento.d \
./source/clases/Medico.d \
./source/clases/MedicoNotificable.d \
./source/clases/Mensaje.d \
./source/clases/Observer.d \
./source/clases/ProblemaSalud.d \
./source/clases/Quirurgico.d \
./source/clases/Singleton.d \
./source/clases/Socio.d \
./source/clases/Subject.d \
./source/clases/Tratamiento.d \
./source/clases/Usuario.d 


# Each subdirectory must supply rules for building sources it contributes
source/clases/%.o: ../source/clases/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


