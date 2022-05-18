#include "brainf.h"
#include "common.h"

int main(int argc, char *argv[]) {
  Init();

  // go through arguments
  for (int i = 0; i < argc; i++) {
    if (!strcmp(argv[i], "-f") && i + 1 < argc) {
      Execute(argv[i + 1]);
      return 0;
    }
  }

  // REPL
  printf(
      "Brainfuck interpreter: version s.m.v.\n"
      "Please keep input under %d characters!\n"
      "Press ctrl-C to exit.\n",
      REPL_MAX_CHARS);
  for (;;) {
    printf(": ");

    // TODO: change this to have a flexible length
    char c[REPL_MAX_CHARS];
    fgets(c, REPL_MAX_CHARS, stdin);

    Run(c);
    printf("\n");
  }
  return 0;
}
// I DON "TKNOW WHAT"I AM DOING WITH MY LI FE HEKPE HELP
// kidding, take care dear programmers