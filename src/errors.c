#include "errors.h"

#include "brainf.h"
#include "mem.h"  // read end note

bool error = false;

void Report(char *err, u32 character) {
  if (character == NO_CHAR) {
    printf("Error: %s\n", err);
  } else
    printf("Error: %s (at character %i)\n", err, character);
  // no REPL checking for now
  // if (!IsREPL()) {
    error = true;
    DestroyMem();
    exit(0);
  // }
}

bool IsError() { return error; }

// so... why I think that headers were a bad idea:
// I am no expert C connoisseur but I just don't like how I had to include
// "mem.h" in my source file instead of the header
// now many would argue that I should just have ALL my includes in my souce
// files but... what if there's a function or variable in the header that
// depends on the include? I'll stop ranting about this but yeah not really
// likeable I suppose
// temporary solution:
// follow this priority - brainf > mem > pointer > errors
// for moving include to source file in case of cyclic include