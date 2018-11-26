################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/dma.c \
../Src/gpio.c \
../Src/main.c \
../Src/motors_param.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/tim.c \
../Src/usart.c 

CPP_SRCS += \
../Src/maincpp.cpp 

OBJS += \
./Src/adc.o \
./Src/dma.o \
./Src/gpio.o \
./Src/main.o \
./Src/maincpp.o \
./Src/motors_param.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/tim.o \
./Src/usart.o 

C_DEPS += \
./Src/adc.d \
./Src/dma.d \
./Src/gpio.d \
./Src/main.d \
./Src/motors_param.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/tim.d \
./Src/usart.d 

CPP_DEPS += \
./Src/maincpp.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/L6470" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/Common" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/X-NUCLEO-IHM02A1"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/L6470" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/Common" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/X-NUCLEO-IHM02A1"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


