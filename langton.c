#include "langton.h"
#include <stdio.h>
void turn_left(struct ant *ant){
    if(ant->direction == UP){
        ant->direction = LEFT;
    }
    else if(ant->direction == LEFT){
        ant->direction = DOWN;
    }
    else if (ant->direction == DOWN){
        ant->direction = RIGHT;
    }
    else{
        ant->direction = UP;
    }
}
void turn_right(struct ant *ant){
    if(ant->direction == UP){
        ant->direction = RIGHT;
    }
    else if(ant->direction == LEFT){
        ant->direction = UP;
    }
    else if (ant->direction == DOWN){
        ant->direction = LEFT;
    }
    else{
        ant->direction = DOWN;
    }
}

void move_forward(struct ant *ant){
    if(ant->direction == UP){
        ant->y += -1;
    }
    else if(ant->direction == LEFT){
        ant->x += -1;
    }
    else if (ant->direction == DOWN){
        ant->y += 1;
    }
    else{
        ant->x += 1;

    }

}

void apply_rule(enum colour *colour, struct ant *ant){ // Using LR rules
    if(*colour == 0){ //If in state 0 turn left
       turn_left(ant);
	//printf("%d", *colour);
       	*colour = BLACK;
    }
    else{  //If in state 1 turn right
        turn_right(ant);
	//printf("%d", *colour);
       	*colour = WHITE;
    }
}
