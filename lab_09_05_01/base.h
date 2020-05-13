#ifndef BASE_H
#define BASE_H

struct matrix_t
{
    int **matr;
    int row;
    int col;
} matrix_t;

#include <stdio.h>
#include <malloc.h>
#include "matr.h"
#include "delete.h"
#include "insert.h"
#include "multiplication.h"

#define OK 0
#define ERROR 1
#define SECOND 2
#define FIRST -2

#endif