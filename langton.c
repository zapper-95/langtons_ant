#include "langton.h"
#include <string.h>

void turn_left(struct ant *ant){ //Turns the ant left depending on its current direction
    if(ant->direction == UP){
        ant->direction = LEFT;
    }
    else if(ant->direction == LEFT){
        ant->direction = DOWN;
    }
    else if (ant->direction == DOWN){
        ant->direction = RIGHT;
    }
    else{ //right
        ant->direction = UP;
    }
}
void turn_right(struct ant *ant){ //Turns the ant right depending on its current direction
    if(ant->direction == UP){
        ant->direction = RIGHT;
    }
    else if(ant->direction == LEFT){
        ant->direction = UP;
    }
    else if (ant->direction == DOWN){
        ant->direction = LEFT;
    }
    else{ //right
        ant->direction = DOWN;
    }
}

void move_forward(struct ant *ant){
    if(ant->direction == UP){ //Moves the ant up because y=max_y-1 is at the lowest point and this decreases as you go upwards
        ant->y += -1;
    }
    else if(ant->direction == LEFT){
        ant->x += -1;
    }
    else if (ant->direction == DOWN){ //Moves the ant down because y=0 is at the highest point and this increases as you go downwards
        ant->y += 1;
    }
    else{
        ant->x += 1;
    }

}

void apply_rule(enum colour *colour, struct ant *ant){ // Using LR rules
    if(*colour == 0){ //If in state 0 turn left and change colour to state 1
       turn_left(ant);
       	*colour = BLACK;
    }
    else{  //If in state 1 turn right and change colour to state 0
        turn_right(ant);
       	*colour = WHITE;
    }
}


void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule){
    //check whether, for a given state, the ant should turn left or right
    //we do this by checking the rules string at the index corresponding to the state

    int state = *colour;

    if((rule->rules)[state] == 'L'){ 
        turn_left(ant);
    }
    else if((rule->rules)[state]== 'R'){
        turn_right(ant);
    }
    //increment the current state by 1. When we get to the end of the rules string we wrap around to the start
    *colour = (*colour + 1) % strlen(rule->rules);
}
