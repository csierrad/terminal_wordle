#include "functions.h"


int check_letter(char main_word[5], int *letter_checked, char c, int index)
{	
	int i;

	for(i = 0; main_word[i]; i++)
	{
		if(main_word[i] == c)
		{
			if(!letter_checked[i])
			{
				letter_checked[i] = 1;

				return (2);		//c está en word pero no en la misma posición
			}
		}
	}
	return (0);		// La letra no está en la palabra
}



int *check_word(char main_word[5], char word[5])
{
	int i;
	int *word_status = (int *)malloc(5 * sizeof(int));
	int *letter_checked = (int *)malloc(5 * sizeof(int));

	for(i = 0; i < 5; i++)
	{
		letter_checked[i] = 0;
	}

	for(i = 0; i < 5; i++)
	{
		if(word[i] == main_word[i])
		{
			letter_checked[i] = 1;
			word_status[i] = 1; 	 // c está en word y en la misma posición
		}
	}

	for(i = 0; word[i]; i++)
	{
		if(!letter_checked[i])
		{
			word_status[i] = check_letter(main_word, letter_checked, word[i], i);
		}
	}

	return (word_status);
}
