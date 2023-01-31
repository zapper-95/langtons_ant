#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"


#define cell_at(y, x) (cells[(y)*max_x + (x)])
#define cell_under_ant cell_at(ant->y, ant->x)

// returns the advanced cell
// (integer corresponding to the state) at the given position
#define adv_cell_at(y, x) (adv_cells[(y)*max_x+(x)])
#define adv_cell_under_ant adv_cell_at(ant->y, ant->x)

static char* states_display[] = {
    ".", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P"
};
cell* cells;
adv_cell* adv_cells;

void wrap_around(struct ant* ant);  // function prototype to wrap around

void start_visualisation(struct ant* ant) {
    setlocale(LC_ALL, "");

    initscr();
    curs_set(FALSE);
    max_x = getmaxx(stdscr);
    max_y = getmaxy(stdscr);

    cells = calloc(max_y*max_x, sizeof(cell));

    // allocates memory for the advanced cells and set them all to 0
    adv_cells = calloc(max_y*max_x, sizeof(adv_cell));
    ant->x = max_x/2;
    ant->y = max_y/2;
    ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
    /* Draw cells and ant */
    for (int y=0; y < max_y; y++) {
        for (int x=0; x < max_x; x++) {
        mvprintw(y, x,
            ant_is_at(y, x)
                ? direction_to_s(ant->direction)
                : cell_at(y, x)
                ? "█"
                : " "
        );
        }
    }
    refresh();

    /* Advance to next step */
    apply_rule(&cell_under_ant, ant);
    move_forward(ant);

    // changes the ant's position if it goes off the grid to a wrapped position
    wrap_around(ant);
}


void advanced_visualise_and_advance(struct ant* ant, struct rule* rules) {
      for (int y=0; y < max_y; y++) {
         for (int x=0; x < max_x; x++) {
            // gets an int corresponding to the cells state
            int current_state = adv_cell_at(y, x);
            mvprintw(y, x,
               ant_is_at(y, x)
                 ? direction_to_s(ant->direction)
                 :states_display[current_state%26]
                // displays the state with its corresponding
                // character in the states_display string
                // if there are more than 26 states then repeat the symbols
                // in the visualisation by wrapping back around
         );
         }
      }

    refresh();

    /* Advance to next step */
    apply_rule_general(&adv_cell_under_ant, ant, rules);
    move_forward(ant);

    // changes the ant's position if it goes off the grid to a wrapped position
    wrap_around(ant);
}



// Check if the user has input "q" to quit
bool not_quit() {
    return 'q' != getch();
}

void end_visualisation() {
    free(cells);
    free(adv_cells);
    endwin();
}

const char* direction_to_s(enum direction d) {
    return UP   == d ? "^" :
            DOWN == d ? "v" :
            LEFT == d ? "<" :
            /* else */  ">";
}

// all four cases are checked to see whether
// the ant needs its position to be adjusted
void wrap_around(struct ant* ant) {
    if (ant->x < 0) {
    ant->x = max_x-1;
    } else if (ant->x >= max_x) {
        ant->x = 0;
    } else if (ant->y <0) {
        ant->y =  max_y-1;
    } else if (ant->y >= max_y) {
        ant->y = 0;
    }
}


