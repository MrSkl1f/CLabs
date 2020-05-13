#include "main.h"

void implementation_first(struct list **cur_list, int *err)
{
    int size_list = 0;
    data_input(cur_list, err, &size_list);
    int need_number = 0; size_list = 0;
    if (!*err && scanf("%d", &need_number) == 1)
    {
        int result = find_result_for_first_task(*cur_list, need_number);
        printf("%d\n", result); 
    }
    else
        *err = 1;
}

int find_result_for_first_task(struct list *head, int number)
{
    int result = 0;
    while (head != NULL)
    {
        result += *(int *)(head->info.number) * (pow(number, *(int *)(head->info.degree)));
        head = head->next;
    }
    return result;
}

void implementation_second(struct list **head, int *err)
{
    int size_list = 0;
    data_input(head, err, &size_list);
    if (!*err)
    {
        struct list *result_list = NULL;
        fill_result_list(*head, &result_list, size_list);
        int new_size = find_size_of_list(result_list);
        if (new_size > 0)
            print_list(result_list, new_size);
        else
            *err = 1;
        free_list(&result_list);
    }
}

void fill_result_list(struct list *head, struct list **result_list, int size_list)
{
    int number = 0, degree = 0;
    for (int i = size_list - 1; i >= 0; i--)
    {
        number = 0, degree = 0;
        take_info_from_knot(head, i, &number, &degree);
        input_need_values(result_list, number, degree);
    }
}

void take_info_from_knot(struct list *head, int need_knot, int *number, int *degree)
{
    for (int i = 0; i < need_knot; i++)
        head = head->next;
    *number = *(int *)(head->info.number);
    *degree = *(int *)(head->info.degree);
}

void input_need_values(struct list **head, int number, int degree)
{
    if (degree - 1 >= 0)
        push_list(head, number * degree, degree - 1);
}

void implementation_third(struct list **first_list, int *err)
{
    int size_first_list = 0;
    data_input(first_list, err, &size_first_list);
    if (!*err)
    {
        int size_second_list = 0;
        struct list *second_list = NULL;
        data_input(&second_list, err, &size_second_list);
        if (!*err)
        {
            struct list *result_list = NULL;
            count_and_fill_result_list(&result_list, *first_list, second_list, size_first_list, size_second_list);
            int size_result_list = find_size_of_list(result_list);
            //printf("%d\n", size_result_list);
            print_list(result_list, size_result_list);
            free_list(&result_list);
        }
        free_list(&second_list);
    }
}

void implementation_fourth(struct list **head, int *err)
{
    int size = 0;
    data_input(head, err, &size);
    if (!*err)
    {
        struct list *first = NULL, *second = NULL;
        int size_first = 0, size_second = 0;
        fill_new_lists(*head, size, &first, &second, &size_first, &size_second);
        print_list(first, size_first);
        print_list(second, size_second);
        free_list(&first); free_list(&second);
    }
}

void fill_new_lists(struct list *head, int size, struct list **first, struct list **second, int *size_first, int *size_second)
{
    int number = 0, degree = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        take_info_from_knot(head, i, &number, &degree);
        if (degree % 2 == 0)
        {    
            push_list(first, number, degree);
            *size_first += 1;
        }
        else
        {
            push_list(second, number, degree);
            *size_second += 1; 
        }
    }
}

void count_and_fill_result_list(struct list **head, struct list *first, struct list *second, int size_first, int size_second)
{
    int already_processed_first = 1;
    int already_processed_second = 1;
    int cur_number_first = 0, cur_degree_first = 0;
    int cur_number_second = 0, cur_degree_second = 0;
    for (int i = size_second; i > 0;)
    {
        if (already_processed_first)
        {
            size_first--;
            take_info_from_knot(first, size_first, &cur_number_first, &cur_degree_first);
            already_processed_first = 0;
        }
        if (already_processed_second)
        {
            i--;
            take_info_from_knot(second, i, &cur_number_second, &cur_degree_second);
            already_processed_second = 0;
        }

        if (cur_degree_second > cur_degree_first)
        {
            push_list(head, cur_number_second, cur_degree_second);
            already_processed_second = 1;
        }
        else if (cur_degree_second == cur_degree_first)
        {
            push_list(head, cur_number_first + cur_number_second, cur_degree_first);
            already_processed_first = 1;
            already_processed_second = 1;
        }
        else
        {
            push_list(head, cur_number_first, cur_degree_first);
            already_processed_first = 1;
        }
    }
    if (!already_processed_first)
        push_list(head, cur_number_first, cur_degree_first);
}

