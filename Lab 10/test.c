#include "head.h"

int main()
{
    // Check sort
    check_cmp_grade();    
    check_cmp_sex();
    check_cmp_first_name();
    check_cmp_birthday();
    check_sort_table_insertion();
    // Check add marks
    check_add_mark();
    check_find_average();
    // Check convert age and conver birthday into int
    check_convert_age();

    return 0;
}

void check_cmp_grade()
{
    struct child first_child, second_child;
    first_child.cur_mark.average = 5;
    second_child.cur_mark.average = 4;
    if (cmp_grade(first_child, second_child) == 1)
        printf("Correct work of cmp grade\n");
}

void check_cmp_sex()
{
    struct child first_child, second_child;
    first_child.sex = malloc(20 * sizeof(char)); strcpy(first_child.sex, "male");
    second_child.sex = malloc(20 * sizeof(char)); strcpy(second_child.sex, "female");
    if (cmp_sex(first_child, second_child) == 1)
        printf("Correct work of cmp sex\n");
    free(first_child.sex); free(second_child.sex);
}

void check_cmp_first_name()
{
    struct child first_child, second_child;
    first_child.first_name = malloc(20 * sizeof(char)); strcpy(first_child.first_name, "ab");
    second_child.first_name = malloc(20 * sizeof(char)); strcpy(second_child.first_name, "aa");
    if (cmp_first_name(first_child, second_child) == 1)
        printf("Correct work of cmp firstname\n");
    free(first_child.first_name); free(second_child.first_name);
}

void check_cmp_birthday()
{
    struct child first_child, second_child;
    first_child.birthday = malloc(20 * sizeof(char)); strcpy(first_child.birthday, "2000.01.01");
    second_child.birthday = malloc(20 * sizeof(char)); strcpy(second_child.birthday, "2000.01.05");
    if (cmp_birthday(first_child, second_child) == 0)
        printf("Correct work of cmp birthday\n");
    free(first_child.birthday); free(second_child.birthday);
}

void check_sort_table_insertion()
{
    struct child *children = malloc(3 * sizeof(struct child));
    children[0].cur_mark.average = 5;
    children[1].cur_mark.average = 4;
    children[2].cur_mark.average = 3;
    sort_table_insertion(children, 3, cmp_grade);
    printf("Correct work of sort table insertion\n");
    free(children);
}

void check_add_mark()
{
    struct child *children = malloc(2 * sizeof(struct child));
    children[0].cur_mark.count_of_marks = 2;
    children[0].cur_mark.marks = malloc(sizeof(int)); children[0].cur_mark.marks[0] = 3;
    children[1].cur_mark.count_of_marks = 2;
    children[1].cur_mark.marks = malloc(sizeof(int)); children[1].cur_mark.marks[0] = 3;
    add_mark(children, 2);
    printf("Correct work of addition marks\n");
    for (int i = 0; i < 2; i++)
        free(children[i].cur_mark.marks);
    free(children);
}

void check_find_average()
{
    struct child *children = malloc(sizeof(struct child));
    children[0].cur_mark.marks = malloc(2 * sizeof(int));
    children[0].cur_mark.count_of_marks = 2;
    children[0].cur_mark.marks[0] = 2;
    children[0].cur_mark.marks[1] = 2;
    find_average(children, 1);
    if (children[0].cur_mark.average == 2)
        printf("Correct work of find average\n");
    
    free(children[0].cur_mark.marks);
    free(children);
}

void check_convert_age()
{
    struct child *children = malloc(sizeof(struct child));
    children[0].birthday = malloc(20 * sizeof(char));
    strcpy(children[0].birthday, "2000.01.01");
    convert_birthday_into_int(&(children[0]));
    convert_age(children, 1);
    if (children[0].cur_child.age == 19)
        printf("Correct work of convert age and conver birthday into int\n");
    free(children[0].birthday);
    free(children);
}
