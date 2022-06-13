################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../circular_buffer.c \
../mdbus_slave.c 

C_DEPS += \
./circular_buffer.d \
./mdbus_slave.d 

OBJS += \
./circular_buffer.o \
./mdbus_slave.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./circular_buffer.d ./circular_buffer.o ./mdbus_slave.d ./mdbus_slave.o

.PHONY: clean--2e-

