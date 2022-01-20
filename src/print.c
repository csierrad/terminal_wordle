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
		/* for (i = 0; i < 5; i++)
		{
			printf(mid_line);
		}
		printf("\n"); */
		for (i = 0; i < 5; i++)
		{
			printf(left_letter_line " " right_letter_line);
		}
		printf("\n");
		/* for (i = 0; i < 5; i++)
		{
			printf(mid_line);
		}
		printf("\n"); */
		for (i = 0; i < 5; i++)
		{
			printf(bot_line);
		}
		printf("\n");
	}

	return;
}

void print_letter_color(char c, int i)
{
	switch(i)
	{
		case 1:
		{
			printf("\e[0;102m"); 	//Fonde verde
			printf("\e[1;30m");		//Letra en negro
			printf("%c" , c);		
			printf("\e[0m");		//Reset
			break;
		}
		case 2:
		{
			printf("\e[0;103m");	//Fondo naranja
			printf("\e[1;30m");		//Letra en negro
			printf("%c" , c);		
			printf("\e[0m");		//Reset
			break;
		}
		default:
		{
			printf("%c" , c);
		}
	}
	return;
}

// Imprime la palabra en la línea indicada
void print_word(char *str, int n)
{
	int i;
	int *word_status = check_word(str);
	printf("\0337"); // Guarda posición del cursor
	printf("\033[1A");
	printf("\033[1A");

	for (i = 0; i < 6 - n - 1; i++)
	{
		printf("\033[3A"); // Mueve el cursor arriba 3 lineas
	}

	printf("\033[2A");

	for (i = 0; str[i]; i++)
	{	
		printf(left_letter_line);
		print_letter_color(str[i], word_status[i]);
		printf(right_letter_line);
	}

	printf("\0338"); // Reestablece posición del cursor

	return;
}

/* int main()
{

	print_grid();

	print_word("POLEA", 1);

	return 0;
} */