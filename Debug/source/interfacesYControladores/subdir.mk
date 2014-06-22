################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/interfacesYControladores/Almacen.cpp \
../source/interfacesYControladores/CConsulta.cpp \
../source/interfacesYControladores/CDiagnostico.cpp \
../source/interfacesYControladores/CUsuario.cpp \
../source/interfacesYControladores/Factory.cpp 

OBJS += \
./source/interfacesYControladores/Almacen.o \
./source/interfacesYControladores/CConsulta.o \
./source/interfacesYControladores/CDiagnostico.o \
./source/interfacesYControladores/CUsuario.o \
./source/interfacesYControladores/Factory.o 

CPP_DEPS += \
./source/interfacesYControladores/Almacen.d \
./source/interfacesYControladores/CConsulta.d \
./source/interfacesYControladores/CDiagnostico.d \
./source/interfacesYControladores/CUsuario.d \
./source/interfacesYControladores/Factory.d 


# Each subdirectory must supply rules for building sources it contributes
source/interfacesYControladores/%.o: ../source/interfacesYControladores/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


