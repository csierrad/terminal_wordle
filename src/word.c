#include "functions.h"


int check_letter(char word[5], char c, int index)
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



int *check_word(char word[5], char word_try[5])
{
	int i;
	int *word_status = (int *)malloc(5 * sizeof(int));

	for(i = 0; word_try[i]; i++)
	{
		word_status[i] = check_letter(word, word_try[i], i);
	}

	return (word_status);
}
