#include "functions.h"

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


int main()
{
	int i;
	char word[5];		//poner 5 o 6!!!!!!!!!!!!!!!!!
	char main_word = get_main_word();

	printf("\e[8;35;75t");		// Resize terminal 35*75 characters
	print_grid();
	printf("\n");

	for(i = 0; i < 6; i++)
	{
		printf("Introduce la %d palabra: ", i + 1);
		fgets(word, 6, stdin);
		clean_stdin();
		print_word(main_word, word, i);
		printf("\033[1A");
		printf("\033[K");
	}

	return 0;
}