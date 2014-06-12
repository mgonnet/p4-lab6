################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/gtest-1.7.0/fused-src/gtest/gtest-all.cc \
../test/gtest-1.7.0/fused-src/gtest/gtest_main.cc 

OBJS += \
./test/gtest-1.7.0/fused-src/gtest/gtest-all.o \
./test/gtest-1.7.0/fused-src/gtest/gtest_main.o 

CC_DEPS += \
./test/gtest-1.7.0/fused-src/gtest/gtest-all.d \
./test/gtest-1.7.0/fused-src/gtest/gtest_main.d 


# Each subdirectory must supply rules for building sources it contributes
test/gtest-1.7.0/fused-src/gtest/%.o: ../test/gtest-1.7.0/fused-src/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


