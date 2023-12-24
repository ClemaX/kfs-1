NAME := kfs-1.bin
TARGET := i686-elf

SRCDIR := src
INCDIR := include
OBJDIR := obj
LIBDIR := lib

OBJS := $(addprefix $(OBJDIR)/, \
	boot.o \
	kernel.o \
	terminal.o \
	utils.o \
)

# Library dependencies
LIBS := $(addprefix $(LIBDIR)/, )

LIBDIRS := $(dir $(LIBS))
LIBINCS := $(addsuffix $(INCDIR), $(LIBDIRS))
LIBARS := $(notdir $(LIBS))

AS := $(TARGET)-as
CC := $(TARGET)-gcc
LD := $(TARGET)-gcc

CFLAGS := -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I$(INCDIR)
LDFLAGS := -ffreestanding -O2 -nostdlib

LDLIBS := $(LIBARS:lib%.a=-l%) -lgcc

all: $(NAME)

# Libraries
$(LIBS): %.a: FORCE
	make CC=$(CC) LD=$(LD) CFLAGS="-DNOSTDLIB $(CFLAGS)" LDFLAGS="$(LDFLAGS)" -C $(dir $@) NAME=$(@F)

# Objects
$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJDIR)/boot.o: $(SRCDIR)/boot.s | $(OBJDIR)
	$(AS) $^ -o $@

# Executables
$(NAME): $(OBJS) $(LIBS) linker.ld
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(OBJS) $(LDLIBS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

FORCE: ;

.PHONY: all clean fclean
