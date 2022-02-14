#include "functions.h"


char *to_upper(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}

	return (str);
}

int main()
{
	int i;
	char word[6];
	char *main_word;

	filter_5letter_words();
	main_word = to_upper(get_main_word());

	printf("\e[8;43;68t"); // Resize terminal 42*75 characters (alto x ancho)
	print_grid();
	printf("\n");

	for (i = 0; i < 6; i++)
	{
		printf("Introduce la %d palabra: ", i + 1);
		fgets(word, 6, stdin);
		
		if (check_length(word))
		{
			i--;
		}
		else
		{
			print_word(main_word, to_upper(word), i);
			if (correct_word(main_word, word))
			{
				break;
			}
		}

		printf("\033[1A");
		printf("\033[K"); // Clear line from cursor right
	}

	if(!correct_word(main_word, word))
	{
		printf("La palabra correcta era: %s\n\n", to_upper(main_word));
	}

	return 0;
}