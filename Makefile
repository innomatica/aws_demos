#-----------------------------------------------------------------------------
# TARGET
#
TARGET = aws_demos

#-----------------------------------------------------------------------------
# TOOLCHAIN
#
PREFIX = arm-none-eabi-
GCC_PATH = /opt/gcc-arm-none-eabi/bin
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#-----------------------------------------------------------------------------
# PATH and FILES
#
# AWS FRTOS root
AWS_RTOS_ROOT = $(HOME)/Research/AmazonFreeRTOS
# Build path
BUILD_DIR = build

# C sources under AWS_ROOT/lib
C_SOURCES =  $(shell find $(AWS_RTOS_ROOT)/lib -name *.c -type f)
# C source under current project
C_SOURCES += $(shell find src -name *.c -type f)

# C includes under AWS_ROOT/lib
C_HEADERS =  $(shell find $(AWS_RTOS_ROOT)/lib -type d)
# C includes under current project
C_HEADERS += $(shell find src -type d)
#
C_INCLUDES = $(patsubst %,-I%, $(C_HEADERS))

# ASM sources (startup code)
ASM_SOURCES = startup_stm32l475xx.s
# AS includes
AS_INCLUDES = 

#-----------------------------------------------------------------------------
# BUILD OPTIONS
#
DEBUG = 1
OPT = -O0 -Wall -fdata-sections -ffunction-sections -fmessage-length=0
 
#-----------------------------------------------------------------------------
# CFLAGS
#
# cpu
CPU = -mcpu=cortex-m4
# fpu
FPU = -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI = -mfloat-abi=hard
# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

#-----------------------------------------------------------------------------
# DEFINITIONS
#
# AS defines
AS_DEFS = 
# C defines
C_DEFS =  \
	-DUSE_HAL_DRIVER \
	-DSTM32L475xx \
	-DMQTTCLIENT_PLATFORM_HEADER=MQTTCMSIS.h \
	-DENABLE_IOT_INFO \
	-DENABLE_IOT_ERROR \
	-DSENSOR \
	-DRFU \
	-DUSE_OFFLOAD_SSL

#-----------------------------------------------------------------------------
# COMPILER
#
# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT)
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT)

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

#-----------------------------------------------------------------------------
# LINKER
#
# linker script
LDSCRIPT = STM32L475VGTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nosys.specs -z muldefs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) \
		  -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

#-----------------------------------------------------------------------------
# OBJECTS
#
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

#-----------------------------------------------------------------------------
# RULES
#
$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	@$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	@$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	@$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	@$(BIN) $< $@	
	
$(BUILD_DIR):
	-mkdir $@		

#-----------------------------------------------------------------------------
# UTILITIES
#
clean:
	-rm -fR $(BUILD_DIR)

clobber:
	-rm -fR .dep $(BUILD_DIR)
	-rm -f tags
  
ctags:
	-rm -f tags
	-ctags -R . 

astyle:
	-find ./src -name *.c | xargs astyle --style=allman --indent=tab
	-find ./src -name *.orig | xargs rm -f
	-find ./snc -name *.h | xargs astyle --style=allman --indent=tab
	-find ./snc -name *.orig | xargs rm -f

# flash with J-Link
jflash:
	JLinkExe -if swd -device stm32l475vg -speed 4000 -commandfile jlinkcmd > /dev/null

# flash with STLINK 
sflash:
	openocd \
		-f interface/stlink-v2-1.cfg \
		-f target/stm32l4x.cfg \
		-c 'program $(BUILD_DIR)/$(TARGET).elf reset exit'

