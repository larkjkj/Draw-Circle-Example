# TARGET
TARGET=sdl2.out

# C_SOURCE
C_SOURCE=$(wildcard *.c)

# COMPILER
CC=mips64r5900el-ps2-elf-gcc

# SPECIFY COMPILER FLAGS
CC_FLAGS=-O2  \
	 -lSDL2 \
	 -lm

# TARGETS
all:
	$(CC) $(CC_FLAGS) $(C_SOURCE) -o $(TARGET)
clean:
	rm -rf $(TARGET)
