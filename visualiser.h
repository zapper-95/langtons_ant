#ifndef visualiser_h
#define visualiser_h

#include "langton.h"
#include <stdbool.h>

static int max_x;
static int max_y;

typedef enum colour cell;
typedef int adv_cell;
void start_visualisation();
void visualise_and_advance();
void advanced_visualise_and_advance();
bool not_quit();

// optional (I have not used this function, but kept it
// in to not change the function signatures of the original file)
cell cell_at_fct(int y, int x);

void end_visualisation();
const char* direction_to_s(enum direction d);

#endif
