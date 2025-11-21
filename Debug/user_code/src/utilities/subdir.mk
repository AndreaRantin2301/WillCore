################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user_code/src/utilities/logging_utility.c 

OBJS += \
./user_code/src/utilities/logging_utility.o 

C_DEPS += \
./user_code/src/utilities/logging_utility.d 


# Each subdirectory must supply rules for building sources it contributes
user_code/src/utilities/%.o user_code/src/utilities/%.su user_code/src/utilities/%.cyclo: ../user_code/src/utilities/%.c user_code/src/utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I"C:/ANDREW/STM32/IDE_PROJECTS/WillCore/user_code/inc" -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -Werror -pedantic -pedantic-errors -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wconversion -v -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-user_code-2f-src-2f-utilities

clean-user_code-2f-src-2f-utilities:
	-$(RM) ./user_code/src/utilities/logging_utility.cyclo ./user_code/src/utilities/logging_utility.d ./user_code/src/utilities/logging_utility.o ./user_code/src/utilities/logging_utility.su

.PHONY: clean-user_code-2f-src-2f-utilities

