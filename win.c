#include "win.h"

int check_for_win(char playboard[][BOARD_ROW])
{
	int win;
	win = win_row(playboard);
	if (win == WIN) {
		return WIN;
	}
	win = win_column(playboard);
	if (win == WIN) {
		return WIN;
	}
	win = win_dia_left_right_up(playboard);
	if (win == WIN) {
		return WIN;
	}
	win = win_dia_left_right_down(playboard);
	if (win == WIN) {
		return WIN;
	}
	return NOTHING;
}

int win_row(char playboard[][BOARD_ROW])
{
	int row, column, count;
	char stone = 32;
	for (row = BOARD_ROW - 1; row >= 0; --row) {
		count = 0;
		for (column = 0; column < BOARD_COL; ++column) {
			if (playboard[column][row] !=  32) {
				if (stone == playboard[column][row]) {
					++count;
				} else {
					stone = playboard[column][row];
					count = 0;
					++count;
				}
				if (count == 4) {
					return WIN;
				}
			} else {
				count = 0;
			}
		}
	}
	return NOTHING;
}

int win_column(char playboard[][BOARD_ROW])
{
	int row, column, count;
		char stone = 32;
		for (column = 0; column < BOARD_COL; ++column) {
			count = 0;
			for (row = BOARD_ROW - 1; row >= 0; --row) {
				if (playboard[column][row] !=  32) {
					if (stone == playboard[column][row]) {
						++count;
					} else {
						stone = playboard[column][row];
						count = 0;
						++count;
					}
					if (count == 4) {
						return WIN;
					}
				} else {
					count = 0;
				}
			}
		}
		return NOTHING;
}

int win_dia_left_right_up(char playboard[][BOARD_ROW])
{
	int row, column, count, last_three, times;
	char stone;
	stone = 32;
	times = 0;
	last_three = 0;
	for (row = 3; row < BOARD_ROW; ++row) {
		count = 0;
		if (row == BOARD_ROW - 1) {
			if (last_three == 3) {
				break;
			}
			if (times == 0) {
				++times;
				--row;
			} else {
				++last_three;
				--row;
			}
		}
		for (column = 0; (column + last_three) < BOARD_COL; ++column) {
			if ((row - column + times) < 0) break;
			if (playboard[column + last_three][row - column + times] != 32) {
				if (stone == playboard[column + last_three][row - column + times]) {
					++count;
				} else {
					stone = playboard[column + last_three][row - column + times];
					count = 0;
					++count;
				}
				if (count == 4) {
					return WIN;
				}
			} else {
				count = 0;
			}
		}
	}
	return NOTHING;
}

int win_dia_left_right_down(char playboard[][BOARD_ROW])
{
	int row, column, count, last_three, times;
	char stone;
	stone = 32;
	times = 0;
	last_three = 0;
	for (row = 2; row >= 0; --row) {
		count = 0;
		if (row == 0) {
			if (last_three == 3) {
				break;
			}
			if (times == 0) {
				++times;
				++row;
			} else {
				++last_three;
				++row;
			}
		}
		for (column = 0; (column + last_three) < BOARD_COL; ++column) {
			if ((row + column - times) >= BOARD_ROW) break;
			if (playboard[column + last_three][row + column - times] != 32) {
				if (stone == playboard[column + last_three][row + column - times]) {
					++count;
				} else {
					stone = playboard[column + last_three][row + column - times];
					count = 0;
					++count;
				}
				if (count == 4) {
					return WIN;
				}
			} else {
				count = 0;
			}
		}
	}
	return NOTHING;
}