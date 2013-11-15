################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Utils/FileIO.cpp \
../Utils/logger.cpp \
../Utils/timer.cpp 

OBJS += \
./Utils/FileIO.o \
./Utils/logger.o \
./Utils/timer.o 

CPP_DEPS += \
./Utils/FileIO.d \
./Utils/logger.d \
./Utils/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Utils/%.o: ../Utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG -I../../Game -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


