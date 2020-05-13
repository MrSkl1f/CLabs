#ifndef SORT_H
#define SORT_H

#define SORTSURNAME "SURNAME"
#define SORTSEX "SEX"
#define SORTBIRTHDATE "BIRTHDATE"
#define SORTGRADE "GRADE" 

void sort_struct_with_key(struct child *children, int count, int *err);
int cmp_grade(struct child *first, struct child *second);
int cmp_sex(struct child *first, struct child *second);
void convert_sex_in_int(struct child *children, int count);
void sort_table_insertion(struct child *children, int count, int (*operations)(struct child *, struct child *));
int cmp_first_name(struct child *first, struct child *second);
int cmp_birthday(struct child *first, struct child *second);

#endif