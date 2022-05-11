#include "mem.h"

#define MEMORY_LIMIT (65536)

u16 mem_len = 8;  // length of memory
u8 *memory;       // actual memory

void InitMem() {
  // first free memory
  // NOTE: what? when will this even be needed?
  free(memory);

  // at the very beginning, we go with 8 bytes instead of 1 single byte because
  // 7 extra bytes for only 1 used sounds okay; having to expand to 2, then 4,
  // then 8 the very instant you start running the program, not that okay
  memory = (u8 *)malloc(8 * sizeof(u8));
}

// oh no here we are, read end note
void ExpandMem() {
  if (mem_len >= MEMORY_LIMIT) {
    Report("Memory limit reached. Stopping.", NULL);
    free(memory);
    exit(0);
  }

  mem_len *= 2;
  realloc(memory, mem_len);

  // repeating lines of code, nooo
  // is using goto in this case bad practice? this is so AAAAA
  if (memory == NULL) {
    Report("Error managing memory. Stopping.", NULL);
    free(memory);
    exit(0);
  }
}

u8 Mem(u16 pointer);

// it kills me to write this ExpandMem because of my own slighly insane
// beliefs about optimisation blocking the wonderful sunset of logic from my
// vision, I just dislike thinking of how the compiler at some point will try to
// reallocate 2^10ish bytes of memory but... I took a little break from life and
// gave this some thought: isn't this method worth it? the answer is that it is,
// the overall cost of implementing growing memory is less than having a 30,000
// byte array at the very beginning...