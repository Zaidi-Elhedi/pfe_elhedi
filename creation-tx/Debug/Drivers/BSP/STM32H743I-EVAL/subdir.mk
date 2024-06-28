################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.c \
../Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.c \
../Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.c 

OBJS += \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.o \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.o \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.o 

C_DEPS += \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.d \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.d \
./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H743I-EVAL/%.o Drivers/BSP/STM32H743I-EVAL/%.su Drivers/BSP/STM32H743I-EVAL/%.cyclo: ../Drivers/BSP/STM32H743I-EVAL/%.c Drivers/BSP/STM32H743I-EVAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H743I-2d-EVAL

clean-Drivers-2f-BSP-2f-STM32H743I-2d-EVAL:
	-$(RM) ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.cyclo ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.d ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.o ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval.su ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.cyclo ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.d ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.o ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_bus.su ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.cyclo ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.d ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.o ./Drivers/BSP/STM32H743I-EVAL/stm32h743i_eval_io.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H743I-2d-EVAL

