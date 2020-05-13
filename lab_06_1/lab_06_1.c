// Функция strchr возвращает первое вхождение в строку
// Т.е. возвращает позицию

#include <stdio.h>
#include <string.h>

char *my_strchr(char *line, int elem);

int main(int argc, char const *argv[])
{
	char my_line[] = "012345";
	int find_elem = '5'; 

	if (my_strchr(my_line, find_elem) == strchr(my_line, find_elem))
	{
		printf("TRUE\n");
	}
	return 0;
}

char *my_strchr(char *line, int elem) 
{
	char *check;
	int count = 0;
	while (*line != elem) 
	{
		if (!*line++) 
		{
			check = NULL;
			count++;
		}
	}
	if (count == 0)
		check = (char *)line;
	return check;
}
