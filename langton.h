#ifndef langton_h
#define langton_h

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant{
    int x;
    int y;
    enum direction direction;
};

struct rule{
    char* rules;
};

#define ant_is_at(posy, posx) (posy == ant->y && posx == ant->x)

enum colour { WHITE, BLACK };
void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

void apply_rule(enum colour *colour, struct ant *ant);
void apply_rule_general(int *colour, struct ant *ant, struct rule *rule);
// I have changed the function signature for apply_rule_general
// to take an int instead of a enum colour.

// Anne Reinarz 24/01/2023 -
// "For the apply_rule_general you can change the input argument types
// as long as you keep the total number of arguments."
#endif
