################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/conllu.cpp \
../src/hmm.cpp \
../src/main.cpp \
../src/utils.cpp \
../src/viterbi.cpp \
../src/vocab2id.cpp 

OBJS += \
./src/conllu.o \
./src/hmm.o \
./src/main.o \
./src/utils.o \
./src/viterbi.o \
./src/vocab2id.o 

CPP_DEPS += \
./src/conllu.d \
./src/hmm.d \
./src/main.d \
./src/utils.d \
./src/viterbi.d \
./src/vocab2id.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201103L -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


