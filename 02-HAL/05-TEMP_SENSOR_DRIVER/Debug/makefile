################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/05-MADC/subdir.mk
-include MCAL/01-PORT/subdir.mk
-include MCAL/00-DIO/subdir.mk
-include HAL/HTEMP_SENSOR/subdir.mk
-include HAL/HLDR_SENSOR/subdir.mk
-include HAL/HLCD/subdir.mk
-include HAL/HKEYPAD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
HTEMP_SENSOR_DRIVER.lss \

FLASH_IMAGE += \
HTEMP_SENSOR_DRIVER.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: HTEMP_SENSOR_DRIVER.elf secondary-outputs

# Tool invocations
HTEMP_SENSOR_DRIVER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,HTEMP_SENSOR_DRIVER.map -mmcu=atmega32 -o "HTEMP_SENSOR_DRIVER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HTEMP_SENSOR_DRIVER.lss: HTEMP_SENSOR_DRIVER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S HTEMP_SENSOR_DRIVER.elf  >"HTEMP_SENSOR_DRIVER.lss"
	@echo 'Finished building: $@'
	@echo ' '

HTEMP_SENSOR_DRIVER.hex: HTEMP_SENSOR_DRIVER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex HTEMP_SENSOR_DRIVER.elf  "HTEMP_SENSOR_DRIVER.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: HTEMP_SENSOR_DRIVER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 HTEMP_SENSOR_DRIVER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) HTEMP_SENSOR_DRIVER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
