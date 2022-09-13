#include "transpiler.h"

#include "common.h"

void Compile(char *file_name) {
  char *command = read_file(file_name);
  int len = strlen(command);

  int indent = 0;
  int bracket_num = 0;

  // clear file first
  FILE *clear = fopen("./out.c", "w");
  fprintf(clear, "%s", "");

  FILE *file = fopen("./out.c", "a");

  fprintf(file, "%s",
          "#include <stdio.h>\n"
          "\n"
          "#define REPL_MAX_CHARS (1024)"
          "\n"
          "int main() {\n"
          "char memory[30000];\n"
          "int pointer = 0;\n"
          "\n");

  for (int i = 0; i < len; i++) {
    char c = command[i];
    switch (c) {
      case '.':
        fprintf(file, "%s", "printf(\"%c\", memory[pointer]);\n");
        break;

      case ',':
        fprintf(file, "%s",
                "char input[REPL_MAX_CHARS];\n"
                "printf(\"input: \");\n"
                "fgets(input, REPL_MAX_CHARS, stdin);\n");
        break;

      case '>':
        fprintf(file, "%s", "pointer++;\n");
        break;
      case '<':
        fprintf(file, "%s", "pointer--;\n");
        break;

      case '+':
        fprintf(file, "%s", "memory[pointer]++;\n");
        break;
      case '-':
        fprintf(file, "%s", "memory[pointer]--;\n");
        break;
      case '[':
        bracket_num++;
        fprintf(file, "%s", "while(memory[pointer]) {\n");
        break;
      case ']':
        bracket_num--;
        fprintf(file, "%s", "}");
      default:
        break;
    }
  }

  fprintf(file, "%s",
          "return 0;\n"
          "}");

  if (bracket_num)
    printf(
        "NOTE: While file has been written, it seems that your code has "
        "errors.\n");
  else
    printf("Done!\n");
}