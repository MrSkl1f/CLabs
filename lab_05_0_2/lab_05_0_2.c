//Вставить строку из чисел 100 после каждой строки, в которой количество элементов,
//начинающихся на заданную цифру, равно количество элементов, которые
//заканчиваются на эту же цифру;

#include <stdio.h>
#define ROWCOLNUM 2
#define MINROW 0
#define MAXROW 10
#define MINCOL 0
#define MAXCOL 10
#define TRUEOUT 0
#define FALSEOUT 1
#define FALSE 0

void input_buf(int *buf, int n, int m, int *check_out);
int main_check(int **array, int lines, int m, int number);
int check_first(int cur);
int check_last(int cur);
void add_row(int **array, int n, int m, int need);
void fill_line(int **array, int need, int m);
void see_out(int **array, int n, int m);

int main()
{
	int buf[MAXROW * MAXCOL * 2];
	int *array[MAXROW];
	int n, m, number;
	int check = 0;
	printf("Input N ");
	check += scanf("%d", &n);
	printf("Input M ");
	check += scanf("%d", &m);
	int out = TRUEOUT;
	int *check_out = &out;
	if (check == ROWCOLNUM)
	{
		if (n > MINROW && n <= MAXROW && m > MINCOL && m <= MAXCOL)
		{
			for (int i = 0; i < MAXROW * 2; i++)
				array[i] = (buf + i * m);
			input_buf(buf, n, m, check_out);
		
			printf("Input number ");
			check += scanf("%d", &number);
			if (check == 3)
			{
				if (number >= 0 && number / 10 == 0)
					if (out != FALSEOUT)
					{
						n = main_check(array, n, m, number);
						see_out(array, n, m);
						out = TRUEOUT;
					}
					else
						out = FALSEOUT;
				else
					out = FALSEOUT;
			}
			else
				out = FALSEOUT;
		}
		else
			out = FALSEOUT;
	}
	else
		out = FALSEOUT;
	return out;
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

void input_buf(int *buf, int n, int m, int *check_out)
{
	*check_out = TRUEOUT;
	for (int i = 0; i < n * m; i++)
		if (scanf("%d", (buf + i)) != 1)
			*check_out = FALSEOUT;
}

int main_check(int **array, int lines, int m, int number)
{
	for (int i = 0; i < lines; i++)
	{
		int first = 0, last = 0;
		for (int j = 0; j < m; j++)
		{
			if (check_first(array[i][j]) == number)
				first++;
			if (check_last(array[i][j]) == number)
				last++;
		}
		if (first == last && first != FALSE && last != FALSE)
		{
			add_row(array, lines, m, i);
			lines++;
			i++;
		}
	}
	return lines;
}

int check_first(int cur)
{
	if (cur < 0)
		cur *= -1;
	while (cur >= 10)
		cur /= 10;
	return cur;
}

int check_last(int cur)
{
	if (cur < 0)
		cur *= -1;
	return cur % 10;
}

void add_row(int **array, int n, int m, int need)
{
	for (int j = 0; j < m; j++)
	{
		for (int k = n - 1; k > need; k--)
		{	
			array[k + 1][j] = array[k][j];
		}
	}
	fill_line(array, need, m);
}

void fill_line(int **array, int need, int m)
{
	for (int j = 0; j < m; j++)
		array[need + 1][j] = 100;
}