################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/BootLoader/BootLoader.c 

OBJS += \
./Src/BootLoader/BootLoader.o 

C_DEPS += \
./Src/BootLoader/BootLoader.d 


# Each subdirectory must supply rules for building sources it contributes
Src/BootLoader/%.o Src/BootLoader/%.su Src/BootLoader/%.cyclo: ../Src/BootLoader/%.c Src/BootLoader/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src-2f-BootLoader

clean-Src-2f-BootLoader:
	-$(RM) ./Src/BootLoader/BootLoader.cyclo ./Src/BootLoader/BootLoader.d ./Src/BootLoader/BootLoader.o ./Src/BootLoader/BootLoader.su

.PHONY: clean-Src-2f-BootLoader

