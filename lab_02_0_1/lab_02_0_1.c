#include <stdio.h>

int power(int number, int pow);

int main()
{
	int a, n, rc;
	int out = 1;
	float check;

	printf("Input your number and pow with space > ");
	rc = scanf("%d %f", &a, &check);

	n = (int)check;
	if (rc != 2 || n < 0 || (check / n != 1))
		printf("Error!\n");
	else
	{
		printf("Your power is %d", power(a, n));
		out = 0;
	}
	return out;
}

int power(int number, int pow)
{
    int count = 1;

    while (pow > 0)
    {
        count *= number;
        pow --;
    }
    return count;
}
