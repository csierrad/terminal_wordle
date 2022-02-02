#include "functions.h"


int clean_stdin(void)
{
    int c, i = 0;	// Si i vale 0, la palabra introducida es de 5 letras
    do {
        c = getchar();
		if(tolower((char)c) >= 'a' && tolower((char)c) <= 'z')
		{
			i = 1;	//Si i vale 1, la palabra introducida es de más de 5 letras
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
			return (1); 	//return 1 -> palabra más corta de 5 letras
		}
	}
	if(clean_stdin())
	{
		return (2);		//return 2 -> palabra de más de 5 letras
	}
	return (0);		//return 0 -> palabra de 5 letras
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