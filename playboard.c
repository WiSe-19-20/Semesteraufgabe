#include <stdio.h>
#include <string.h>

#include "playboard.h"
#include "helpful.h"
#include "koop.h"

void print_playboard(char playboard[][BOARD_ROW])
{	
	/*prints the playboard, parameter is multidimensional array for the player_moves*/
	int i, j;
	clear_screen();
	printf("\t\t\t\t CONNECT 4\n");
	printf("\n\t\tCOLUMN:   1   2   3   4   5   6   7");
	for (i = 0; i < BOARD_ROW; ++i) {
		printf("\n\t\t\t+---+---+---+---+---+---+---+\n\t\t\t|");
		for (j = 0; j < BOARD_COL; ++j) {
			printf(" %c |", playboard[j][i]);
		}
	}
	printf("\n\t\t\t+---+---+---+---+---+---+---+\n");
	
}

int set_playboard(char playboard[][BOARD_ROW], char player[][NAME])
{
	/*taking the input from player and set it into the array with a drop down take*/
	char move_prev, play_stone;
	int move, i, controll;

	play_stone = player[1][0];
	while(1) { /*legal move*/
		move_prev = player[0][0];
		move = move_prev - '1';
		if (playboard[move][0] != 32) {
			printf("\n\n    Your choosen Column is already full, please choose another one or quit: ");
			controll = read_player_move(player[0]);
			if (controll == 2) {
				return 2;
			}
			if (controll == 0) {
				printf("\n\t    Your input was incorrect, please input \"quit\" or a column!\n\t\t\t  Press any Key to continue!");
				keypress();
			}
			continue;
		}
		break;
	}
	for (i = 0; i < BOARD_ROW; ++i) {
		if (i == 5) {
			playboard[move][i] = play_stone;
			break;
		}
		if (playboard[move][i + 1] != 32) {
			playboard[move][i] = play_stone;
			break;
		}
	}
	return 1;	
}

int read_player_move(char player[])
{
	/*read the input from the player and evaluates it 0: wrong input/ 1: correct player_move/ 2: quit the game*/
	char temp[INPUT], c;
	int i;
	i = 0;
	c = getchar();
	while (c != '\n' && i < INPUT - 1) {
		temp[i++] = c;
		c = getchar();
	}
	if (c != '\n') {
		buffer_clear();
	}
	temp[i] = '\0';
	if (strcmp(temp, "quit") == 0) {
		return 2;
	}
	if (i > 1) {
		return 0;
	}
	if (strchr(INPUT_CHECK, temp[0]) != 0) {
		if (temp[0] == '\0') {
			return 0;
		}
		player[0] = temp[0];
		return 1;
	}
	return 0;
}