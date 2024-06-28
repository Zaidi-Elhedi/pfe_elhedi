################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/exc7200/exc7200.c \
../Drivers/BSP/Components/exc7200/exc7200_reg.c 

OBJS += \
./Drivers/BSP/Components/exc7200/exc7200.o \
./Drivers/BSP/Components/exc7200/exc7200_reg.o 

C_DEPS += \
./Drivers/BSP/Components/exc7200/exc7200.d \
./Drivers/BSP/Components/exc7200/exc7200_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/exc7200/%.o Drivers/BSP/Components/exc7200/%.su Drivers/BSP/Components/exc7200/%.cyclo: ../Drivers/BSP/Components/exc7200/%.c Drivers/BSP/Components/exc7200/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DFLASH_BANK1 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/threadx/common/inc/ -I../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-exc7200

clean-Drivers-2f-BSP-2f-Components-2f-exc7200:
	-$(RM) ./Drivers/BSP/Components/exc7200/exc7200.cyclo ./Drivers/BSP/Components/exc7200/exc7200.d ./Drivers/BSP/Components/exc7200/exc7200.o ./Drivers/BSP/Components/exc7200/exc7200.su ./Drivers/BSP/Components/exc7200/exc7200_reg.cyclo ./Drivers/BSP/Components/exc7200/exc7200_reg.d ./Drivers/BSP/Components/exc7200/exc7200_reg.o ./Drivers/BSP/Components/exc7200/exc7200_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-exc7200

