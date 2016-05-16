INCDIR  = ./inc
SRCDIR  = ./src
OBJDIR  = ./obj
HEXDIR  = ./hex

LIBDIR  =


TARGET = $(HEXDIR)/relax

# main.c first
#C_SRC   = $(wildcard $(SRCDIR)/main.c) $(wildcard $(SRCDIR)/**/*.c)
C_SRC   = $(SRCDIR)/main.c $(wildcard $(SRCDIR)/*.c) $(SRCDIR)/cordlib/cord_hw.c $(SRCDIR)/cordlib/cord_init.c $(SRCDIR)/cordlib/cord_connection.c $(SRCDIR)/cordlib/cord_protocol.c $(SRCDIR)/jsmn/jsmn.c
ASM_SRC =

C_SRC_FILE = $(patsubst $(SRCDIR)/%,%,$(C_SRC))
C_OBJ_FILE = $(C_SRC_FILE:%.c=%.c.rel)

OBJ = $(addprefix $(OBJDIR)/, $(C_OBJ_FILE))

# Memory Model (small, medium, large, huge)
MODEL  = large

# Memory Layout
CODE_SIZE = --code-loc  0x0000 --code-size 65536
IRAM_SIZE = --idata-loc 0x0000 --iram-size 256
XRAM_SIZE = --xram-loc  0x0000 --xram-size 1024


# SDCC
CC = sdcc
AS = sdas8051

MCU_MODEL = mcs51

#LIBS    =
#LIBPATH = -L $(LIBDIR)

#DEBUG = --debug
AFLAGS = -l -s
CFLAGS = -I./inc -I$(INCDIR) -m$(MCU_MODEL) --model-$(MODEL) --out-fmt-ihx --no-xinit-opt $(DEBUG)
LFLAGS = $(LIBPATH) $(LIBS) -m$(MCU_MODEL) --model-$(MODEL) $(CODE_SIZE) $(IRAM_SIZE) $(XRAM_SIZE) --out-fmt-ihx  $(DEBUG)

.PHONY: all clean

all: $(TARGET).hex


$(HEXDIR)/%.hex: $(OBJDIR)/%.ihx
	$(S) packihx $^ > $@

$(OBJDIR)/%.ihx: $(OBJ)
	$(S) $(CC) -o $@ $(LFLAGS) $^

$(OBJ): $(OBJDIR)/%.c.rel: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(S) $(CC) -o $@ $(CFLAGS) -c $^

$(OBJDIR)/%.asm.rel: $(SRCDIR)/%.asm
	$(S) $(AS) $(AFLAGS) -o $@ $^

clean:
	$(S) rm -rf $(OBJDIR)/*
	$(S) rm -rf $(TARGET).hex
