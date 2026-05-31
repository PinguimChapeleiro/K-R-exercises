#include <stdio.h>

#define TABSTOPS 8
#define TAB 8

int getstring(char string[]);
int detab(char string[], int i);
int entab(char string[], int i);
int fix(char string[], int i, int index);

int main ()
{
	int i, index;
	char string[TABSTOPS];

	while ((i = getstring(string)) > 0)
	{
		i = detab(string, i);
		i = entab(string, i);

		for (index = 0; index < i; ++index)
		{
			printf("[%c] ", string[index]);
		}
	}

	printf("\n");
	return 0;
}

int getstring(char string[])
{
	int i, c;

	i = 0;
	c = '\0';

	while (c != '\n' && c != '\t' && c != EOF && i < TABSTOPS)
	{
		if ((c = getchar()) != EOF)
		{
			string[i] = c;
			++i;
		}
	}

	return i;
}

int detab(char string[], int i)
{
	if (string[i - 1] == '\t')
	{
		--i;
		while (i < TABSTOPS)
		{
			string[i] = ' ';
			++i;
		}
	}

	return i;
}

int entab(char string[], int i)
{
	int need_tab, index;

	need_tab = 0;

	for(index = 0; index < i; ++index)
	{
		if (string[index] == ' ')
		{
			++need_tab;
			if (need_tab == TAB)
			{
				index = index + 1 - TAB;
				string[index] = '\t';
				need_tab = 0;
 				i = fix(string, i, index);
			}
		}
		else
		{
			need_tab = 0;
		}
	}

	return i;
}

int fix(char string[], int i, int index)
{//			4	1
	int present, future;

	future = TAB - 1;
	i = i - future;

	for (present = index + 1; present < i; ++present)
	{
		string[present] = string[present + future];
	}

	return i;
}
