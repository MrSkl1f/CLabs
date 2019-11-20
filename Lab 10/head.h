#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORDS 256
#define OK 0
#define ERROR 1

struct birth
{
    int day;
    int month;
    int year;
    int age;
};

struct mark
{
    int *marks;
    int count_of_marks;
    float average;
};

struct child
{
    char *first_name;
    char *sex;
    int sex_key;
    char *birthday;
    struct birth cur_child;
    struct mark cur_mark;
};

#include "structure.h"
#include "addmark.h"
#include "sort.h"
#include "birthday.h"
#include "delete.h"
#include "test.h"

#endif