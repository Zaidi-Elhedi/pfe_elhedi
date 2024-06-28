################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.c \
../Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.c 

OBJS += \
./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.o \
./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.o 

C_DEPS += \
./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.d \
./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/mfxstm32l152/%.o Drivers/BSP/Components/mfxstm32l152/%.su Drivers/BSP/Components/mfxstm32l152/%.cyclo: ../Drivers/BSP/Components/mfxstm32l152/%.c Drivers/BSP/Components/mfxstm32l152/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DFLASH_BANK2 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Drivers/BSP/STM32H743I-EVAL" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Core/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Drivers/BSP/Components/Common" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Utilities/Fonts" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Utilities/lcd" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-mfxstm32l152

clean-Drivers-2f-BSP-2f-Components-2f-mfxstm32l152:
	-$(RM) ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.cyclo ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.d ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.o ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152.su ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.cyclo ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.d ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.o ./Drivers/BSP/Components/mfxstm32l152/mfxstm32l152_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-mfxstm32l152

