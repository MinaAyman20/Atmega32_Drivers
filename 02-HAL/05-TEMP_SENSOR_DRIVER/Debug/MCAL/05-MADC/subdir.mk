################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/05-MADC/MADC_config.c \
../MCAL/05-MADC/MADC_prog.c 

OBJS += \
./MCAL/05-MADC/MADC_config.o \
./MCAL/05-MADC/MADC_prog.o 

C_DEPS += \
./MCAL/05-MADC/MADC_config.d \
./MCAL/05-MADC/MADC_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/05-MADC/%.o: ../MCAL/05-MADC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


