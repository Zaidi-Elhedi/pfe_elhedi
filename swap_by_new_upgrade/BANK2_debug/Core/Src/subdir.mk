################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MQTTConnectClient.c \
../Core/Src/MQTTDeserializePublish.c \
../Core/Src/MQTTFormat.c \
../Core/Src/MQTTPacket.c \
../Core/Src/MQTTSerializePublish.c \
../Core/Src/MQTTSim800.c \
../Core/Src/MQTTSubscribeClient.c \
../Core/Src/MQTTUnsubscribeClient.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/MQTTConnectClient.o \
./Core/Src/MQTTDeserializePublish.o \
./Core/Src/MQTTFormat.o \
./Core/Src/MQTTPacket.o \
./Core/Src/MQTTSerializePublish.o \
./Core/Src/MQTTSim800.o \
./Core/Src/MQTTSubscribeClient.o \
./Core/Src/MQTTUnsubscribeClient.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/MQTTConnectClient.d \
./Core/Src/MQTTDeserializePublish.d \
./Core/Src/MQTTFormat.d \
./Core/Src/MQTTPacket.d \
./Core/Src/MQTTSerializePublish.d \
./Core/Src/MQTTSim800.d \
./Core/Src/MQTTSubscribeClient.d \
./Core/Src/MQTTUnsubscribeClient.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H743I_EVAL -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7xx -c -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Core/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/Components" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/STM32H743I-EVAL" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Utilities/lcd" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/CMSIS/Include" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/MQTTConnectClient.cyclo ./Core/Src/MQTTConnectClient.d ./Core/Src/MQTTConnectClient.o ./Core/Src/MQTTConnectClient.su ./Core/Src/MQTTDeserializePublish.cyclo ./Core/Src/MQTTDeserializePublish.d ./Core/Src/MQTTDeserializePublish.o ./Core/Src/MQTTDeserializePublish.su ./Core/Src/MQTTFormat.cyclo ./Core/Src/MQTTFormat.d ./Core/Src/MQTTFormat.o ./Core/Src/MQTTFormat.su ./Core/Src/MQTTPacket.cyclo ./Core/Src/MQTTPacket.d ./Core/Src/MQTTPacket.o ./Core/Src/MQTTPacket.su ./Core/Src/MQTTSerializePublish.cyclo ./Core/Src/MQTTSerializePublish.d ./Core/Src/MQTTSerializePublish.o ./Core/Src/MQTTSerializePublish.su ./Core/Src/MQTTSim800.cyclo ./Core/Src/MQTTSim800.d ./Core/Src/MQTTSim800.o ./Core/Src/MQTTSim800.su ./Core/Src/MQTTSubscribeClient.cyclo ./Core/Src/MQTTSubscribeClient.d ./Core/Src/MQTTSubscribeClient.o ./Core/Src/MQTTSubscribeClient.su ./Core/Src/MQTTUnsubscribeClient.cyclo ./Core/Src/MQTTUnsubscribeClient.d ./Core/Src/MQTTUnsubscribeClient.o ./Core/Src/MQTTUnsubscribeClient.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

