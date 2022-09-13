CC = gcc
TITLE = brainfuck
CFILES = src/main.c src/common.c src/brainf.c src/mem.c src/transpiler.c src/errors.c

smv:
	@$(CC) $(CFILES) -o $(TITLE)