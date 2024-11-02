# brainfudge
A simple interpreter for the infamous esoteric language, in C. Made by me!  
Though, literally everyone has done this.
## What is brain... uh, fudge?
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
./brainfudge -h        # for help
./brainfudge           # for running REPL
./brainfudge -f <file> # for running brainfudge
./brainfudge -c <file> # for compiling to C
```

## Why did you make this?
I saw a video on brainfudge by Fireship and my brain decided to make something.
I really don't know why my brain acts like that, but it was nice making what I made.

## TODO
- Better memory management.
- Better error handling (specially for REPL).
- Fix potential undefined behaviour and bugs.

## Updates from last version:
Now you can transpile brainfudge to C!

## Anything else?
Now to add indentation to the compiled C... Tiresome work.  

PS:  
I renamed the repository just because mentioning this to people was getting tiresome.  
While I cannot afford to jeopardize my company, I can totally rename this repository so... Brainfudge.  
We live in a society.
