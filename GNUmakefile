ARCH_PREFIX := aarch64-linux-gnu-
ASM 		:= $(ARCH_PREFIX)as
CC 			:= $(ARCH_PREFIX)gcc
LD 			:= $(ARCH_PREFIX)ld
OBJCPY		:= $(ARCH_PREFIX)objcopy

BLASRC		:= $(wildcard src/start/*.asm)
KASRC		:= $(wildcard src/kernel/*.asm)
KCSRC		:= $(wildcard src/kernel/*.c)
ALLSRC  	:= $(BLASRC) $(KASRC) $(KCSRC)

BUILD_DIR 	:= build
SRC_DIR   	:= src

LNKSCR	:= $(SRC_DIR)/linker.ld
ELF		:= $(BUILD_DIR)/kernel8.elf
IMG		:= $(BUILD_DIR)/kernel8.img

OBJECTS := $(patsubst %.asm,$(BUILD_DIR)/%.o,$(notdir $(BLASRC) $(KASRC)))
OBJECTS += $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(KCSRC)))

.PHONY: all clean bootldr

all: $(IMG)

bootldr: $(IMG)

$(IMG): $(ELF)
	$(OBJCPY) -O binary $< $@

$(ELF): $(OBJECTS) $(LNKSCR) | $(BUILD_DIR)
	$(LD) -T $(LNKSCR) $(OBJECTS) -o $(ELF)

$(BUILD_DIR)/%.o: $(SRC_DIR)/kernel/%.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ -O2 -Wall -Wextra -nostdlib -ffreestanding -mcpu=cortex-a72

$(BUILD_DIR)/%.o: $(SRC_DIR)/kernel/%.asm | $(BUILD_DIR)
	$(ASM) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/start/%.asm | $(BUILD_DIR)
	$(ASM) $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)