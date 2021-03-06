#include "header.h"


//Used to save only 5 letter words
void filter_5letter_words()
{
	int eof = 1, i, flag;
	char str[5];
	char c;
	int fd = open("./dictionaries/spanish_common_words.txt", O_RDONLY);
	int fd1 = open("./build/filtered_dictionary.txt", O_WRONLY);
	
	while(eof)
	{
		eof = read(fd, &c, 1);	
		i = 0;
		flag = 0;
		while(c != 10 && eof)
		{
			if(c < 'a' || c > 'z')
			{
				flag++;
			}
			if(i < 5 && flag == 0)
			{
				str[i] = c;
			}
			i++;
			eof = read(fd, &c, 1);
		}
		if(i == 5)
		{
			write(fd1, str, 5);
			write(fd1, "\n", 1);
		}
	}

	close(fd1);
	close(fd);

	return;
}

// Get the rows of filtered_dictionary
int get_rows()
{
	int rows = 0, eof = 1;
	char c;
	char *str;
	int fd = open("./build/filtered_dictionary.txt", O_RDONLY);

	while(eof)
	{
		eof = read(fd, &c, 1);
		if(c == 10)
		{
			rows++;
		}
	}

	close(fd);

	return(rows);
}

//Choose randomly the word that will be the main_word
char *get_main_word()
{
	int i = 0, nrand, rows;
	char *str = (char *)malloc(sizeof(char) + 6);
	char c;
	int fd = open("./build/filtered_dictionary.txt", O_RDONLY);
	
	srand(time(NULL));

	rows = get_rows();
	nrand = rand() % rows;

	while(i < nrand - 1)
	{
		read(fd, &c, 1);
		if(c == 10)
		{
			i++;
		}
	}
	
	i = 0;
	
	read(fd, str, 5);
	str[6] = 0;
	
	close(fd);

	return (str);
}