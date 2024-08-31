################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gen_code_s/pi_discrete.c 

OBJS += \
./gen_code_s/pi_discrete.o 

C_DEPS += \
./gen_code_s/pi_discrete.d 


# Each subdirectory must supply rules for building sources it contributes
gen_code_s/pi_discrete.o: ../gen_code_s/pi_discrete.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103x6 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/personal repo/mahmoudnasser/proteus/uart_float/int_test_get/gen_code_s" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"gen_code_s/pi_discrete.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

