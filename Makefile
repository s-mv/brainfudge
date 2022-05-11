CC = gcc
TITLE = brainfuck
CFILES = src/main.c src/brainf.c src/mem.h src/errors.h

smv:
	@$(CC) $(CFILES) -o $(TITLE)