ARCH_PREFIX := aarch64-none-elf-
ASM 		:= $(ARCH_PREFIX)as
CC 			:= $(ARCH_PREFIX)gcc
LD 			:= $(ARCH_PREFIX)ld
OBJCPY		:= $(ARCH_PREFIX)objcopy
QEMU		:= qemu-system-aarch64

BLASRC		:= $(wildcard src/start/*.S)
KASRC		:= $(wildcard src/kernel/*.S)
KCSRC		:= $(wildcard src/kernel/*.c)
ALLSRC  	:= $(BLASRC) $(KASRC) $(KCSRC)

BUILD_DIR 	:= build
SRC_DIR   	:= src

LNKSCR	:= $(SRC_DIR)/linker.ld
ELF		:= $(BUILD_DIR)/kernel8.elf
IMG		:= $(BUILD_DIR)/kernel8.img

OBJECTS := $(patsubst %.S,$(BUILD_DIR)/%.o,$(notdir $(BLASRC) $(KASRC)))
OBJECTS += $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(KCSRC)))

CFLAGS := -I src/include -O2 -Wall -Wextra -nostdlib -ffreestanding -mcpu=cortex-a76 -march=armv8-a -mabi=lp64 -ggdb
AFLAGS := -march=armv8-a+nofp
QFLAGS := -machine virt -cpu cortex-a76 -nographic \
		  -chardev stdio,id=char0,logfile=serial.log,signal=off \
		  -serial chardev:char0 -s -S -kernel $(ELF)

.PHONY: all clean run run-qemu

all: $(IMG)

run: run-qemu

$(IMG): $(ELF)
	$(OBJCPY) -O binary $< $@

$(ELF): $(OBJECTS) $(LNKSCR) | $(BUILD_DIR)
	$(LD) -T $(LNKSCR) $(OBJECTS) -o $(ELF)

$(BUILD_DIR)/%.o: $(SRC_DIR)/kernel/%.c | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/kernel/%.S | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/start/%.S | $(BUILD_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run-qemu: $(IMG)
	$(QEMU) $(QFLAGS)

clean:
	rm -rf $(BUILD_DIR)