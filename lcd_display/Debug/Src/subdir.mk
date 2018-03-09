################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MenuAndSubMenu.c \
../Src/hd44780.c \
../Src/main.c \
../Src/pcf8574.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/MenuAndSubMenu.o \
./Src/hd44780.o \
./Src/main.o \
./Src/pcf8574.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/MenuAndSubMenu.d \
./Src/hd44780.d \
./Src/main.d \
./Src/pcf8574.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"C:/Users/DAWID/Desktop/User_interface/User-Interface/Inc" -I"C:/Users/DAWID/Desktop/User_interface/User-Interface/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/DAWID/Desktop/User_interface/User-Interface/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/DAWID/Desktop/User_interface/User-Interface/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/DAWID/Desktop/User_interface/User-Interface/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


