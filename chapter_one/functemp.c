#include <stdio.h>

void ftc(int lower, int upper, int step);

int main ()
{
	ftc(0, 300, 20);
	printf("\n");
}

void ftc(int lower, int upper, int step)
{
	int fahr, celsius;

	fahr = lower;

	while (fahr <= upper)
	{
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
