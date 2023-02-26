#include <stdio.h>
#include <stdlib.h>



char level[10][10];
void init_level(void);

int main(void)
{
	system("clear");

	init_level();

	printf("%s",level[3]);


	return (0);
}


void init_level(void)
{
	FILE *maze;
	maze=fopen("level1.txt","r");

	for (int i = 0;i < 10; i++)
		fgets(level[i],sizeof(level[i]), maze);
		
} 
