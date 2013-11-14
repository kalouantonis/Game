################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GO/DrawableGameObject.cpp \
../GO/GameObject.cpp 

OBJS += \
./GO/DrawableGameObject.o \
./GO/GameObject.o 

CPP_DEPS += \
./GO/DrawableGameObject.d \
./GO/GameObject.d 


# Each subdirectory must supply rules for building sources it contributes
GO/%.o: ../GO/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG -I"/home/slacker/Projects/Game" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


