# Overview

This is a simple test program to mix ARM Cortex-M 'Thumb' assembly code and C code. It will define a weak reference to a 'main' method which simply loops, while a C file defines an overriding 'main' method that will actually execute the program's main code. The C method will then go on to call a mix of assembly functions and vendor-provided 'Standard Peripheral Library' C functions to blink an LED every half-second or so.

