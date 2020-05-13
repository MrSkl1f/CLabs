#ifndef STRUCTS_H
#define STRUCTS_H

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

#endif