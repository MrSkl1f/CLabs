// Сформируйте новый массив из элементов исходного массива. При этом в новый массив
// помещаются (копируются) элементы исходного массива, которые больше среднего арифметического его
// элементов.

#include <stdio.h>

#define TRUEOUT 0
#define FALSEOUT 1
#define TRUE 1
#define FALSE 0
#define MINLEN 0
#define MAXLEN 10

// Ввод массива
int *input_array(int *array, int dimension, int *check_out);
// Подсчет среднего арифметического
float arithmetic_mean(int *array, int dimension);
// Подсчет количества чисел, больших среднего арифметического
int count_of_medium(int *array, int dimension, float medium);
// Создание нового массива
int *creation_of_array(int *array, int *new_array, int dimension, float medium);
// Вывод массива
void seeout(int *array, int dimension);

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
			float medium = arithmetic_mean(array, dimension);
			int count_medium = count_of_medium(array, dimension, medium);
			if (count_medium == 0)
				out = FALSEOUT;
			else
			{
				int new_array[count_medium];
				creation_of_array(array, new_array, dimension, medium);
				seeout(new_array, count_medium);
				out = TRUEOUT;
			}
		}
	}
	return out;
}

int *input_array(int *array, int dimension, int *check_out)
{
	int check = 0;
	for (int i = 0; i < dimension; i++)
		check += scanf("%d", (array + i));

	if (check == dimension)
		*check_out = TRUEOUT;

	return array;
}

float arithmetic_mean(int *array, int dimension)
{
	float summ = 0;
	for (int i = 0; i < dimension; i++)
		summ += array[i];
	return (summ / dimension); 
}

int count_of_medium(int *array, int dimension, float medium)
{
	int summ = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (array[i] > medium)
			summ++;
	}
	return summ;
}

int *creation_of_array(int *array, int *new_array, int dimension, float medium)
{
	int count = 0;
	for (int i = 0; i < dimension; i++)
	{
		if (array[i] > medium)
		{
			new_array[count] = array[i];
			count++;
		}
	}
	return new_array;
}

void seeout(int *array, int dimension)
{
	for (int i = 0; i < dimension; i++)
		printf("%d ", array[i]);
}