#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"
#include <string.h>
bool ValidRule(char* rule);

int main(int argc, char* argv[]){

		char* current_rule = "LR";

		if(argc > 1){ //if the user has entered a rule, use that rule, otherwise use basic rule
			current_rule = argv[1];
		}
		if(!ValidRule(current_rule)){
			printf("Invalid rule entered. Please provide a rule consisting only of R's and L's. \n");
			return 1;
		}	
		//Stores the rule in a struct and allocates the correct amount of memory for it
		struct rule *rule = malloc(sizeof(char)*strlen(current_rule));
		rule->rules = current_rule; 


    	struct ant *ant = malloc(sizeof(struct ant));
    	start_visualisation(ant);

		//for (size_t i = 0; i < 10000; i++)
		//{
		//	advanced_visualise_and_advance(ant, rule);			
		//}
		

    	do
    	{
        	//visualise_and_advance(ant);
			advanced_visualise_and_advance(ant, rule);
    	} while (not_quit());  
    	end_visualisation();
		free(ant);    
    	return 0;
}



//check in a function called valid rule if the rule is valid (i.e it consists only of R's and L's)
bool ValidRule(char* rule){
	int i = 0;
	while(rule[i] != '\0'){
		if(rule[i] != 'R' && rule[i] != 'L'){
			return false;
		}		
		i++;
	}
	return true;
}



