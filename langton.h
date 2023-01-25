#ifndef langton_h
#define langton_h

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant
{
    int x;
    int y;
    enum direction direction;
};

struct rule
{
    char* rules;
};

#define ant_is_at(posy, posx) (posy == ant->y && posx == ant->x)

enum colour { WHITE, BLACK };
enum adv_colour {st_0, st_1, st_2, st_3, st_4, st_5, st_6, st_7, st_8, st_9, st_10, st_11, st_12, st_13, st_14, st_15, st_16, st_17, st_18, st_19, st_20, st_21, st_22, st_23, st_24, st_25};
void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

void apply_rule(enum colour *colour, struct ant *ant);
void apply_rule_general(enum adv_colour *colour, struct ant *ant, struct rule *rule);

#endif
