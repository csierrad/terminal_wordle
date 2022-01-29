#include "functions.h"

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

char *to_upper(char *str)
{
	int i = 0;
	while(str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}

	return (str);
}


int main()
{
	int i;
	char word[5];		//poner 5 o 6!!!!!!!!!!!!!!!!!
	char *main_word;
	
	filter_5letter_words();
	main_word = to_upper(get_main_word());

	printf("\e[8;42;75t");		// Resize terminal 35*75 characters
	print_grid();
	printf("\n");

	for(i = 0; i < 6; i++)
	{
		printf("Introduce la %d palabra: ", i + 1);
		fgets(word, 6, stdin);
		clean_stdin();
		print_word(main_word, to_upper(word), i);
		printf("\033[1A");
		printf("\033[K");	//Clear line from cursor right
	}

	return 0;
}