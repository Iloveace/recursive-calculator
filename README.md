# Recursive Calculator

This program is a command-line calculator written in C++ that implements
a recursive descent parser. It evaluates simple arithmetic expressions
passed as a string via the command line.

## Supported Features

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Parentheses for grouping
- Unary plus and minus (e.g., `-5`, `+(3)`, `-(2+4)`)

## Build

Compile with:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Main.cpp RecCal.cpp -o toy-app