################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget.cc \
../test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget_test.cc 

OBJS += \
./test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget.o \
./test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget_test.o 

CC_DEPS += \
./test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget.d \
./test/gtest-1.7.0/xcode/Samples/FrameworkSample/widget_test.d 


# Each subdirectory must supply rules for building sources it contributes
test/gtest-1.7.0/xcode/Samples/FrameworkSample/%.o: ../test/gtest-1.7.0/xcode/Samples/FrameworkSample/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


