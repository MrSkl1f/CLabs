// По матрице получить одномерный массив, присвоив его k-тому элементу
// значение 1, если выполняется указанное ниже условие, и значение 0 иначе
// элементы k-го столбца упорядочены по убыванию

#include <stdio.h>
#define ROWCOLCOUNT 2
#define MINROW 0
#define MAXROW 10
#define MINCOL 0
#define MAXCOL 10
#define TRUEOUT 0
#define FALSEOUT 1
#define TRUE 1
#define FALSE 0

void array_check(int **array, int n, int m, int *array_for_out);
void input_buf(int *buf, int n, int m, int *check_out);
void see_out_array_check(int *array_for_out, int m);

int main()
{
	int n, m;
	int check = 0;
	printf("Input N ");
	check += scanf("%d", &n);
	printf("Input M ");
	check += scanf("%d", &m);
	int out = FALSEOUT;
	int *check_out = &out;
	if (check == ROWCOLCOUNT && n > MINROW && n < MAXROW && m > MINCOL && m < MAXCOL)
	{
		int buf[n * m];
		input_buf(buf, n, m, check_out);
		if (out != FALSEOUT)
		{
			int *array[n];
			for (int i = 0; i < n; i++)
				array[i] = (buf + i * m);
			int array_for_out[m];
			array_check(array, n, m, array_for_out);
			see_out_array_check(array_for_out, m);
			out = TRUEOUT;
		}
	}
	else
		out = FALSEOUT;
	return out;
}

void input_buf(int *buf, int n, int m, int *check_out)
{
	*check_out = TRUEOUT;
	for (int i = 0; i < n * m; i++)
		if (scanf("%d", (buf + i)) != 1)
			*check_out = FALSEOUT;
}

void array_check(int **array, int n, int m, int *array_for_out)
{
	for (int k = 0; k < m; k++)
	{
		int check = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (array[i][k] < array[i + 1][k])
				check++;
		}
		
		int checkcur = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (array[i][k] == array[i + 1][k])
				checkcur++;
		}

		if (check == 0 && checkcur != n - 1)
			check = 1;
		else
			check = 0;
		array_for_out[k] = check;
	}
}

void see_out_array_check(int *array_for_out, int m)
{
	for (int i = 0; i < m; i++)
		printf("%d ", array_for_out[i]);
}