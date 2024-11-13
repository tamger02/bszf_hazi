################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Objects.c \
../app.c \
../game.c \
../init_LCD.c \
../init_uart.c \
../main.c \
../segmentlcd.c \
../segmentlcd_individual.c 

OBJS += \
./Objects.o \
./app.o \
./game.o \
./init_LCD.o \
./init_uart.o \
./main.o \
./segmentlcd.o \
./segmentlcd_individual.o 

C_DEPS += \
./Objects.d \
./app.d \
./game.d \
./init_LCD.d \
./init_uart.d \
./main.d \
./segmentlcd.d \
./segmentlcd_individual.d 


# Each subdirectory must supply rules for building sources it contributes
Objects.o: ../Objects.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"Objects.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

app.o: ../app.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

game.o: ../game.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"game.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

init_LCD.o: ../init_LCD.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"init_LCD.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

init_uart.o: ../init_uart.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"init_uart.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

segmentlcd.o: ../segmentlcd.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"segmentlcd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

segmentlcd_individual.o: ../segmentlcd_individual.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG990F1024=1' '-DHFXO_FREQ=48000000' '-DSL_BOARD_NAME="BRD2200A"' '-DSL_BOARD_REV="B05"' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/config" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/autogen" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/hardware/board/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/CMSIS/Core/Include" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/device_init/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/emlib/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/common/toolchain/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/system/inc" -I"/Users/gergelytamasy/Documents/bszf_hazi/snake/gecko_sdk_4.4.4/platform/service/udelay/inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"segmentlcd_individual.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


