# brainfuck
A brainfuck interpreter in C. Made by me!  
Though, literally everyone has done this.
## What is brainfuck?
It's a... uh... I-   
Just read this: https://en.wikipedia.org/wiki/Brainfuck
## How to run this?
Prerequisite: install realine.
```bash
sudo apt install libreadline-dev
```
First compile the files:
```bash
make
```
You can optionally add in `CC=<compiler of your choice>`.  
Then:
```
./brainfuck -h        # for help
./brainfuck           # for running REPL
./brainfuck -f <file> # for running brainfuck
./brainfuck -c <file> # for compiling to C
```

## Why did you make this?
I saw a video on brainfuck by Fireship and my brain decided to make something.
I really don't know why my brain acts like that, but it was nice making what I made.

## TODO
- Better memory management.
- Better error handling (specially for REPL).
- Fix potential undefined behaviour and bugs.

## Updates from last version:
Now you can compile brainfuck to C!

## Anything else?
Now to add indentation to the compiled C... Tiresome work, heh.
