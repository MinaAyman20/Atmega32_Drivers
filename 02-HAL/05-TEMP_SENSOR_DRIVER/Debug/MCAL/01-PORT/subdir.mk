################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/01-PORT/MPort_config.c \
../MCAL/01-PORT/MPort_prog.c 

OBJS += \
./MCAL/01-PORT/MPort_config.o \
./MCAL/01-PORT/MPort_prog.o 

C_DEPS += \
./MCAL/01-PORT/MPort_config.d \
./MCAL/01-PORT/MPort_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/01-PORT/%.o: ../MCAL/01-PORT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


