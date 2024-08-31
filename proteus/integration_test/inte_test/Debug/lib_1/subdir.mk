################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib_1/biko.c 

OBJS += \
./lib_1/biko.o 

C_DEPS += \
./lib_1/biko.d 


# Each subdirectory must supply rules for building sources it contributes
lib_1/biko.o: ../lib_1/biko.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103x6 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/personal repo/mahmoudnasser/proteus/integration_test/inte_test/lib_1" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lib_1/biko.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

