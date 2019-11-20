void input_structure(struct child **children, int *err, int *count);
int check_end_of_line(char *word);
int check_line_of_birthday(char *word);
void see_out_structure(struct child *children, int count);
void delete_structure(struct child **children, int count);
int check_sex(char *sex);
void free_field(struct child *children);
void malloc_field(struct child *children);
void input_marks(struct child *children, int *err);
int convert_birthday_into_int(struct child *children);
int check_converted_birthday(struct birth children);
int check_input_first_name(char *word);
int make_lower_word(char *word);
void output_in_file(struct child *children, int count);
int create_new_low_word(char *word, char *check_word);
int create_new_word_for_sex(char *word);

