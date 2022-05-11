#include "brainf.h"

#include "common.h"

// !!(is this a session?)
// !(is a file being run?)
bool REPL = true;

// most redundant function award!
// however, good for organising parts of the interpreter, I suppose
void Init() { InitMem(); }

// the real deal, finally
void Run(char *command) {
  // if error and running from a file, stop running
  if (error && !REPL) exit(0);
  error = false;  // reset since there's either no error or an REPL error

  u32 index;
  u32 len = strlen(command);
  for (u32 i = 0; i < len; i++)
  {
    
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