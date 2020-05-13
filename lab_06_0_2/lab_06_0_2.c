#include <stdio.h>
#include <string.h>
#define TRUEOUT 0
#define FALSEOUT 1
#define MAXSTRING 255
#define MAX 16
#define MAXWORD 16

void input(char *str, int *out);
void transform(char *buf, char **words);
void split_word(char **words, int *count, char *str, char *symbols);
void count_cur(char **words, int count);
int before(char **words, int i);

int main()
{
	int out = TRUEOUT;
	char *symbols = " \t\n,;:-.!?";
	char str[MAXSTRING];
	// Общее кол-во слов
	int count_of_words;

	input(str, &out);

	// Буферная зона
	char buf[MAX * MAXWORD];
	// Указатели на слова
	char *words[MAXWORD];

	if (!out)
	{
		// Преобразуем в матрицу указателей на слова
		transform(buf, words);
		// Разбиваем на слова и заполняем
		split_word(words, &count_of_words, str, symbols);
		if (count_of_words == 0)
			out = FALSEOUT;
	}
	if (!out)
	{
		printf("Result: \n");
		// Находим и сразу выводим на экран
		count_cur(words, count_of_words);
	}
	return out;
}

void input(char *str, int *out)
{
	*out = FALSEOUT;
	if (fgets(str, MAXSTRING, stdin) != NULL)
		if (strchr(str, '\n') != NULL)
			*out = TRUEOUT;
}

void transform(char *buf, char **words)
{
	for (int i = 0; i < MAXWORD; i++)
		words[i] = buf + MAX * i;
}

void count_cur(char **words, int count)
{
	int n = 1;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (strcmp(words[i], words[j]) == 0 && before(words, i))
			{
				n++;
			}
		}
		if (before(words, i))
			printf("%s %d\n", words[i], n);
		n = 1;
	}
}

int before(char **words, int i)
{
	int count = 0;
	for (int j = 0; j < i; j++)
	{
		if (strcmp(words[i], words[j]) == 0)
			count++;
	}
	int out = 0;
	if (count == 0)
		out = 1;
	return out;
}

void split_word(char **words, int *count, char *str, char *symbols)
{
	int count_sym = 0;
	for (; str[count_sym]; count_sym++);
	int j = 0;
	int k = 0;
	
	*count = 0;
	while (j <= count_sym)
	{
		while (strchr(symbols, str[j]) == 0)
		{
			words[*count][k] = str[j];
			j++;
			k++;
		}	
		if (j > 0)
		{
			if (strchr(symbols, str[j - 1]) == 0 && strchr(symbols, str[j]) != 0)
			{
				words[*count][k] = '\0';
				*count += 1;
				k = 0;
			}
		}
		j++;	
	}
}