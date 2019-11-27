#include <stdio.h>
#include <stdlib.h>

#include "helpful.h"

void keypress(void)
{	
	char c;
	c = getchar();
	if (c != '\n') buffer_clear();/*one time press only ?*/
}
void buffer_clear(void)
{
	char c;
	c = getchar();
	while (c != '\n') {
		c = getchar();
	}
}
void clear_screen(void)
{
	
	system("clear");/*better solution out there?*/
}