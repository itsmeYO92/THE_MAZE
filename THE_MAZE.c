#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

char level[32][200];
void init_level(int n);
void print_level(void);
void move_player(char mv);
int is_success(void);

int p_x = 0, p_y = 0;  /* Player initial position */

int main(void)
{

	char mv;
	system("clear");
	system( "/bin/stty --file=/dev/tty -icanon" );  /*no need to hit enter when you move*/
	int level=1;
	init_level(level);        /* initialising the level array from the level file text */

	print_level();       /* printing the maze to the console */
	
GET_MV:
	mv=getchar();
	move_player(mv);     
	print_level();
	if(is_success())
	{
		level++;
		p_y = 0;	
		p_x = 0;
		init_level(level);
		print_level();		
	}
	goto GET_MV;

	
	return (0);
}


void init_level(int n)
{
	FILE *maze;
	char lev[30];

	sprintf(lev,"level%d.txt",n);
	maze=fopen(lev,"r");
	char line[200];

	for (int i = 0;i < 32; i++)
	{
		fgets(line,sizeof(line), maze);
		strcpy(level[i],line);
	}

	level[p_y][p_x]='@';
	fclose(maze);
	lev[0] = '\0';
} 

void print_level(void)
{
	system("clear");
	for (int i=0; i < 32; i++)
		printf("%s",level[i]);


//	printf("\n px = %d  py = %d", p_x, p_y);
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
		if( p_x < 60)
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


int is_success(void)
{
	if (p_x == 59 && p_y == 30)
		return (1);
	return (0);
} 


