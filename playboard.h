#ifndef PLAYBOARD_H_INLCUDE
#define PLAYBOARD_H_INLCUDE

#include "koop.h"
#define BOARD_ROW 6
#define BOARD_COL 7
#define INPUT 10	/*max length of checked input*/
#define INPUT_CHECK "1234567" /*legal inputs*/

void print_playboard(char playboard[][BOARD_ROW]);						
int set_playboard(char playboard[][BOARD_ROW], char player[][NAME]);
int read_player_move(char player[]);


#endif
/*PLAYBOARD_H_END*/