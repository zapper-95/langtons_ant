#include <ncursesw/curses.h>
#include <locale.h>
#include <stdlib.h>
#include "visualiser.h"


#define cell_at(y,x) (cells[(y)*max_x + (x)])
#define cell_under_ant cell_at(ant->y,ant->x)

#define adv_cell_at(y,x) (adv_cells[(y)*max_x+(x)])
#define adv_cell_under_ant adv_cell_at(ant->y,ant->x)

cell *cells;
adv_cell *adv_cells;

void wrap_around(struct ant* ant); //function prototype

void start_visualisation(struct ant* ant) {
  setlocale(LC_ALL, "");

   initscr();
   curs_set(FALSE);
   max_x = getmaxx(stdscr);
   max_y = getmaxy(stdscr);
   cells = calloc(max_y*max_x, sizeof(cell));
   adv_cells = calloc(max_y*max_x, sizeof(adv_cell));
   ant->x = max_x/2;
   ant->y = max_y/2;
   ant->direction = RIGHT;
}

void visualise_and_advance(struct ant* ant) {
      /* Draw cells and ant */
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 : cell_at(y,x)
                    ? "█"
                    : " "
            );
         }
      }
      refresh();

      /* Advance to next step */
      apply_rule(&cell_under_ant, ant);
      move_forward(ant);
	wrap_around(ant);      
}
//write the code to define a char array which contains the first 26 numbers (from 0 to 25) as chars. Call it states
char* states = ".123456789ABCDEFGHIJKLMNOP";


void advanced_visualise_and_advance(struct ant* ant, struct rule* rules){
      for (int y=0; y<max_y; y++)
      {
         for (int x=0; x<max_x; x++)
         {
            int current_state = adv_cell_at(y,x);
            //printf("%d", current_state);

            mvprintw(y,x,
               ant_is_at(y,x)
                 ? direction_to_s(ant->direction)
                 :states+current_state

            );
         
         }
      }

   refresh();
   apply_rule_general(&adv_cell_under_ant, ant, rules);
   move_forward(ant);
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
          /* else */  ">" ;
}

void wrap_around(struct ant* ant) {
      if(ant->x<0){
      ant->x = max_x-1;
   }
      else if(ant->x >= max_x){
      ant->x = 0;
   }
      else if(ant->y <0){
      ant->y =  max_y-1;
   }
      else if (ant->y >= max_y){
      ant->y = 0;
   }
}


