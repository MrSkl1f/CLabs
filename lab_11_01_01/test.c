#include "main.h"
#include "test.h"
#include "mysnprintf.h"

int main()
{
    first_check();
    second_check();
    third_check();
    fourth_check();
    fifth_check();

    return 0;
}

void first_check()
{
    char first_buf[10], second_buf[10];
    if (snprintf(first_buf, 5, "%c %c", 'a', 'b') == my_snprintf(second_buf, 5, "%c %c", 'a', 'b') &&
        strcmp(first_buf, second_buf) == 0)
        printf("TRUE first\n");
}

void second_check()
{
    char *first_buf = NULL, *second_buf = NULL; 
    if (snprintf(first_buf, 0, "%c %c", 'a', 'b') == my_snprintf(second_buf, 0, "%c %c", 'a', 'b'))
        printf("TRUE second\n");
}

void third_check()
{
    char first_buf[10], second_buf[10];
    int new_size = 2;
    if (snprintf(first_buf, new_size, "%c %c word", 'a', 'b') == my_snprintf(second_buf, new_size, "%c %c word", 'a', 'b') &&
        strcmp(first_buf, second_buf) == 0)
        printf("TRUE third\n");
}

void fourth_check()
{
    char first_buf[10], second_buf[10];
    if (snprintf(first_buf, 7, "%c %c %c", 'a', 'b', 'c') == my_snprintf(second_buf, 7, "%c %c %c", 'a', 'b', 'c') &&
        strcmp(first_buf, second_buf) == 0)
        printf("TRUE fourth\n");
}

void fifth_check()
{
    char first_buf[10], second_buf[10];
    if (snprintf(first_buf, 10, "%c %c %c asf", '\t', '\n', '\0') == my_snprintf(second_buf, 10, "%c %c %c asf", '\t', '\n', '\0') &&
        strcmp(first_buf, second_buf) == 0)
        printf("TRUE fifth\n");
}