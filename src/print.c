#include "functions.h"

// Print the initial grid
void print_grid()
{
	int i, j;

	printf("\n 888       888   d88888b   8888888b   8888888b   888      8888888888 \n 888   o   888 d88P   Y88b 888   Y88b 888   Y88b 888      888        \n 888  d8b  888 888     888 888    888 888    888 888      888        \n 888 d888b 888 888     888 888   d88P 888    888 888      8888888    \n 888d88888b888 888     888 8888888P   888    888 888      888        \n 88888P Y88888 888     888 888 T88b   888    888 888      888        \n 8888P   Y8888 Y88b   d88P 888  T88b  888   d88P 888      888        \n 888P     Y888   Y88888P   888   T88b 8888888P   88888888 8888888888 \n\n");


	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < 5; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			printf(top_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			printf(bot_line);
		}
		printf("\n");
	}

	return;
}


void set_color(int status)
{
	switch(status)
	{
		case 1:
		{
			printf("\e[0;102m"); // Green background
			printf("\e[1;30m");
			break;	 // Black font
		}
		case 2:
		{
			printf("\e[0;103m"); // Orange background
			printf("\e[1;30m");
			break;	 // Black font
		}
	}
	return;
}

void print_letter_with_color(char *str, int *word_status)
{
	int i, j;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; str[i]; i++)
		{
			if(i == 0)
			{
				printf("\t   ");
			}
			if(j == 1)
			{
				printf(left_mid_line);
				set_color(word_status[i]);
				printf("  ");
				printf("%c", str[i]);
				printf("  ");
				printf("\e[0m"); // Reset
				printf(right_mid_line);
			}
			else
			{
				printf(left_mid_line);
				set_color(word_status[i]);
				printf("     ");
				printf("\e[0m"); // Reset
				printf(right_mid_line);
			}
		}
		printf("\033[1A");
		printf("\033[99D");
	}

	return;
}

// Print word at the n-th line
void print_word(char *main_word, char *word, int n)
{
	int i, j;
	int *word_status = check_word(main_word, word);


	printf("\0337"); // Save cursor position
	printf("\033[1A");
	printf("\033[1A");

	for (i = 0; i < 6 - n - 1; i++)
	{
		printf("\033[5A"); //Move the sursor 3 lines upwards
	}

	printf("\033[2A");

	print_letter_with_color(word, word_status);

	printf("\0338"); // Resets cursor position

	free(word_status);
	
	return;
}