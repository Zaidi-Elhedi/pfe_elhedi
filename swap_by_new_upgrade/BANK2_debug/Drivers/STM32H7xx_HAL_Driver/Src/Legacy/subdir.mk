################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.c \
../Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.c 

OBJS += \
./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.o \
./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.o 

C_DEPS += \
./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.d \
./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32H7xx_HAL_Driver/Src/Legacy/%.o Drivers/STM32H7xx_HAL_Driver/Src/Legacy/%.su Drivers/STM32H7xx_HAL_Driver/Src/Legacy/%.cyclo: ../Drivers/STM32H7xx_HAL_Driver/Src/Legacy/%.c Drivers/STM32H7xx_HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H743I_EVAL -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7xx -c -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Core/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/Components" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/STM32H743I-EVAL" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Utilities/lcd" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/CMSIS/Include" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/swap_by_new_upgrade/Drivers/BSP/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src-2f-Legacy

clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.d ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.o ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth.su ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.cyclo ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.d ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.o ./Drivers/STM32H7xx_HAL_Driver/Src/Legacy/stm32h7xx_hal_eth_ex.su

.PHONY: clean-Drivers-2f-STM32H7xx_HAL_Driver-2f-Src-2f-Legacy

