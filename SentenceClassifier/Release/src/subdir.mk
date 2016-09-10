################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dataload.cpp \
../src/feature.cpp \
../src/main.cpp \
../src/obs2id.cpp \
../src/utils.cpp 

OBJS += \
./src/dataload.o \
./src/feature.o \
./src/main.o \
./src/obs2id.o \
./src/utils.o 

CPP_DEPS += \
./src/dataload.d \
./src/feature.d \
./src/main.d \
./src/obs2id.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


