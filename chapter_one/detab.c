
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define COLUMNS 6

int tab;

int detector(char string[]);
int tabulator(char string[], int i);

int main ()
{
	int i, index;
	char string[COLUMNS];

	while ((i = detector(string)) > 0)
	{
		if (tab == TRUE)
		{
			i = tabulator(string, i);
		}

		for (index = 0; index <= i; ++index)
		{
			printf("%c", string[index]);
		}
	}

	putchar('\n');
	return 0;
}

int detector(char string[])
{
	int i, c;

	tab = FALSE;
	i = -1;
	c = '\0';

	while (c != '\t' && c != '\n' && c != EOF && i < COLUMNS)
	{
		c = getchar();

		if (c != EOF)
		{
			++i;
			string[i] = c;

			if (c == '\t')
			{
 				tab = TRUE;
			}
		}
	}

	return i;
}

int tabulator(char string[], int i)
{
	if (string[i] == '\t')
	{
		while (i < COLUMNS)
		{
			string[i] = ' ';
			++i;
		}
	}

	return i;
}















