# TARGET
EE_BIN		+= main.elf

# C_SOURCE
EE_C		+= main.c

# O FILE
EE_OBJS		+= main.o

# SPECIFY COMPILER FLAGS
EE_INCS		+= -I$(PS2SDK)/common/include -I$(PS2SDK)/ports/include -I$(GSKIT)/include
EE_LDFLAGS	+= -L$(PS2SDK)/ports/lib/ -L$(GSKIT)/lib
EE_LIBS		+= -lm -lc -lSDL2 -lSDL2main -ldebug -lps2_drivers -lgskit -ldma -ldmakit

# TARGETS
all: $(EE_BIN)

clean:
	rm -rf $(TARGET)

include $(PS2SDK)/samples/Makefile.eeglobal
include $(PS2SDK)/Defs.make
