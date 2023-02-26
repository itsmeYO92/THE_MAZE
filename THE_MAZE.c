#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char level[41][100];
void init_level(void);
void print_level(void);
void move_player(char mv);


int p_x = 0, p_y = 0;  /* Player initial position */

int main(void)
{
	char mv;
	system("clear");

	init_level();

	print_level();
	
GET_MV:
	mv=getchar();
	move_player(mv);
	print_level();
	goto GET_MV;

	
	return (0);
}


void init_level(void)
{
	FILE *maze;
	maze=fopen("level1.txt","r");
	char line[100];

	for (int i = 0;i < 41; i++)
	{
		fgets(line,sizeof(line), maze);
		strcpy(level[i],line);
	}
} 

void print_level(void)
{
	system("clear");
	for (int i=0; i < 41; i++)
		printf("%s",level[i]);
}


void move_player(char mv)
{
	if ('q' == mv)
	{
		if( p_x > 0)
		{
			if(level[p_y][p_x-1] == ' ')
			{
				level[p_y][p_x]=' ';
				level[p_y][p_x-1]='@';
				p_x--;
			}
		}
	}
	else if ('s' == mv)
	{
		if( p_x < 40)
		{
			if(level[p_y][p_x+1] == ' ')
			{
				level[p_y][p_x]=' ';
				level[p_y][p_x+1]='@';
				p_x++;
			}
		}
	}
		

	if ('z' == mv)
	{
		if( p_y > 0)
		{
			if(level[p_y-1][p_x] == ' ')
			{
				level[p_y][p_x]=' ';
				level[p_y-1][p_x]='@';
				p_y--;
			}
		}
	}
	else if ('w' == mv)
	{
		if( p_y < 40)
		{
			if(level[p_y+1][p_x] == ' ')
			{
				level[p_y][p_x]=' ';
				level[p_y+1][p_x]='@';
				p_y++;
			}
		}
	}
}
