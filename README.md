# langtons_ant
To run please use the following commands in order:

make library  
make

This will firstly compile the dynamically linked library into "libant.so"
Then make will compile main.c and libant.so into an executable, which will subsequently be run.

To alter the rule set, please change the "ARGUMENT" after the ./ant "ARGUMENT" to your desired rules i.e LLRR

The only altered function signature is "apply_rule_general".
I have changed the the input argument type *colour, to an int whilst keeping the total number of arguments the same 

When there are more than 26 rules, I have coded it so that characters are re-used in the visulisation

I Hope everything runs well :)
