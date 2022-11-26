#include <readline/history.h>
#include <readline/readline.h>

#include "brainf.h"
#include "common.h"
#include "transpiler.h"

extern u32 id;

int main(int argc, char *argv[]) {
  Init();

  // go through arguments
  for (int i = 0; i < argc; i++) {
    if (!strcmp(argv[i], "-h")) {
      printf("%s", help_message);
      return 0;
    }
    if (!strcmp(argv[i], "-f")) {
      if (i + 1 >= argc)
        printf("File name not provided.\n");
      else
        Execute(argv[i + 1]);
      return 0;
    }
    if (!strcmp(argv[i], "-c")) {
      if (i + 1 >= argc)
        printf("File name not provided.\n");
      else
        Compile(argv[i + 1]);
      return 0;
    }
  }

  // REPL
  // now with readline hehe
  printf(
      "Brainfuck interpreter: version s.m.v.\n"
      "Please keep input under %d characters!\n"
      "Press ctrl-C to exit.\n"
      "Use -h for help.\n",
      REPL_MAX_CHARS);

  read_history("./.bf_hist");
  loop {
    id = 0;
    char *c = readline(": ");
    Run(c);
    add_history(c);

    printf("\n");
  }

  return 0;
}