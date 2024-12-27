CC = gcc
CFLAGS = -Wall -Wextra -g `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`
OBJ = main.o menu.o conversion.o callbacks.o
EXEC = convertisseur

all: $(EXEC)

$(EXEC): $(OBJ)
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c menu.h
    $(CC) $(CFLAGS) -c $< -o $@

menu.o: menu.c menu.h conversion.h
    $(CC) $(CFLAGS) -c $< -o $@

conversion.o: conversion.c conversion.h
    $(CC) $(CFLAGS) -c $< -o $@

callbacks.o: callbacks.c callbacks.h
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(EXEC)

.PHONY: clean
