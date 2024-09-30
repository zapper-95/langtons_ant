# Langton's Ant

## Overview
* This repository implements a generalisation of [Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant) in C. Langton's ant is a 2 dimensional cellular automata that demonstrates emergent behaviour through a simple set of rules.
* I completed this project as part of my university's systems programming module, where it achieved a mark of 87/100.   


## Basic Rules
* Intially all cells are in state 1.
* When the ant is on a cell in state 1, it does the following:
    1. Turns left
    2.  Changes the cell to state 2
    3.  Moves forward 1 space
* Conversely, when the ant is on a cell in state 2, it does the following:
    1. Turns right
    2.  Changes the cell to state 1
    3.  Moves forward 1 space
* If the ant ever goes past the edge of grid, it wraps around to the other side

## Advanced Rules
* A more general implementation exists for a `n-state ant`. The cells can be in states `1` through to `n`, with 'L' or 'R' indicating whether the ant should turn left or right, for a given state. 
* For example, with the rule set `LLRR`, the ant would turn left in states 1 and 2, and right in states 3 and 4.
* After visting a cell in state `i`, the cell's state is incremented to `i+1`. For state `n`, it loops back around and to state 1.

## Basic Rule Set (LR)
![LR Rule Set](./basic_ant.gif)
## Advanced Rule Set (LLRR)
![LLRR Rule Set](./llrr_ant.gif)

## Set Up
### Using GCC
* To compile the code, you will need gcc. If using windows, download WSL and install gcc using 
`sudo apt install gcc`. Alternatively, download mingw or any other support for the gcc compiler on windows.

* You will also need make to run the makefile. Install it with the linux command `sudo apt install make`.


### Compilation
To compile the code please use the following commands in order:

1. `make library`
2. `make`

`make library` will compile the dynamically linked library into "libant.so"

`make` will compile main.c and libant.so into an executable, which will subsequently be run.

### Running the Code
* To run the executable `./ant` in a CLI, first run `export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH`. This will add the current directory to the path which the dynamic linker searches.
* The terminal will then display an empty grid with the ant in the middle. 
Press `q` to quit, and any other key to advance the ant.

### Custom Rule Sets

Running `./ant`, will use the default ruleset `LR`, where states 1 and 2 are represented by black and white tiles respectively.

To use a custom rule set, please add an argument of a strings of L's and R's i.e `./ant "LLRR"`. 



Custom rule sets use characters to visualise different states: 

* `.` is state 1
* `1-9` are states 2-10
* `A-P` are states 11-26

When there are more than 26 rules, characters are re-used in the visualisation, i.e state 27 is `.`
