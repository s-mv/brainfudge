#include "common.h"

#include "errors.h"
// for read_file
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

char* read_file(char* file_name) {
  char* command;

  int f = open(file_name, O_RDONLY);
  if (f == -1) Report("Issue opening file.", NO_CHAR);

  struct stat sb;
  if (fstat(f, &sb) == -1) Report("Issue reading file.", NO_CHAR);

  command = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, f, 0);
  if (command == MAP_FAILED) Report("Issue reading file.", NO_CHAR);

  return command;
}

void write_file(char *file_name) {
  // write()
}