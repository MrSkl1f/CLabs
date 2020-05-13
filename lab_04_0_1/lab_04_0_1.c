// Найти сумму четных элементов массива

#include <stdio.h>
#define TRUEOUT 0
#define FALSEOUT 1
#define TRUE 1
#define FALSE 0
#define MINLEN 0
#define MAXLEN 10

// Ввод массива
int *input_array(int *array, int dimension, int *check_out);
// Вычисление суммы четных элементов
int summ_of_even(int *array, int dimension, int summ);
// Вычисление количества четных элементов
int check_summ(int *array, int dimension, int summ);

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
			int summ = 0;
			summ = summ_of_even(array, dimension, summ);
			int check_of_summ = 0;
			check_of_summ = check_summ(array, dimension, check_of_summ);
			if (check_of_summ == 0)
				out = FALSEOUT;
			else
			{
				printf("Your summ > %d", summ);
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

int check_summ(int *array, int dimension, int summ)
{
	for (int i = 0; i < dimension; i++)
	{
		if (array[i] % 2 == 0)
			summ++;
	}
	return summ;
}

int summ_of_even(int *array, int dimension, int summ)
{
	for (int i = 0; i < dimension; i++)
	{
		if (array[i] % 2 == 0)
			summ += array[i];
	}
	return summ;
}
