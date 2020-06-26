#ifndef CALCFREQ_H
#define CALCFREQ_H

#include <stdio.h>

typedef struct {
    char* s;
} word;

typedef struct {
    word* str;
    int* nums;
    int size;
    int size_n;
    int capacity;
} dictionary;

#endif