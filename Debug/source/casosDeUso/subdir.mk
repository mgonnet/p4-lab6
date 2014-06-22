################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/casosDeUso/CasosDeUso.cpp 

OBJS += \
./source/casosDeUso/CasosDeUso.o 

CPP_DEPS += \
./source/casosDeUso/CasosDeUso.d 


# Each subdirectory must supply rules for building sources it contributes
source/casosDeUso/%.o: ../source/casosDeUso/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


