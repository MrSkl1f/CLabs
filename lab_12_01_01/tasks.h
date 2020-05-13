#ifndef TASKS_H
#define TASKS_H

void implementation_first(struct list **cur_list, int *err);
int find_result_for_first_task(struct list *head, int number);
void implementation_second(struct list **head, int *err);
void fill_result_list(struct list *head, struct list **result_list, int size_list);
void take_info_from_knot(struct list *head, int need_knot, int *number, int *degree);
void input_need_values(struct list **head, int number, int degree);
void fill_new_lists(struct list *head, int size, struct list **first, struct list **second, int *size_first, int *size_second);
void implementation_fourth(struct list **head, int *err);
void implementation_third(struct list **first_list, int *err);
void count_and_fill_result_list(struct list **head, struct list *first, struct list *second, int size_first, int size_second);

#endif