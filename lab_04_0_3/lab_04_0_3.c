// Удалите из исходного массива все элементы, которые являются
// числами-палиндромами.

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TRUEOUT 0
#define FALSEOUT 1
#define MINLEN 0
#define MAXLEN 10

void input_array(int *array, int dimension, int *check_out);
int summ_of_elem(int *array, int dimension);
int palindrome(int n);
void seeout(int *array, int dimension);
void solution(int *arr, int dimension, int *check_out);

int main()
{
	int out = FALSEOUT;
	int *check_out = &out;
	int dimension, check = TRUEOUT;
	int array[MAXLEN];

	printf("Input the dimension > ");
	check += scanf("%d", &dimension);
	
	if (check == TRUE && dimension > MINLEN && dimension <= MAXLEN)
	{
		input_array(array, dimension, check_out);
		if (out != FALSEOUT)
		{
			int new_dimension = summ_of_elem(array, dimension);
			if (new_dimension == 0)
				out = FALSEOUT;
			else
			{
				solution(array, dimension, check_out);
				if (out != FALSEOUT)
				{
					seeout(array, new_dimension);
					out = TRUEOUT;
				}
			}
		}
	}	
	return out;
}

void input_array(int *array, int dimension, int *check_out)
{
	int check = TRUEOUT;
	for (int i = 0; i < dimension; i++)
		check += scanf("%d", (array + i));

	if (check == dimension)
		*check_out = TRUEOUT;
}

int summ_of_elem(int *array, int dimension)
{
	int summ = 0;
	for (int i = 0; i < dimension; i++)
		if (palindrome(array[i]))
			summ++;
	return (dimension - summ);
}

int palindrome(int n)
{
	int pal = n;
	int check_pal = 0;
	while (pal > 0)
	{
		check_pal = 10 * check_pal + pal % 10;
		pal /= 10;
	}
	return (check_pal == n);
}

void seeout(int *array, int dimension)
{
	for (int i = 0; i < dimension; i++)
		printf("%d ", array[i]);
}

void solution(int *arr, int dimension, int *check_out)
{
	int i = 0;
	for (int j = 0; j < dimension; j++)   
	{
		if (palindrome(arr[j]))
		{
			j++;
			for (; j < dimension && palindrome(arr[j]); j++);
			if (j < dimension)
			{
				arr[i] = arr[j];
				i++;	
			}
		}
		else
		{
			arr[i] = arr[j];
			i++;
		}
	}
	if (i == 0)
		*check_out = FALSEOUT;
}