# Introduction

This project provides a generic function `compact` which
works on a simple `std::vector` by shifting **selected** elements
towards the beginning of the array based on the satisfaction
of a given *predicate*.

Such *predicate*, in turn, has to be programmed by the
application programmer, according to one's need.

The `compact` function warrants that the shifiting operation
keeps the original relative order among the selected elements.

# Compilation

To compile this project, run on the root folder the following
command:

```
g++ -Wall -std=c++11 -I include src/compact.cpp src/drive_compact.cpp -o bin/drive_compact
```
or just call `make`.


# TODO

You should alter this project so that it supports function
template, rather than explicity function pointer.
