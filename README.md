# Design-and-Implementation-of-a-Debugging-System-Using-C-preprocessor-Directives

A custom C preprocessor implementation (my_Preprocessor) that parses .c source files and outputs processed .i files. Key features include:   Comment Removal: Strips single-line (//) and multi-line (/* */) comments.   Header Inclusion: Expands #include directives.   Macro Substitution: Replaces #define identifiers.  

## C Preprocessor Implementation
A custom C preprocessor executable (my_Preprocessor) that parses raw .c source files and generates expanded .i output files by stripping comments, resolving header dependencies, and expanding macro directives. Built using a modular architecture and managed with a standard Makefile.

## Features

-  Comment Removal: Strips both single-line (//) and multi-line (/* ... */) comments from the source file.
-  Header File Inclusion: Replaces #include directives with the actual contents of the specified header files.
-  Macro Substitution: Identifies #define directives and replaces all matching tokens with their defined values across the file.
-  Modular Codebase: Modularized structure for scalable C development and maintainability.

## File Overview

- Input (.c): Source code containing preprocessor directives, comments, and macros.
- Output (.i): Fully expanded preprocessed file ready for compilation.

## Getting Started

### prerequisites
- gcc (or any standard C compiler)
- make build tool

### Compilation
Build the project using the provided Makefile:
```bash
make
