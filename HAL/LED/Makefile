
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

MCU = atmega32
CLK = 8000000

CFLAGS    = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(MCU) 
CC      = avr-gcc.exe
Project_Name= LED

project: $(Project_Name)_program.o

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@