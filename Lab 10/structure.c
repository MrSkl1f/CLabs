#include "head.h"

void input_structure(struct child **children, int *err, int *count)
{
    int step = 1;
    int check_nobody = 1;
    *children = malloc(step * sizeof(struct child));
    char *check = malloc(256 * sizeof(char));
    while (*err == OK && check_nobody)
    {
        if (scanf("%s", check) == 1)
        {
            if (create_new_low_word(check, "nobody"))
            {
                if (check_input_first_name(check) && check_end_of_line(check))
                {
                    malloc_field(&((*children)[*count]));
                    strcpy((*children)[*count].first_name, check);
                    if (scanf("%s", (*children)[*count].sex) == 1 && create_new_word_for_sex((*children)[*count].sex) && 
                        check_end_of_line((*children)[*count].sex) && scanf("%s", (*children)[*count].birthday) == 1 && 
                        check_line_of_birthday((*children)[*count].birthday) && convert_birthday_into_int((&(*children)[*count])) && 
                        check_converted_birthday((*children)[*count].cur_child) && scanf("%d", &((*children)[*count].cur_mark.count_of_marks)) == 1 && 
                        (*children)[*count].cur_mark.count_of_marks > 0)
                    {
                        input_marks(&((*children)[*count]), err);
                        if (*err == ERROR)
                            free_field((&(*children)[*count]));
                        else
                        {
                            *count += 1;
                            *children = realloc(*children, (*count + step) * sizeof(struct child));
                        }
                    }
                    else
                    {
                        free_field((&(*children)[*count]));
                        *err = ERROR;
                    }
                }
                else
                    *err = ERROR;
            }
            else
                check_nobody = 0;
        }
        else
            *err = ERROR;
    }
    
    free(check);
}

int create_new_word_for_sex(char *word)
{
    char *new_word = malloc(strlen(word) * sizeof(char) + sizeof(char));
    for (int i = 0; i < strlen(word) + 1; i++)
        new_word[i] = tolower(word[i]);
    int check = 0;
    if ((strcmp(new_word, "male") == 0))
        check = 1;
    else if (strcmp(new_word, "female") == 0)
        check = 1;
    free(new_word);
    return check;
}

int create_new_low_word(char *word, char *check_word)
{
    char *new_word = malloc(strlen(word) * sizeof(char) + sizeof(char));
    for (int i = 0; i < strlen(word) + 1; i++)
        new_word[i] = tolower(word[i]);
    int check = 1;
    if (strcmp(new_word, check_word) == 0)
        check = 0;
    free(new_word);
    return check;
}

int make_lower_word(char *word)
{
    for (int i = 0; i < strlen(word); i++)
        word[i] = tolower(word[i]);
    return 1;
}

int check_input_first_name(char *word)
{
    int check = 1;
    for (int i = 0; word[i] != '\0'; i++)
        if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
            check = 0;
    return check;
}

int check_converted_birthday(struct birth children)
{
    int check = 0;
    if (children.year < 1980)
        check = 0;
    else if (children.day > 0 && children.month > 0 && children.month <= 12 && children.year > 0)
    {
        if ((children.year % 4 == 0 && children.year % 100 != 0 && children.month == 2 && children.day <= 29) ||
            (children.year % 400 == 0 && children.month == 2 && children.day <= 29))
            check = 1;
        else if (children.month == 2 && children.day <= 28)
            check = 1;
        else
        {
            if ((children.month != 2 && children.month < 8 && children.month % 2 == 1 && children.day <= 31) ||
                (children.month != 2 && children.month < 8 && children.month % 2 == 0 && children.day <= 30))
                check = 1;
            else if ((children.month != 2 && children.month >= 8 && children.month % 2 == 1 && children.day <= 30) ||
                (children.month != 2 && children.month >= 8 && children.month % 2 == 0 && children.day <= 31))
                check = 1;
        }
    }
    return check;
}

int convert_birthday_into_int(struct child *children)
{
    children->cur_child.year = 0; children->cur_child.month = 0; children->cur_child.day = 0;
    for (int i = 0; i < 4; i++)
    {
        children->cur_child.year += (children->birthday[i] - '0');
        if (i != 3)
            children->cur_child.year *= 10;
    }
    for (int i = 5; i < 7; i++)
    {
        children->cur_child.month += (children->birthday[i] - '0');
        if (i != 6)
            children->cur_child.month *= 10; 
    }
    for (int i = 8; i < 10; i++)
    {
        children->cur_child.day += (children->birthday[i] - '0');
        if (i != 9)
            children->cur_child.day *= 10;
    }
    return 1;
}

void input_marks(struct child *children, int *err)
{
    children->cur_mark.marks = realloc(children->cur_mark.marks, children->cur_mark.count_of_marks * sizeof(int));   
    for (int j = 0; j < children->cur_mark.count_of_marks && !*err; j++)
    {
        if (scanf("%d", &(children->cur_mark.marks[j])) != 1)
            *err = ERROR;
        else if (children->cur_mark.marks[j] <= 0)
            *err = ERROR;
    }
}

void free_field(struct child *children)
{
    free(children->first_name);
    free(children->birthday);
    free(children->sex);
    if (children->cur_mark.marks != NULL)
        free(children->cur_mark.marks);
}

int check_sex(char *sex)
{
    int res = 0;
    if (!strcmp(sex, "male") || !strcmp(sex, "female"))
        res = 1;
    return res;
}

int check_end_of_line(char *word)
{
    int check = 0;
    if (strlen(word) < 256 && word[strlen(word)] == '\0')
        check = 1;
    return check;
}

int check_line_of_birthday(char *word)
{
    int check = 1;
    
    if (strlen(word) == 10)
    {
        if (word[4] == '.' && word[7] == '.' && word[10] == '\0')
            for (int i = 0; i < 10; i++)
            {
                if (i != 4 && i != 7 && (word[i] - '0' >= 0 && word[i] - '0' < 10))
                    check = 1;
                else if (i != 4 && i != 7)
                {
                    check = 0;
                    break;
                }
            }
        else
            check = 0;
    }
    else
        check = 0;
    return check;
}

void see_out_structure(struct child *children, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Surname > %s\n", children[i].first_name);
        printf("Sex > %s\n", children[i].sex);
        printf("Birthday > %s\n", children[i].birthday);
        for (int j = 0; j < children[i].cur_mark.count_of_marks; j++)
            printf("%d ", children[i].cur_mark.marks[j]);
        printf("\n");
    }
}

void delete_structure(struct child **children, int count)
{
    for (int i = 0; i < count; i++)
    {
        free((*children)[i].first_name);
        free((*children)[i].sex);
        free((*children)[i].birthday);
        free((*children)[i].cur_mark.marks);
    }
    free(*children);
    //children = NULL;
}

void malloc_field(struct child *children)
{
    children->first_name = malloc(256 * sizeof(char));
    children->sex = malloc(256 * sizeof(char));
    children->birthday = malloc(256 * sizeof(char));
    children->cur_mark.marks = NULL;
}

void output_in_file(struct child *children, int count)
{
    FILE *file = fopen("kids.txt", "w");
    if (file)
    {
        printf("Yes\n");
        for (int i = 0; i < count; i++)
        {
            fprintf(file, "%s\n", children[i].first_name);
            fprintf(file, "%s\n", children[i].sex);
            fprintf(file, "%s\n", children[i].birthday);
            fprintf(file, "%d ", children[i].cur_mark.count_of_marks);
            for (int j = 0; j < children[i].cur_mark.count_of_marks; j++)
                fprintf(file, "%d ", children[i].cur_mark.marks[j]);
            fprintf(file, "\n");
        }
    }
    fclose(file);
}