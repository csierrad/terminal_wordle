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



int *check_word(char *word)
{
	int i;
	int *word_status = (int *)malloc(5 * sizeof(int));

	for(i = 0; word[i]; i++)
	{
		word_status[i] = check_letter(word[i], i);
	}

	return (word_status);
}
