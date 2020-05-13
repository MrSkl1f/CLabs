// Склифасовский Денис ИУ7-15
// Программа, которая вычисляет
// количество бутылок, которые мы можем купить

#include <stdio.h>

int bottles(int s);

int main(void)
{
	int s;	// Вся сумма
	printf("Input all your money > ");
	scanf("%d", &s);

	printf("All bottles - %d", bottles(s));

	return 0;
}

int bottles(int s)
{
	return (s - 20) / 25;
}