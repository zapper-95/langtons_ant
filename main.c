#include <stdio.h>
#include <stdlib.h>
#include "visualiser.h"
#include <string.h>
bool ValidRule(char* rule);

int main(int argc, char* argv[]) {
    char* current_rule = "";
    struct ant *ant = malloc(sizeof(struct ant));

	if(argc > 1) {  // if the user has entered a rule, use that rule
		current_rule = argv[1];
		// the rule is assumed to be contained in only the first argument

		// ensure that the rule is valid (i.e consists of only R's and L's)
		if(!ValidRule(current_rule)) {
			printf("Invalid rule entered."
			" Please provide a rule consisting only of R's and L's. \n");
			free(ant);
			return (-1);
		}

		start_visualisation(ant);

		// Stores the rule in a struct and allocates
		// the correct amount of memory for it
		struct rule *rule = malloc(sizeof(char)*strlen(current_rule));
		rule->rules = current_rule;

		// runs the advanced functionality
		for (int i = 0; i < 0; i++) {
			advanced_visualise_and_advance(ant, rule);
		}
		do {
			advanced_visualise_and_advance(ant, rule);
		} while (not_quit());

		free(rule);  // free the memory allocated for the rule
					 // (as it is no longer needed)
	} else {  // runs the basic functionality if no rule is provided
		start_visualisation(ant);

		do {
			visualise_and_advance(ant);
		} while (not_quit());
	}

    end_visualisation();
	free(ant);
    return(0);
}



// check the rule is valid by iterating
// through each character and checking it is either an R or L
bool ValidRule(char* rule) {
	int i = 0;
	while(rule[i] != '\0') {
		if(rule[i] != 'R' && rule[i] != 'L') {
			return false;
		}
		i++;
	}
	return true;
}



