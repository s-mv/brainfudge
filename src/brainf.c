#include "brainf.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

// !!(is this a session?)
// !(is a file being run?)
bool REPL = true;

bool user_input = false;

u32 while_depth = 0;  // how deep are we in ['s?

u16 pointer = 0;  // read note at end
u32 id = 0;  // not `index` because of strings.h having some function named so

void SetPointer(u16 loc);
void RunChar(char c);
// void Loop(u32 index_, char *command);
void Close(int code);

// most redundant function award!
// however, good for organising parts of the interpreter, I suppose
void Init() {
  InitMem();
  // atexit(DestroyMem);
  signal(SIGINT, Close);
}

// loops, finally
void Run(char *command) {
  // I literally can't explain how I managed the loops in comments
  // but let me just say that a LOT of trial and error was included
  for (; command[id] != '\0'; id++) {
    char c = command[id];
    switch (c) {
      case ']': {
        if (while_depth == 0) Report("Extra ']'.", id);
        return;
      }
      case '[': {
        while_depth++;
        u32 temp_id = ++id;
        u16 temp_pointer = pointer;
        while (Mem(temp_pointer != 0)) {
          id = temp_id;
          Run(command);
        }
        while_depth--;
        break;
      }
      default: {
        RunChar(c);
        break;
      }
    }
  }
}

// the real deal, finally
void RunChar(char c) {
  // https://en.wikipedia.org/wiki/Brainfuck#Language_design
  switch (c) {
    case '.': {
      printf("%c", Mem(pointer));
      break;
    }
    case ',': {
      printf("input: ");

      char input[REPL_MAX_CHARS];

      user_input = true;
      fgets(input, REPL_MAX_CHARS, stdin);
      user_input = false;

      SetMem(pointer, input[0]);
      break;
    }
    case '>':
    case '<': {
      // why not just pointer++? refer to the function
      SetPointer(pointer + (c == '>' ? 1 : -1));
      break;
    }
    case '+':
    case '-': {
      // sets memory at *pointer* to *memory at pointer* +/- 1
      SetMem(pointer, Mem(pointer) + (c == '+' ? 1 : -1));
      break;
    }
    case '\0': {
      if (while_depth > 0) Report("'[' not closed", id);
      break;
    }
    default:
      printf("character: %c", c);
      // ignore
      break;
  }
}

void Execute(char *file_name) {
  REPL = false;  // not a session

  FILE *file = fopen(file_name, "r");
  // get length
  fseek(file, 0, SEEK_END);
  char command[ftell(file)];

  // read to command
  rewind(file);
  fscanf(file, "%s", command);
  printf("command %s\n", command);
  Run(command);
}

void SetPointer(u16 loc_) {
  // TODO somehow check if < was used to circle to the end of memory and then
  // instead of expanding to maximum length of array, just expand to 3x the size
  // with our current data copied at the centre of this new memory

  u16 loc = loc_ > MEMORY_LIMIT ? MEMORY_LIMIT - 1 : loc_;
  if (loc >= MEMORY_LIMIT / 2)
    ExpandMemTo(MEMORY_LIMIT);
  else if (loc >= MemLength())
    ExpandMemTo(loc * 2);
  pointer = loc;
}

bool IsREPL() { return REPL; }

void Close(int code) {
  // again, TODO ctrl-C exit fgets
  printf("\nExited.\n");
  DestroyMem();
  exit(code);
}

// pointer.c only held SetPointer, IncrementPointer, GetPointer, Pointer along
// with u16 pointer which seemed so redundant to be honest and not exactly
// worth modularising, fell in the same trap OOP fanatics fall in, writing
// much more code than needed in the end