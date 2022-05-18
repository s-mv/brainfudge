#include "brainf.h"

// !!(is this a session?)
// !(is a file being run?)
bool REPL = true;

bool user_input = false;

u16 pointer = 0;  // read note at end

void SetPointer(u16 loc);
void Loop(u32 index, char *command);
void Close(int code);

// most redundant function award!
// however, good for organising parts of the interpreter, I suppose
void Init() {
  InitMem();
  // atexit(DestroyMem);
  signal(SIGINT, Close);
}

// the real deal, finally
void Run(char *command) {
  for (u32 i = 0; command[i] != '\0'; i++) {
    u8 c = command[i];
    // https://en.wikipedia.org/wiki/Brainfuck#Language_design
    switch (c) {
      case '.': {
        printf("%c\n", Mem(pointer));
        break;
      }
      case ',': {
        printf("input: ");

        char input[1000];

        user_input = true;
        fgets(input, 1000, stdin);
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
      // TODO loops
      case '[': {
        // ugly I know, but well...
        Loop(i, &(command[i + 1]));
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

void Loop(u32 index, char *command) {
  u16 temp_pointer = 0;
  for (size_t i = 0; command[i] != '\0'; i++) {
    char temp_pointer;
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
  // TODO somehow check if < was used to circle to the end of memory and then
  // instead of expanding to maximum length of array, just expand to 3x the size
  // with our current data copied at the centre of this new memory
  if (loc > MemLength()) ExpandMemTo(loc);
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
// with u16 pointer which seemed so redundant to be honest and not exactly worth
// modularising, fell in the same trap OOP fanatics fall in, writing much more
// code than needed in the end