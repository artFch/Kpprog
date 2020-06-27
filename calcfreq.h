#ifndef CALCFREQ_H
#define CALCFREQ_H

#include <stdio.h>

typedef struct {
	char*s;
	int count;
	} word;
	
typedef struct{
	word*str;
	int size;
	int capacity;
	} dictionary;

void free_dic(dictionary*dic);
int push_back(dictionary*dic,char*string);
int string_finder(dictionary*dic,char*string);
int fill_dic (dictionary*dic,FILE *in);
#endif
