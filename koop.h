#ifndef KOOP_H_INCLUDE
#define KOOP_H_INCLUDE

#define PLAYER 3 /*length of player_move array [0]: move [1]: playstone [3]: Name*/
#define SAVELINE 100
#define NAME 17
#define STONE 2

void koop_play(void);
void introduction(char name1[], char name2[], char player[][NAME]);
void read_names(char name[]);
void set_player(char player[][NAME], char name[]);
void set_stone(char player[][NAME], char playstone[], char name2[]);
void change_stone(char player[][NAME], char stone[]);

#endif
/*KOOP_H_END*/