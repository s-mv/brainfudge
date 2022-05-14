#include "brainf.h"

// !!(is this a session?)
// !(is a file being run?)
bool REPL = true;

u16 pointer = 0;  // read note at end
void SetPointer(u16 loc);

// most redundant function award!
// however, good for organising parts of the interpreter, I suppose
void Init() { InitMem(); }

// the real deal, finally
void Run(char *command) {
  // u32 index;
  u32 len = strlen(command);
  for (u32 i = 0; i < len; i++) {
    u8 c = command[i];
    // https://en.wikipedia.org/wiki/Brainfuck#Language_design
    switch (c) {
      case '.': {
        printf("%c", Mem(pointer));
        break;
      }
      case ',': {
        // TODO: input
        break;
      }
      case '>':
      case '<': {
        // why not just pointer++? refer to the function
        SetPointer(pointer + c == '>' ? 1 : -1);
        break;
      }
      case '+':
      case '-': {
        // sets memory at *pointer* to *memory at pointer* +/- 1
        SetMem(pointer, Mem(pointer) + c == '+' ? 1 : -1);
        break;
      }
      // TODO loops
      case '[': {
        break;
      }
      case ']': {
        break;
      }
      default:
        // ignore
        break;
    }
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

  Run(command);
}

void SetPointer(u16 loc) {
  while (loc > MemLength()) ExpandMem();
  pointer = loc;
}

bool IsREPL() { return REPL; }

// pointer.c only held SetPointer, IncrementPointer, GetPointer, Pointer along
// with u16 pointer which seemed so redundant to be honest and not exactly worth
// modularising, fell in the same trap OOP fanatics fall in, writing much more
// code than needed in the end