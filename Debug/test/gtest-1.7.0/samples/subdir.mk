################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/gtest-1.7.0/samples/sample1.cc \
../test/gtest-1.7.0/samples/sample10_unittest.cc \
../test/gtest-1.7.0/samples/sample1_unittest.cc \
../test/gtest-1.7.0/samples/sample2.cc \
../test/gtest-1.7.0/samples/sample2_unittest.cc \
../test/gtest-1.7.0/samples/sample3_unittest.cc \
../test/gtest-1.7.0/samples/sample4.cc \
../test/gtest-1.7.0/samples/sample4_unittest.cc \
../test/gtest-1.7.0/samples/sample5_unittest.cc \
../test/gtest-1.7.0/samples/sample6_unittest.cc \
../test/gtest-1.7.0/samples/sample7_unittest.cc \
../test/gtest-1.7.0/samples/sample8_unittest.cc \
../test/gtest-1.7.0/samples/sample9_unittest.cc 

OBJS += \
./test/gtest-1.7.0/samples/sample1.o \
./test/gtest-1.7.0/samples/sample10_unittest.o \
./test/gtest-1.7.0/samples/sample1_unittest.o \
./test/gtest-1.7.0/samples/sample2.o \
./test/gtest-1.7.0/samples/sample2_unittest.o \
./test/gtest-1.7.0/samples/sample3_unittest.o \
./test/gtest-1.7.0/samples/sample4.o \
./test/gtest-1.7.0/samples/sample4_unittest.o \
./test/gtest-1.7.0/samples/sample5_unittest.o \
./test/gtest-1.7.0/samples/sample6_unittest.o \
./test/gtest-1.7.0/samples/sample7_unittest.o \
./test/gtest-1.7.0/samples/sample8_unittest.o \
./test/gtest-1.7.0/samples/sample9_unittest.o 

CC_DEPS += \
./test/gtest-1.7.0/samples/sample1.d \
./test/gtest-1.7.0/samples/sample10_unittest.d \
./test/gtest-1.7.0/samples/sample1_unittest.d \
./test/gtest-1.7.0/samples/sample2.d \
./test/gtest-1.7.0/samples/sample2_unittest.d \
./test/gtest-1.7.0/samples/sample3_unittest.d \
./test/gtest-1.7.0/samples/sample4.d \
./test/gtest-1.7.0/samples/sample4_unittest.d \
./test/gtest-1.7.0/samples/sample5_unittest.d \
./test/gtest-1.7.0/samples/sample6_unittest.d \
./test/gtest-1.7.0/samples/sample7_unittest.d \
./test/gtest-1.7.0/samples/sample8_unittest.d \
./test/gtest-1.7.0/samples/sample9_unittest.d 


# Each subdirectory must supply rules for building sources it contributes
test/gtest-1.7.0/samples/%.o: ../test/gtest-1.7.0/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


