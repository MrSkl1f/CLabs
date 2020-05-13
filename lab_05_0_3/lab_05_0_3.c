// Упорядочить строки матрицы по возрастанию суммы их элементов

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define ROWCOLCOUNT 2
#define MINROW 0
#define MAXROW 10
#define MINCOL 0
#define MAXCOL 10
#define TRUEOUT 0
#define FALSEOUT 1

void input_buf(int *buf, int n, int m, int *check_out);
void bubble_arr(int **array, int n, int m);
int check_line(int **array, int m, int need);
void swap(int **array, int need, int m);
void see_out(int **array, int n, int m);

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

			bubble_arr(array, n, m);
			see_out(array, n, m);
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

void bubble_arr(int **array, int n, int m)
{
	int count = 1;
	while (count < n)
	{
		for (int i = 0; i < (n - count); i++)
		{
			if (check_line(array, m, i) > check_line(array, m, i + 1))
			{
				swap(array, i, m);	
			}
		}
		count++;
	}
}

int check_line(int **array, int m, int need)
{	
	int summ = 0;
	for (int j = 0; j < m; j++)
		summ += array[need][j];
	return summ;
}

void swap(int **array, int need, int m)
{
	int help;
	for (int j = 0; j < m; j++)
	{
		help = array[need][j];
		array[need][j] = array[need + 1][j];
		array[need + 1][j] = help;
	}
}

void see_out(int **array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%d ", array[i][j]);			 
		printf("\n");
	}
}