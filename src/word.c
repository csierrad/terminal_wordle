#include "functions.h"


int check_letter(char c, char *main_word, int *letter_checked)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (c == main_word[i])
		{
			if (!letter_checked[i])
			{
				letter_checked[i] = 1;
				return (2);		// La letra esta pero no en esa posición
			}
		}
	}
	return (0);		// La letra no está
}


int *check_word(char *main_word, char *word)
{
	int i;
	int *word_status = (int *)malloc(sizeof(int) * 5);
	int *letter_checked = (int *)malloc(sizeof(int) * 5);

	for(i = 0; i < 5; i++)
	{
		letter_checked[i] = 0;
	}

	for (i = 0; i < 5; i++)
	{
		if (word[i] == main_word[i])
		{
			word_status[i] = 1;		//La letra está en esa posición
			letter_checked[i] = 1;
		}
	}

	for (i = 0; i < 5; i++)
	{
		if (word_status[i] != 1)
		{
			word_status[i] = check_letter(word[i], main_word, letter_checked);
		}
	}
	return (word_status);
}