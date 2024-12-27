CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o menu.o conversion.o
EXEC = convertisseur

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c menu.h
menu.o: menu.c menu.h conversion.h
conversion.o: conversion.c conversion.h

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean
