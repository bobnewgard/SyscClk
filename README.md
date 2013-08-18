## Introduction

This project implements the SyscClk namespace, containing a general-purpose
clock class Clk for SystemC test benches.
Clk wraps the SystemC channel class sc\_core:sc\_clock and provides a
single sc\_core:sc\_out interface.

Clk is templated to provide flexibility of output type.  A single
template parameter specifies the type to the sc\_core:sc\_out interface.

The constructor arguments for Clk match the underlying sc\_core:sc\_clock arguments
and are provided without modification
to sc\_core:sc\_clock class.

### Use Cases

* Driving multiple clock inputs from the same source.
* Driving a bool signal
* Driving a sc\_logic signal

### Unsupported Use Cases

* TBD

### Test Bench

The test bench implemented as part of this project is used to validate the
SyscClk namespace.

### SystemC

The test bench uses the [Accellera](http://www.accellera.org/home/)
implementation of the SystemC classes to provide
a simulation kernel and the base class of the test bench.

The path to the SystemC installation is set in the makefiles using the
variable SYSC\_DIR.

## Validated Environments

Driving bool and sc\_logic signals has been validated in the following environments

| Linux                | libc  | gcc   | SystemC | make | bash   |
|----------------------|-------|-------|---------|------|--------|
| Debian 3.2.0-4-amd64 | 2.13  | 4.7.2 | 2.3.0   | 3.81 | 4.2.37 |

## Other Dependencies

Dependencies beyond those listed above under the Validated Environments heading are the projects

* SyscMake
* SyscMsg

## Installation

1. Make sure you have installed the components shown in the
   "Validated Environments" section
    * Install SystemC from source, since it is unlikely to be
      packaged
1. Clone repos listed in "Other Dependencies"
    * Clone such that SyscClk and the other Sysc\* repos are
      in the same directory
1. Modify the path to the SystemC installation, SYSC\_DIR,
   in SyscMake/vars.mk
1. execute "make" for hints about available targets

## Issues

* Bug tracker TBD

## Comms

* Mailing list TBD

## License

### License for Code

The code in this project is licensed under the GPLv3

### License for This Project Summary

This work is licensed under the Creative Commons Attribution-ShareAlike 3.0
Unported License. To view a copy of this license, visit
http://creativecommons.org/licenses/by-sa/3.0/. 
