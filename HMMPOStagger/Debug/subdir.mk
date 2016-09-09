################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../conllu.cpp \
../hmm.cpp \
../main.cpp \
../utils.cpp \
../viterbi.cpp \
../vocab2id.cpp 

OBJS += \
./conllu.o \
./hmm.o \
./main.o \
./utils.o \
./viterbi.o \
./vocab2id.o 

CPP_DEPS += \
./conllu.d \
./hmm.d \
./main.d \
./utils.d \
./viterbi.d \
./vocab2id.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201103L -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


