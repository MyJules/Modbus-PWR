################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/mdbus_master/mdbus_master.c 

OBJS += \
./Core/Src/mdbus_master/mdbus_master.o 

C_DEPS += \
./Core/Src/mdbus_master/mdbus_master.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/mdbus_master/%.o Core/Src/mdbus_master/%.su: ../Core/Src/mdbus_master/%.c Core/Src/mdbus_master/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G071xx -c -I../Core/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc -I../Drivers/STM32G0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-mdbus_master

clean-Core-2f-Src-2f-mdbus_master:
	-$(RM) ./Core/Src/mdbus_master/mdbus_master.d ./Core/Src/mdbus_master/mdbus_master.o ./Core/Src/mdbus_master/mdbus_master.su

.PHONY: clean-Core-2f-Src-2f-mdbus_master

