#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>


#define trc "\U00002513" //┓
#define tlc "\U0000250F" //┏
#define brc "\U0000251B" //┛
#define blc "\U00002517" //┗
#define hl "\U00002501"	 //━
#define vl "\U00002503"	 //┃


#define top_line tlc hl hl hl hl hl hl hl trc //┏━━━┓
#define left_mid_line vl " "	  //┃
#define right_mid_line " " vl	  // ┃
#define bot_line blc hl hl hl hl hl hl hl brc //┗━━━┛

// main.c
void clean_stdin(void);

// print.c
void print_grid();
void set_color(int status);
void print_letter_color(char *str, int *word_status);
void print_word(char *str, int n);

// word.c
int check_letter(char c, int index);
int *check_word(char *sol);

#endif