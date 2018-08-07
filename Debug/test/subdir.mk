################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../test/FechaHora.o \
../test/MedicoNotificable.o \
../test/Mensaje.o \
../test/medicoNotificableTest.o 

CPP_SRCS += \
../test/medicoNotificableTest.cpp 

OBJS += \
./test/medicoNotificableTest.o 

CPP_DEPS += \
./test/medicoNotificableTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


