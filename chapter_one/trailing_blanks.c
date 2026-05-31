#include <stdio.h>

#define MAXLINE 20
#define BLANKLINE 1

int cleaner(char line[]);

int main ()
{
	int cl; /* Cleared Line */
	char line[MAXLINE];

	while ((cl = cleaner(line)) > 0)
	{
		if (line[0] != '\n')
		{
			line[cl] = '\0';
			printf("%s", line);
			printf("\n");
		}
	}

	return 0;
}

int cleaner(char line[])
{
	int i, c, btcounter;;

	i = btcounter = 0;

	while ((c = getchar()) != EOF && c != '\n' && i < MAXLINE - 1)
	{
		if (c == ' ' || c == '\t')
		{
			line[i] = c;
			++btcounter;
		}
		else
		{
			line[i] = c;
			btcounter = 0;
		}
		++i;
	}

	i = i - btcounter;
	if (i <= 0)
	{
		line[0] = '\n';
		i = BLANKLINE;
	}

	return i;
}














