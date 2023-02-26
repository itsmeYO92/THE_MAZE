#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char level[10][100];
void init_level(void);
void print_level(void);

int main(void)
{
	system("clear");

	init_level();

	print_level();

	return (0);
}


void init_level(void)
{
	FILE *maze;
	maze=fopen("level1.txt","r");
	char line[100];

	for (int i = 0;i < 10; i++)
	{
		fgets(line,sizeof(line), maze);
		strcpy(level[i],line);
	}
} 

void print_level(void)
{
	for (int i=0; i < 10; i++)
		printf("%s",level[i]);
}
