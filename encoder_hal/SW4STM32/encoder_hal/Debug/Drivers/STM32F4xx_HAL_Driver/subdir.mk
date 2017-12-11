################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ramfunc.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc_ex.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim.o \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim_ex.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ramfunc.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc_ex.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim.d \
./Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_cortex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_dma_ex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_flash_ramfunc.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_gpio.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_pwr_ex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_rcc_ex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_spi.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F4xx_HAL_Driver/stm32f4xx_hal_tim_ex.o: /home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Drivers/CMSIS/Include" -I"/home/mromanow/Dokumenty/RobotFirmware/encoder_hal/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


