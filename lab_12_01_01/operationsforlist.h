#ifndef OPERATIONSFORLIST_H
#define OPERATIONSFORLIST_H

void push_list(struct list **head, int value_first, int value_second);
void pop_list(struct list **head);
void print_list(struct list *head, int size_list);
void free_list(struct list **head);
void print_need_knot(struct list *head, int need_knot);
int find_size_of_list(struct list *head);
void add_new_elem(struct list **head, int number, int degree);

#endif