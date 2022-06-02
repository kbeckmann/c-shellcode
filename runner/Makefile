BUILD_DIR := build
TARGET := out
TARGET_ELF_PATH := $(BUILD_DIR)/$(TARGET).elf

CFLAGS += -Os

CFLAGS += -ggdb -fno-stack-protector -nostartfiles -fomit-frame-pointer -fPIE -static

LDFLAGS +=


C_SOURCES = runner.c

OBJS += $(C_SOURCES:%=$(BUILD_DIR)/%.o)


all: $(TARGET_ELF_PATH)

clean:
	rm -rf $(BUILD_DIR)


# c source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET_ELF_PATH) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
