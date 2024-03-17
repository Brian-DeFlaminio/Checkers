################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/2021HW5starter.cpp \
../src/Board.cpp \
../src/CheckerMove.cpp \
../src/Production.cpp \
../src/Tests.cpp 

C_SRCS += \
../src/LinkedList.c 

OBJS += \
./src/2021HW5starter.o \
./src/Board.o \
./src/CheckerMove.o \
./src/LinkedList.o \
./src/Production.o \
./src/Tests.o 

CPP_DEPS += \
./src/2021HW5starter.d \
./src/Board.d \
./src/CheckerMove.d \
./src/Production.d \
./src/Tests.d 

C_DEPS += \
./src/LinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


