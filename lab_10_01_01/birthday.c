#include "head.h"

void convert_age(struct child *children, int count)
{
    int cur_year = 2019, cur_month = 11, cur_day = 1; 
    for (int i = 0; i < count; i++)
    {
        children[i].cur_child.age = cur_year - children[i].cur_child.year;
        if (cur_month < children[i].cur_child.month || (cur_month == children[i].cur_child.month && cur_day < children[i].cur_child.day))
            children[i].cur_child.age--;
    }
}
