#include "errors.h"

#include "mem.h"  // read end note

void Report(char *err, u32 character) {
  if (character == NULL) {
    printf("Error: %s\n", err);
  } else
    printf("Error: %s at character %li\n", err, character);

  error = true;
}

// so... why I think that headers were a bad idea:
// I am no expert C connoisseur but I just don't like how I had to include
// "mem.h" in my source file instead of the header
// now many would argue that I should just have ALL my includes in my souce
// files but... what if there's a function or variable in the header that
// depends on the include? I'll stop ranting about this but yeah not really
// likeable I suppose
// temporary solution:
// follow this priority - brainf > mem > errors
// for moving include to source file in case of cyclic include