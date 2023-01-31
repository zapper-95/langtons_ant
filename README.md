# langtons_ant
## jbtl68
To run please use the following commands in order:

make library  
make

This will firstly compile the dynamically linked library into "libant.so"
Then "make" will compile main.c and libant.so into an executable, which will subsequently be run.

To alter the rule set, please change the "ARGUMENT" after the ./ant "ARGUMENT" to your desired rules i.e LLRR

The only altered function signature is "apply_rule_general".
I have changed the input argument type *colour, to an int whilst keeping the total number of arguments the same 

When there are more than 26 rules, I have coded it so that characters are re-used in the visualisation

For linting I applied cpplint. I ignored errors prompting me to use spaces instead of tab (personal preference) and about the line length, which would sometimes make it less readable. In the case of the mvprintw function I kept the brackets on the other line for readibility (as was done in the original visualiser.c file)

I Hope everything runs well :)
