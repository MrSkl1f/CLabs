#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

struct data
{
    void *number;
    void *degree;
} data;

struct list
{
    struct data info;    
    struct list *next;
};

#define FIRST_TASK "val"
#define SECOND_TASK "ddx"
#define THIRD_TASK "sum"
#define FOURTH_TASK "dvd"

#include "operationsforlist.h"
#include "input.h"
#include "tasks.h"

#endif