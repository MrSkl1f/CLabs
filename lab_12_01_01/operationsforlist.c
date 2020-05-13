#include "main.h"

void push_list(struct list **head, int value_first, int value_second)
{
    struct list *tmp = malloc(sizeof(struct list));
    tmp->next = *head;
    int *val_frst = malloc(sizeof(int));
    int *val_sec = malloc(sizeof(int));
    *val_frst = value_first;
    *val_sec = value_second;
    tmp->info.number = val_frst;
    tmp->info.degree = val_sec;
    *head = tmp;
}

void print_list(struct list *head, int size_list)
{
    for (int i = size_list - 1; i >= 0; i--)
        print_need_knot(head, i);
    printf("L\n");
}

void free_list(struct list **head)
{
    struct list *out;
    while (*head != NULL)
    {
        if ((*head)->info.number != NULL)
            free((*head)->info.number);
        if ((*head)->info.degree != NULL)
            free((*head)->info.degree);
        out = *head;
        *head = (*head)->next;
        free(out);
    }
}

void print_need_knot(struct list *head, int need_knot)
{
    for (int i = 0; i < need_knot; i++)
        head = head->next;
    printf("%d %d ", *(int *)((head->info.number)), *(int *)((head->info.degree)));
}

int find_size_of_list(struct list *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void add_new_elem(struct list **head, int number, int degree)
{
    struct list *temp, *after_need;
    temp = (struct list*)malloc(sizeof(struct list));
    after_need = (*head)->next;
    (*head)->next = temp;
    temp->info.number = malloc(sizeof(int));
    temp->info.degree = malloc(sizeof(int));
    temp->info.number = &number;
    temp->info.degree = &degree;
    temp->next = after_need;
}

void deletelem(struct list **lst, struct list **root)
{
    struct list *temp;
    temp = *root;
    while (temp->next != *lst) 
        temp = temp->next;
    temp->next = (*lst)->next; 
    free(lst); 
}