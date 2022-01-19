#include "functions.h"

char word[] = "METAL";



int check_letter(char c, int index)
{	
	int i;

	for(i = 0; word[i]; i++)
	{
		if(word[i] == c)
		{
			break;
		}
		if(i == 4)
		{
			return (0); // La letra no está en la palabra
		}
	}

	if(word[index] == c)
	{
		return (1); // c está en word y en la misma posición
	}

	return(2); //c está en word pero no en la misma posición
}


//REcordar hacer free(sol_status)!!!!!!!!!!!!!!!!!!
int *check_word(char *sol)
{
	int i;
	int *sol_status = (int *)malloc(5 * sizeof(int));

	for(i = 0; sol[i]; i++)
	{
		sol_status[i] = check_letter(sol[i], i);
	}

	return (sol_status);
}

int main()
{
	int i;
	char sol[5] = "MAREO";
	int *sol_status = check_word(sol);
	
	for(i=0; i < 5; i++)
		printf("%d\n", sol_status[i]);

	return 0;
}