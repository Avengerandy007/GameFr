# GameFr
Is a c++ library designed to deal with the basic, somewhat boring parts of game dev so you can get faster to the cool parts.

# Building

## Dependencies:
 - Make
 - Cmake
 - a c++ compiler

## Instructions:

```bash
git clone https://github.com/Avengerandy007/GameFr
cd GameFr
cmake -S . -B build
cd GameFr/build
cmake --build .
```

# Usage:
1. Move the bin file and the headers in the directory of your project
2. Add them to you compiler and linker

# Features:
  - Predefined enitity class with basic functions like Push, rectangular and circular collision
  - Camera system to detect if an entity is on the screen and allows you to decide what to do in each case
