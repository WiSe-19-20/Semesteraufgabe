#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "playboard.h"
#include "helpful.h"
#include "koop.h"

void koop_play(void)
{	
	char playboard[BOARD_COL][BOARD_ROW], name1[NAME], name2[NAME], player[PLAYER][NAME], playstone[STONE];
	int i, j, controll;
	srand(time(NULL));
	for (i = 0; i < BOARD_ROW; ++i) {
		for (j = 0; j < BOARD_COL; ++j) {
			playboard[j][i] = 32;			/*initialize array with 'space'*/
		}
	}
	introduction(name1, name2, player);
	if (strcmp(player[2], name1) == 0) {
		set_stone(player, playstone, name2);
	} else {
		set_stone(player, playstone, name1);
	}
	while(1){
		print_playboard(playboard);
		printf("\n\t\t\tYour move %s: ", player[2]);
		/*player input label*/
		controll = read_player_move(player[0]);
		if (controll == 1) {
			controll = set_playboard(playboard, player);
			if (strcmp(player[2], name1) == 0) {
				set_player(player, name2);
				change_stone(player, playstone);
			} else {	
				set_player(player, name1);
				change_stone(player, playstone);
			}
		}
		if (controll == 2) {
			break;
		}
		if (controll == 0) {
			printf("\n\t    Your input was incorrect, please input \"quit\" or a column!\n\t\t\tPress ENTER to continue!");
			keypress();
		}

	}
}

void introduction(char name1[], char name2[], char player[][NAME])
{
	clear_screen();
	printf("\n\t\t\tWelcome to Con4!"
			"\n\t\t--------------------------------"
			"\n\t\tFirst input your names [1-16]! \n\t\t"
			"The first 16 character will be taken:"
			"\n\t\tFirst Player: ");
	read_names(name1);
	printf("\t\tSecond Player: ");
	read_names(name2);
	printf("\n\t\tNow we random choose who Player1 is."
		"\n\t\t(Player1 has the right to start)\n");
	if ((rand() % 2) == 0) {
		printf("\n\t\t%s is Player1", name1);
		set_player(player, name1);
		printf("\n\t\t%s is Player2", name2);
	} else {
		printf("\n\t\t%s is Player1", name2);
		set_player(player, name2);
		printf("\n\t\t%s is Player2", name1);
	}
	printf("\n\n\t\tPress ENTER to continue!");
	keypress();
}

void read_names(char name[])
{	
	char c;
	int i;
	i = 0;
	c = getchar();
	while (c != '\n' && i < NAME - 1) {
		name[i++] = c;
		c = getchar();
	}
	if (c != '\n') {
		buffer_clear();
	}
	name[i] = '\0';
}	

void set_player(char player[][NAME], char name[])
{
	int i;
	for (i = 0; i < NAME; ++i) {
		player[2][i] = name[i];
		if (name[i] == '\0') {
			break;
		}
	}
}

void set_stone(char player[][NAME], char playstone[], char name2[])
{	
	char c;
	clear_screen();
	printf("\n\t\tNow each player can choose their individual playstone."
			"\n\t\tIt must be different for each player!"
			"\n\t\tFor fairness %s(Player2) can choose first: "
			"\n\t\tChoose wisely the first legal symbol will be taken!!"
			"\n\n\t\tYour choice %s: ", name2, name2);
	c = getchar();
	while (c == '\n' || c == 32) {
		printf("\n\n\t\tEverything except ENTER and SPACE: ");
		c = getchar();
	}
	buffer_clear();
	playstone[1] = c;

	printf("\n\t\t%s your choice was: %c."
			"\n\t\tNow %s(Player1), remember you can't choose %c."
			"\n\n\t\tYour choice %s: ", name2, playstone[1], player[2], playstone[1], player[2]);
	c = getchar();
	while (c == '\n' || c == 32 || c == playstone[1]) {
		printf("\n\n\t\tEverything except ENTER, SPACE and %c: ", playstone[1]);
		c = getchar();
	}
	buffer_clear();
	player[1][0] = c;
	playstone[0] = c;

	printf("\n\t\t%s your choice was: %c."
			"\n\n\t\tPress ENTER to start the game!", player[2], playstone[0]);
	keypress();
}

void change_stone(char player[][NAME], char stone[])
{
	if (player[1][0] == stone[0]) {
		player[1][0] = stone[1];
	} else {
		player[1][0] = stone[0];
	}
}
