################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Logic/GameStateMachine.cpp 

OBJS += \
./Logic/GameStateMachine.o 

CPP_DEPS += \
./Logic/GameStateMachine.d 


# Each subdirectory must supply rules for building sources it contributes
Logic/%.o: ../Logic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG -I"/home/slacker/Projects/Game" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


