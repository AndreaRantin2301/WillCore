################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user_code/src/bsp/bsp_uart.c 

OBJS += \
./user_code/src/bsp/bsp_uart.o 

C_DEPS += \
./user_code/src/bsp/bsp_uart.d 


# Each subdirectory must supply rules for building sources it contributes
user_code/src/bsp/%.o user_code/src/bsp/%.su user_code/src/bsp/%.cyclo: ../user_code/src/bsp/%.c user_code/src/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/ANDREW/STM32/IDE_PROJECTS/WillCore/user_code/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -Werror -pedantic -pedantic-errors -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wconversion -v -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-user_code-2f-src-2f-bsp

clean-user_code-2f-src-2f-bsp:
	-$(RM) ./user_code/src/bsp/bsp_uart.cyclo ./user_code/src/bsp/bsp_uart.d ./user_code/src/bsp/bsp_uart.o ./user_code/src/bsp/bsp_uart.su

.PHONY: clean-user_code-2f-src-2f-bsp

