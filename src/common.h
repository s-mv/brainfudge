#ifndef smv_common_stuff_bf_impl_h
#define smv_common_stuff_bf_impl_h

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define loop for (;;)
#define NO_CHAR (-1)
// not _that_ common but oh well
#define REPL_MAX_CHARS (1024)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t i32;
// yes I _know_ that I'm typedefing a typedef typedef

static const char *help_message =
    "Help:\n"
    "-h           - print this message\n"
    "-c <file>    - compile to C code (out.c)\n"
    "-f <file>    - fun a file\n"
    "<no options> - run REPL mode\n";

char *read_file(char *file_name);
void write_file(char *file_name);

#endif