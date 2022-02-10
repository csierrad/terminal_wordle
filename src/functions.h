#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

// main.c
char *to_upper(char *str);

// print.c
void print_grid();
void set_color(int status);
void print_letter_with_color(char *str, int *word_status);
void print_word(char *main_word, char *word, int n);

// word.c
int check_letter(char word[5], int *letter_checked, char c, int index);
int *check_word(char *word, char *word_try);

//dictionary_filter.c
void filter_5letter_words();
int get_rows();
char *get_main_word();

//checks.c
int correct_word(char * main_word, char *word);
int check_length(char *str);
int clean_stdin(void);


#endif