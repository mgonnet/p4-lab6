################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/gtest-1.7.0/src/gtest-all.cc \
../test/gtest-1.7.0/src/gtest-death-test.cc \
../test/gtest-1.7.0/src/gtest-filepath.cc \
../test/gtest-1.7.0/src/gtest-port.cc \
../test/gtest-1.7.0/src/gtest-printers.cc \
../test/gtest-1.7.0/src/gtest-test-part.cc \
../test/gtest-1.7.0/src/gtest-typed-test.cc \
../test/gtest-1.7.0/src/gtest.cc \
../test/gtest-1.7.0/src/gtest_main.cc 

OBJS += \
./test/gtest-1.7.0/src/gtest-all.o \
./test/gtest-1.7.0/src/gtest-death-test.o \
./test/gtest-1.7.0/src/gtest-filepath.o \
./test/gtest-1.7.0/src/gtest-port.o \
./test/gtest-1.7.0/src/gtest-printers.o \
./test/gtest-1.7.0/src/gtest-test-part.o \
./test/gtest-1.7.0/src/gtest-typed-test.o \
./test/gtest-1.7.0/src/gtest.o \
./test/gtest-1.7.0/src/gtest_main.o 

CC_DEPS += \
./test/gtest-1.7.0/src/gtest-all.d \
./test/gtest-1.7.0/src/gtest-death-test.d \
./test/gtest-1.7.0/src/gtest-filepath.d \
./test/gtest-1.7.0/src/gtest-port.d \
./test/gtest-1.7.0/src/gtest-printers.d \
./test/gtest-1.7.0/src/gtest-test-part.d \
./test/gtest-1.7.0/src/gtest-typed-test.d \
./test/gtest-1.7.0/src/gtest.d \
./test/gtest-1.7.0/src/gtest_main.d 


# Each subdirectory must supply rules for building sources it contributes
test/gtest-1.7.0/src/%.o: ../test/gtest-1.7.0/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


