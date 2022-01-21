#include "functions.h"

// Imprime la cuadrícula inicial
void print_grid()
{
	int i, j;

	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < 5; i++)
		{
			printf(top_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
			printf(left_mid_line "     " right_mid_line);
		}
		printf("\n");
		for (i = 0; i < 5; i++)
		{
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
			printf("\e[0;102m"); // Fonde verde
			printf("\e[1;30m");
			break;	 // Letra en negro
		}
		case 2:
		{
			printf("\e[0;103m"); // Fondo naranja
			printf("\e[1;30m");
			break;	 // Letra en negro
		}
	}
	return;
}

void print_letter_color(char *str, int *word_status)
{
	int i, j;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; str[i]; i++)
		{
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

// Imprime la palabra en la línea indicada
void print_word(char *str, int n)
{
	int i, j;
	int *word_status = check_word(str);
	printf("\0337"); // Guarda posición del cursor
	printf("\033[1A");
	printf("\033[1A");

	for (i = 0; i < 6 - n - 1; i++)
	{
		printf("\033[5A"); // Mueve el cursor arriba 3 lineas
	}

	printf("\033[2A");

	print_letter_color(str, word_status);

	printf("\0338"); // Reestablece posición del cursor

	free(word_status);
	
	return;
}