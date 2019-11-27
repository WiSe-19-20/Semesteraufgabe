/*********************************************************
Alpha Version 0.2 
Last Edited 23.11.19
Editor Daniel Maquet 
Connect_4_01
**********************************************************/
/**********************************************************
*	Das Programm kann schon mal ein Feld befüllen mit 	  *
*	'X' je nach eingabe in die richtige Spalte		      *
*	TO DO: Abwechselnd und COMPUTER; Algo das einen Sieg  *
*	erkennt; Optimieren; Verbesserungen                   *
***********************************************************/
/*includes*/
#include <stdio.h>
#include <string.h>

#include "playboard.h"
#include "helpful.h"
#include "koop.h"

/*defines*/

/*functions*/																		
void menu(void);
void welcome_screen(void);


int main(void)
{	
	clear_screen();
	welcome_screen();
	menu();
	return 0;
}

void menu(void)
{	
	char game_menu[INPUT];
	int quit;
	quit = 0;
	while (1) {
		clear_screen();
		printf("\t\t\t\tCONNECT 4\n\n\t\t\t      CHOOSE BETWEEN:\n\t\t\t\t1) P1 vs. P2\n\t\t\t\t2) vs. COM\n\t\t\t\t3) quit"
				"\n\t\t\tYour choice: ");
		switch (read_player_move(game_menu)) {
			case 1: {
				switch (game_menu[0]) {
					case '1': koop_play(); break;
					case '2': break;
					case '3': quit = 1; break;
					default: break;
				}
				break;
			}
			case 2: quit = 1; break;
			default: break;
		}
		if (quit == 1) {
			break;
		}
	}

}

void welcome_screen(void)
{
	printf("\t\t\tWELCOME TO CONNECT 4!\n");
	printf("\n\n\t\t      Press ENTER to continue!\n");
	keypress();/*TO DO: hide input text*/
}
