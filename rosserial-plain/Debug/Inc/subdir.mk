################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Inc/duration.cpp \
../Inc/time.cpp 

OBJS += \
./Inc/duration.o \
./Inc/time.o 

CPP_DEPS += \
./Inc/duration.d \
./Inc/time.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o: ../Inc/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/CMSIS/Include" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/L6470" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/Components/Common" -I"/home/michal/GITHUB/RobotFirmware/rosserial-plain/Drivers/BSP/X-NUCLEO-IHM02A1"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


