################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/is42s32800g/is42s32800g.c 

OBJS += \
./Drivers/BSP/Components/is42s32800g/is42s32800g.o 

C_DEPS += \
./Drivers/BSP/Components/is42s32800g/is42s32800g.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/is42s32800g/%.o Drivers/BSP/Components/is42s32800g/%.su Drivers/BSP/Components/is42s32800g/%.cyclo: ../Drivers/BSP/Components/is42s32800g/%.c Drivers/BSP/Components/is42s32800g/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DFLASH_BANK1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Utilities/Fonts" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Utilities/lcd" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Drivers/BSP/Components/Common" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Drivers/BSP/STM32H743I-EVAL" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_bsp/Drivers/STM32H7xx_HAL_Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-is42s32800g

clean-Drivers-2f-BSP-2f-Components-2f-is42s32800g:
	-$(RM) ./Drivers/BSP/Components/is42s32800g/is42s32800g.cyclo ./Drivers/BSP/Components/is42s32800g/is42s32800g.d ./Drivers/BSP/Components/is42s32800g/is42s32800g.o ./Drivers/BSP/Components/is42s32800g/is42s32800g.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-is42s32800g

