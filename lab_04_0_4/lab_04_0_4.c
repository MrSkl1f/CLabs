// Метод сортировки пузырьком

#include <stdio.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TRUEOUT 0
#define FALSEOUT 1
#define MINLEN 0
#define MAXLEN 10

// Ввод массивам
int *input_array(int *array, int dimension, int *check_out);
// Сортировка массива
int *bubble(int *array, int dimension);
// Вывод массива
void seeout(int *array, int dimension);
// Сдвиг
void swap(int *first, int *second);

int main()
{
	int out = FALSEOUT;
	int *check_out = &out;
	float dimension_check;
	int dimension, check = TRUEOUT;

	printf("Input the dimension > ");
	check += scanf("%f", &dimension_check);
	dimension = (int)dimension_check;

	if (check == TRUE && ((dimension_check / dimension) == TRUE) && dimension > MINLEN && dimension <= MAXLEN)
	{
		int array[dimension];
		input_array(array, dimension, check_out);
		if (out != FALSEOUT)
		{
			bubble(array, dimension);
			seeout(array, dimension);
			out = TRUEOUT;
		}
	}	
	return out;
}

int *input_array(int *array, int dimension, int *check_out)
{
	int check = TRUEOUT;
	for (int i = 0; i < dimension; i++)
		check += scanf("%d", (array + i));

	if (check == dimension)
		*check_out = TRUEOUT;

	return array;
}

int *bubble(int *array, int dimension)
{
	int count = 1;
	while (count < dimension)
	{
		for (int i = 0; i < (dimension - count); i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
			}
		}
		count++;
	}
	return array;
}

void seeout(int *array, int dimension)
{
	for (int i = 0; i < dimension; i++)
		printf("%d ", array[i]);
}

void swap(int *first, int *second)
{
	int help = *first;
	*first = *second;
	*second = help;
}