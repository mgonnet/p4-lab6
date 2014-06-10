################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/dataTypes/DTCategoriaPS.cpp \
../source/dataTypes/DTInfoLogueo.cpp \
../source/dataTypes/DTSocio.cpp \
../source/dataTypes/DTUser.cpp \
../source/dataTypes/FechaHora.cpp 

OBJS += \
./source/dataTypes/DTCategoriaPS.o \
./source/dataTypes/DTInfoLogueo.o \
./source/dataTypes/DTSocio.o \
./source/dataTypes/DTUser.o \
./source/dataTypes/FechaHora.o 

CPP_DEPS += \
./source/dataTypes/DTCategoriaPS.d \
./source/dataTypes/DTInfoLogueo.d \
./source/dataTypes/DTSocio.d \
./source/dataTypes/DTUser.d \
./source/dataTypes/FechaHora.d 


# Each subdirectory must supply rules for building sources it contributes
source/dataTypes/%.o: ../source/dataTypes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


