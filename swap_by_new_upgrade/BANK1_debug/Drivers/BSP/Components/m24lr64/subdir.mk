################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/m24lr64/m24lr64.c 

OBJS += \
./Drivers/BSP/Components/m24lr64/m24lr64.o 

C_DEPS += \
./Drivers/BSP/Components/m24lr64/m24lr64.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/m24lr64/%.o Drivers/BSP/Components/m24lr64/%.su Drivers/BSP/Components/m24lr64/%.cyclo: ../Drivers/BSP/Components/m24lr64/%.c Drivers/BSP/Components/m24lr64/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DFLASH_BANK1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-m24lr64

clean-Drivers-2f-BSP-2f-Components-2f-m24lr64:
	-$(RM) ./Drivers/BSP/Components/m24lr64/m24lr64.cyclo ./Drivers/BSP/Components/m24lr64/m24lr64.d ./Drivers/BSP/Components/m24lr64/m24lr64.o ./Drivers/BSP/Components/m24lr64/m24lr64.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-m24lr64

