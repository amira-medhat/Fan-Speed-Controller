################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_MOTOR.c \
../PWM_TIMER0.c \
../adc.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./DC_MOTOR.o \
./PWM_TIMER0.o \
./adc.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./DC_MOTOR.d \
./PWM_TIMER0.d \
./adc.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


