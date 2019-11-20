#include "head.h"

void add_mark(struct child *children, int count)
{
    for (int i = 0; i < count; i++)
    {
        children[i].cur_mark.marks = realloc(children[i].cur_mark.marks, children[i].cur_mark.count_of_marks * sizeof(int) + sizeof(int));
        children[i].cur_mark.count_of_marks += 1;
        children[i].cur_mark.marks[children[i].cur_mark.count_of_marks - 1] = 3;
    }
}

void find_average(struct child *children, int count)
{
    float sum_cur = 0;
    for (int i = 0; i < count; i++)
    {
        sum_cur = 0;
        for (int j = 0; j < children[i].cur_mark.count_of_marks; j++)
            sum_cur += children[i].cur_mark.marks[j];
        children[i].cur_mark.average = sum_cur / children[i].cur_mark.count_of_marks;
    }
}