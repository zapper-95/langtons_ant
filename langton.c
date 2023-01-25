#include "langton.h"
#include <stdio.h>
#include <string.h>
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
       	*colour = BLACK;
    }
    else{  //If in state 1 turn right
        turn_right(ant);
       	*colour = WHITE;
    }
}

void apply_rule_general(enum adv_colour *colour, struct ant *ant, struct rule *rule){
    //Iterate through each character for the rule string in the rule struct
    //if the colour is equal to the current index, then perform turn left (if the character is L)
    //or turn right (if the character is R)
    // afterwards, increment the colour by 1, wrapping back around to 0 if it is greater or equal to the length of the rule string
    for(int i = 0; i < strlen(rule->rules); i++){
        if(*colour == i){
            if(rule->rules[i] == 'L'){
                turn_left(ant);
            }
            else if(rule->rules[i] == 'R'){
                turn_right(ant);
            }
            *colour = (*colour + 1) % strlen(rule->rules);
            break;
        }
    }
}
