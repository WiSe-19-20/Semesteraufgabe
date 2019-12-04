#ifndef WIN_H
#define WIN_H

#include "playboard.h"

#define WIN 1
#define NOTHING 0

int check_for_win(char playboard[][BOARD_ROW]);
int win_row(char playboard[][BOARD_ROW]);
int win_column(char playboard[][BOARD_ROW]);
int win_dia_left_right_up(char playboard[][BOARD_ROW]);
int win_dia_left_right_down(char playboard[][BOARD_ROW]);


#endif
/*WIN_H_END*/