################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/mdbus_slave/circular_buffer.c \
../Core/Src/mdbus_slave/mdbus_slave.c 

OBJS += \
./Core/Src/mdbus_slave/circular_buffer.o \
./Core/Src/mdbus_slave/mdbus_slave.o 

C_DEPS += \
./Core/Src/mdbus_slave/circular_buffer.d \
./Core/Src/mdbus_slave/mdbus_slave.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/mdbus_slave/%.o Core/Src/mdbus_slave/%.su: ../Core/Src/mdbus_slave/%.c Core/Src/mdbus_slave/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-mdbus_slave

clean-Core-2f-Src-2f-mdbus_slave:
	-$(RM) ./Core/Src/mdbus_slave/circular_buffer.d ./Core/Src/mdbus_slave/circular_buffer.o ./Core/Src/mdbus_slave/circular_buffer.su ./Core/Src/mdbus_slave/mdbus_slave.d ./Core/Src/mdbus_slave/mdbus_slave.o ./Core/Src/mdbus_slave/mdbus_slave.su

.PHONY: clean-Core-2f-Src-2f-mdbus_slave

