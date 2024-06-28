################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/lcd/subdir.mk
-include Utilities/Fonts/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/Legacy/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32H743I-EVAL/subdir.mk
-include Drivers/BSP/Components/wm8994/subdir.mk
-include Drivers/BSP/Components/ts3510/subdir.mk
-include Drivers/BSP/Components/stmpe811/subdir.mk
-include Drivers/BSP/Components/mt25tl01g/subdir.mk
-include Drivers/BSP/Components/mfxstm32l152/subdir.mk
-include Drivers/BSP/Components/m24lr64/subdir.mk
-include Drivers/BSP/Components/is42s32800g/subdir.mk
-include Drivers/BSP/Components/exc7200/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := swap_by_new_upgrade
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
swap_by_new_upgrade.elf \

MAP_FILES += \
swap_by_new_upgrade.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
swap_by_new_upgrade.list \

OBJCOPY_BIN += \
swap_by_new_upgrade.bin \


# All Target
all: main-build

# Main-build Target
main-build: swap_by_new_upgrade.elf secondary-outputs

# Tool invocations
swap_by_new_upgrade.elf swap_by_new_upgrade.map: $(OBJS) $(USER_OBJS) C:\Users\ezaidi\STM32CubeIDE\workspace_1.13.2\swap_nbsp\STM32H743XIHX_FLASH_Bank2.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "swap_by_new_upgrade.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\ezaidi\STM32CubeIDE\workspace_1.13.2\swap_nbsp\STM32H743XIHX_FLASH_Bank2.ld" --specs=nosys.specs -Wl,-Map="swap_by_new_upgrade.map" -Wl,--gc-sections -static -L"C:\Users\ezaidi\STM32Cube\Repository\STM32Cube_FW_H7_V1.11.1\Middlewares\ST\STM32_Audio\Addons\PDM\Lib" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

swap_by_new_upgrade.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "swap_by_new_upgrade.list"
	@echo 'Finished building: $@'
	@echo ' '

swap_by_new_upgrade.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "swap_by_new_upgrade.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout swap_by_new_upgrade.bin swap_by_new_upgrade.elf swap_by_new_upgrade.list swap_by_new_upgrade.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
