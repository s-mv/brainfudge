#ifndef smv_bf_impl_h
#define smv_bf_impl_h

#include <signal.h>

#include "common.h"
#include "errors.h"
#include "mem.h"

// initialise... _stuff_
void Init();
// run the command, duh
void Run(char *command);
// bad naming in action, this just *Run*s what is in the file
void Execute(char *file_name);
void Destroy();

bool IsREPL();

#endif