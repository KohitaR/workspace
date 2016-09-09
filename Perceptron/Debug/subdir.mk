################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../feature.cpp \
../main.cpp \
../obs2id.cpp \
../perceptron.cpp \
../utils.cpp 

OBJS += \
./feature.o \
./main.o \
./obs2id.o \
./perceptron.o \
./utils.o 

CPP_DEPS += \
./feature.d \
./main.d \
./obs2id.d \
./perceptron.d \
./utils.d 


# Each subdirectory must supply rules for building sources it contributes
feature.o: ../feature.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201103L -I/home/ryosuke-k/workspace/eigen-3.0.1 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"feature.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201103L -I/home/ryosuke-k/workspace/eigen-3.0.1 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


