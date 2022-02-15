#include "functions.h"


int clean_stdin(void)
{
    int c, i = 0;	// i = 0 -> the word introduced has 5 letters
    do {
        c = getchar();
		if(tolower((char)c) >= 'a' && tolower((char)c) <= 'z')
		{
			i = 1;	//i = 1 -> the word introduced has more than 5 letters
		}
    } while (c != '\n' && c != EOF);

	return (i);
}


int check_length(char *str)
{
	int i;

	for(i = 0; str[i];  i++)
	{
		if(str[i] == 10)
		{
			return (1); 	//return 1 -> the word has less than 5 letters
		}
	}
	if(clean_stdin())
	{
		return (2);		//return 2 -> the word has more than 5 letters
	}
	return (0);		//return 0 -> word of 5 letters
}


int correct_word(char *main_word, char *word)
{
	int i = 0;
	int *word_status = check_word(main_word, word);


	for(i = 0; i < 5; i++)
	{
		if(word_status[i] != 1)
		{
			return (0);
		}
	}

	return (1);
}