################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Graphics/Camera2D.cpp \
../Graphics/Color.cpp \
../Graphics/Sprite.cpp 

OBJS += \
./Graphics/Camera2D.o \
./Graphics/Color.o \
./Graphics/Sprite.o 

CPP_DEPS += \
./Graphics/Camera2D.d \
./Graphics/Color.d \
./Graphics/Sprite.d 


# Each subdirectory must supply rules for building sources it contributes
Graphics/%.o: ../Graphics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG -I"/home/slacker/Projects/Game" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


