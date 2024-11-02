CC = gcc
TITLE = brainfudge
CFILES = src/main.c src/common.c src/brainf.c src/mem.c src/transpiler.c src/errors.c

smv:
	@$(CC) $(CFILES) -lreadline -o $(TITLE)