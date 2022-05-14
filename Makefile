CC = gcc
TITLE = brainfuck
CFILES = src/main.c src/brainf.c src/mem.c src/errors.c

smv:
	@$(CC) $(CFILES) -o $(TITLE)