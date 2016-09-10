################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dataload.cpp \
../src/feature.cpp \
../src/main.cpp \
../src/obs2id.cpp \
../src/perceptron.cpp \
../src/utils.cpp 

OBJS += \
./src/dataload.o \
./src/feature.o \
./src/main.o \
./src/obs2id.o \
./src/perceptron.o \
./src/utils.o 

CPP_DEPS += \
./src/dataload.d \
./src/feature.d \
./src/main.d \
./src/obs2id.d \
./src/perceptron.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__cplusplus=201103L -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/c++/5 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


