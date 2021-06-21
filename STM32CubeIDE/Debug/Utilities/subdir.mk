################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/trace/adv_trace/stm32_adv_trace.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/lpm/tiny_lpm/stm32_lpm.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_mem.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/sequencer/stm32_seq.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_systime.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/timer/stm32_timer.c \
/home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_tiny_vsnprintf.c 

OBJS += \
./Utilities/stm32_adv_trace.o \
./Utilities/stm32_lpm.o \
./Utilities/stm32_mem.o \
./Utilities/stm32_seq.o \
./Utilities/stm32_systime.o \
./Utilities/stm32_timer.o \
./Utilities/stm32_tiny_vsnprintf.o 

C_DEPS += \
./Utilities/stm32_adv_trace.d \
./Utilities/stm32_lpm.d \
./Utilities/stm32_mem.d \
./Utilities/stm32_seq.d \
./Utilities/stm32_systime.d \
./Utilities/stm32_timer.d \
./Utilities/stm32_tiny_vsnprintf.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/stm32_adv_trace.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/trace/adv_trace/stm32_adv_trace.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_adv_trace.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_lpm.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/lpm/tiny_lpm/stm32_lpm.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_lpm.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_mem.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_mem.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_mem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_seq.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/sequencer/stm32_seq.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_seq.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_systime.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_systime.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_systime.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_timer.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/timer/stm32_timer.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Utilities/stm32_tiny_vsnprintf.o: /home/nathan/GoogleDrive/Projects/STM32CubeIDE/LoraNODE1/LoRaWAN_End_Node/Utilities/misc/stm32_tiny_vsnprintf.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../Middlewares/Third_Party/LoRaWAN/Mac -I../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../Middlewares/Third_Party/SubGHz_Phy -I../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../Utilities/lpm/tiny_lpm -I../../Utilities/misc -I../../Utilities/sequencer -I../../Utilities/timer -I../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Utilities/stm32_tiny_vsnprintf.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

