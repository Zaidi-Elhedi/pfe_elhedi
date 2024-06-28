################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Example/Startup/startup_stm32h743xihx.s 

OBJS += \
./Example/Startup/startup_stm32h743xihx.o 

S_DEPS += \
./Example/Startup/startup_stm32h743xihx.d 


# Each subdirectory must supply rules for building sources it contributes
Example/Startup/%.o: ../Example/Startup/%.s Example/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/SwapBank/Drivers/STM32H7xx_HAL_Driver" -I"C:/Users/ezaidi/STM32Cube/Repository/STM32Cube_FW_H7_V1.11.0/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/SwapBank/Drivers/STM32H7xx_HAL_Driver/Inc" -I"C:/Users/ezaidi/STM32CubeIDE/workspace_1.13.2/SwapBank/Drivers/CMSIS/Include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Example-2f-Startup

clean-Example-2f-Startup:
	-$(RM) ./Example/Startup/startup_stm32h743xihx.d ./Example/Startup/startup_stm32h743xihx.o

.PHONY: clean-Example-2f-Startup

