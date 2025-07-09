################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/TADbaraja.cpp \
../src/TADcarta.cpp \
../src/entorno.cpp \
../src/main.cpp \
../src/pr_baraja.cpp \
../src/pr_carta.cpp \
../src/pr_tablero.cpp 

OBJS += \
./src/TADJuego.o \
./src/TADTablero.o \
./src/TADbaraja.o \
./src/TADcarta.o \
./src/entorno.o \
./src/main.o \
./src/pr_baraja.o \
./src/pr_carta.o \
./src/pr_tablero.o 

CPP_DEPS += \
./src/TADJuego.d \
./src/TADTablero.d \
./src/TADbaraja.d \
./src/TADcarta.d \
./src/entorno.d \
./src/main.d \
./src/pr_baraja.d \
./src/pr_carta.d \
./src/pr_tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


