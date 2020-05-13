#ifndef INPUT_H
#define INPUT_H

void data_input(struct list **cur_list, int *err, int *size_list);
int check_previous(struct list *cur_list, int deg);
void input_key_for_task(struct list **cur_list, int *err);

#endif