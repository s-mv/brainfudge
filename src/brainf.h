#ifndef smv_bf_impl_h
#define smv_bf_impl_h

#include "common.h"
#include "mem.h"
#include "errors.h"

// initialise... _stuff_
void Init();
// run the command, duh
void Run(char *command);
// bad naming in action, this just *Run*s what is in the file
void Execute(char *file_name);

bool IsREPL();

#endif