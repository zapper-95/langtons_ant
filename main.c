#include <stdio.h>
#include <stdlib.h>
#include "langton.h"
#include "visualiser.h"

int main(){

    	struct ant *ant = malloc(sizeof(struct ant));
    	start_visualisation(ant);

	for (int i=0; i< 50000; i++){

		visualise_and_advance(ant);
	}
    	do
    	{
        	visualise_and_advance(ant);
    	} while (not_quit());  
    	end_visualisation();
	free(ant);    
    	return 0;
}

