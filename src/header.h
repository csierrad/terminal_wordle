#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define trc "\U00002513" //┓
#define tlc "\U0000250F" //┏
#define brc "\U0000251B" //┛
#define blc "\U00002517" //┗
#define hl "\U00002501"	 //━
#define vl "\U00002503"	 //┃

#define top_line tlc hl hl hl hl hl hl hl trc //┏━━━┓
#define left_mid_line vl " "				  //┃
#define right_mid_line " " vl				  // ┃
#define bot_line blc hl hl hl hl hl hl hl brc //┗━━━┛

#define wordle_header "\n 888       888   d88888b   8888888b   8888888b   888      8888888888 \n 888   o   888 d88P   Y88b 888   Y88b 888   Y88b 888      888        \n 888  d8b  888 888     888 888    888 888    888 888      888        \n 888 d888b 888 888     888 888   d88P 888    888 888      8888888    \n 888d88888b888 888     888 8888888P   888    888 888      888        \n 88888P Y88888 888     888 888 T88b   888    888 888      888        \n 8888P   Y8888 Y88b   d88P 888  T88b  888   d88P 888      888        \n 888P     Y888   Y88888P   888   T88b 8888888P   88888888 8888888888 \n\n"


// main.c
char *to_upper(char *str);

// print.c
void print_grid();
void set_color(int status);
void print_letter_with_color(char *str, int *word_status);
void print_word(char *main_word, char *word, int n);

// word.c
int check_letter(char c, char *main_word, int *letter_checked);
int *check_word(char *main_word, char *word);

//dictionary_filter.c
void filter_5letter_words();
int get_rows();
char *get_main_word();

//checks.c
int correct_word(char * main_word, char *word);
int check_length(char *str);
int clean_stdin(void);
int check_characters(char *word);


#endif