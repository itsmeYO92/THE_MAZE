#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#define KRED "\x1B[31m"
#define KNOR "\x1B[37m"
	/*  FUNCTIONS   */

void init_level(int n);
void print_level(void);
void move_player(char mv);
int is_success(void);
char welcome_screen(void);

	/* GLOBAL VARIABLES */

char level[32][200];
char avatar ;     
int p_x = 0, p_y = 0;  /* Player initial position */

int main(void)
{
	system( "/bin/stty --file=/dev/tty -icanon" );  /*no need to hit enter when you move*/
	avatar = welcome_screen();
	char mv;
	system("clear");
	int level=1;
	init_level(level);         /* initialising the level array from the level text file */

	print_level();		   /* printing the maze to the console */
	
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

	level[p_y][p_x]=avatar;
	fclose(maze);
	lev[0] = '\0';
} 

void print_level(void)
{
	system("clear");
	for (int i=0; i < 32; i++)
	{
		if (i != p_y)
			printf("%s",level[i]);
		else
		{
			for (int j = 0; j < strlen(level[i]); j++)
			{
				if (j != p_x)
					printf("%c",level[i][j]);
				else
				{
					printf("%s",KRED);
					printf("%c", level[i][j]);
					printf("%s", KNOR);
				}
			}
		}

	}

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
				level[p_y][p_x-1]=avatar;
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
				level[p_y][p_x+1]=avatar;
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
				level[p_y-1][p_x]=avatar;
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
				level[p_y+1][p_x]=avatar;
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

char welcome_screen(void)
{
	
	int j = 0;
	char avatars[]="&!@/O";
	char ch;
PRINT:	
	system("clear");
	printf("\n\n\n		###    PLEASE MAXIMIZE THE WINDOWS    ###\n");
	printf("\n\n\n		   use q to move left, s to move right\n");
	printf("\n\n                     "); 
	for (int i = 0; i < 5 ; i++)
	{
		if(i == j)
		{
			printf("%s",KRED);
			printf("%c    ",avatars[i]);
			printf("%s",KNOR);
		}
		else
		{
		printf("%c    ", avatars[i]);
		}
	}
	
	ch = getchar();

	if (ch == 'q' && j > 0)
		j--;
	else if (ch == 's' && j < 4)
		j++;
	else if (ch == '\n')
		return(avatars[j]);

	goto PRINT;

	
}
