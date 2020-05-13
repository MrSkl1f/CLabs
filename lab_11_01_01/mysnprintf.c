#include "main.h"
#include "mysnprintf.h"

int my_snprintf(char *buffer, int size_of_buffer, char *specificator, ...)
{
    va_list pointer;
    va_start(pointer, specificator);
    int cur_pos_in_specificator = 0, cur_pos_in_buf = 0;

    for (; cur_pos_in_specificator < strlen(specificator) && cur_pos_in_buf < size_of_buffer - 1; cur_pos_in_specificator++)
    {
        if (specificator[cur_pos_in_specificator] == '%' && cur_pos_in_specificator + 1 < strlen(specificator) && specificator[cur_pos_in_specificator + 1] == 'c')
        {
            buffer[cur_pos_in_buf] = va_arg(pointer, int);
            cur_pos_in_specificator++;
            cur_pos_in_buf++;
        }
        else
        {
            buffer[cur_pos_in_buf] = specificator[cur_pos_in_specificator];
            cur_pos_in_buf++;
        }
    }
    va_end(pointer);
    if (cur_pos_in_buf < size_of_buffer)
        buffer[cur_pos_in_buf] = 0;
    return count_in_nee_line(specificator);
}

int count_in_nee_line(char *line)
{
    int count = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] == '%' && i + 1 < strlen(line) && line[i + 1] == 'c')
        {
            count++;
            i++;
        }
        else
            count++;
    }
    return count;
}