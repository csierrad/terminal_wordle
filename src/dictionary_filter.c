#include "functions.h"

//Word list -> https://github.com/bitcoin/bips/blob/master/bip-0039/spanish.txt

void filter_5letter_words()
{
	int eof = 1, i, flag;
	char str[5];
	char c;
	int fd = open("./spanish_dictionary.txt", O_RDONLY);
	int fd1 = open("./build/filtered_dictionary.txt", O_APPEND | O_WRONLY, 00700);

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
			printf("str: %s\n", str);
			write(fd1, str, 5);
			write(fd1, "\n", 1);
		}
	}

	close(fd1);
	close(fd);

	return;
}

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

char *get_main_word()
{
	int i = 0;
	char *str = (char *)malloc(sizeof(char) + 5);
	char c;
	int fd = open("./build/filtered_dictionary.txt", O_RDONLY);
	int rows = get_rows();
	
	srand(time(NULL));

	int nrand = rand() % rows;
	printf("rand: %d\n", nrand);

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
	
	close(fd);

	return (str);
}

/* 
menor c=10 	i<=4
igual c=10	i=5
mayor c!=10 	i>5 */