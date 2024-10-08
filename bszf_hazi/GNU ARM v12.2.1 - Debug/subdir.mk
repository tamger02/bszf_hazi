################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../dma.c \
../main.c 

OBJS += \
./app.o \
./dma.o \
./main.o 

C_DEPS += \
./app.d \
./dma.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
app.o: ../app.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\config" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\autogen" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\hardware\board\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emlib\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\system\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\sleeptimer\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\uartdrv\inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dma.o: ../dma.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\config" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\autogen" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\hardware\board\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emlib\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\system\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\sleeptimer\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\uartdrv\inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"dma.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\config" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\autogen" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\Device\SiliconLabs\EFM32GG\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\hardware\board\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\CMSIS\Core\Include" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\device_init\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\dmadrv\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\common\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emlib\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\common\toolchain\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\system\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\service\sleeptimer\inc" -I"C:\Users\dbura\OneDrive\Documents\Bszf hazi\bszf_hazi\bszf_hazi\gecko_sdk_4.4.4\platform\emdrv\uartdrv\inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


