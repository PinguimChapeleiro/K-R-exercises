#include <stdio.h>

#define MAXLENGTH 20
#define LONGERTHAN 8


int charcount(char line[]);

int main ()
{
	int ll;  /* line length */
	char line[MAXLENGTH];

	while ((ll = charcount(line)) > 0)
	{
		if ( ll > LONGERTHAN && ll < MAXLENGTH)
		{
			line[ll] = '\0';
			printf("%s", line);
		}
		else if (ll >= MAXLENGTH)
		{
			line[MAXLENGTH - 1] = '\0';
			printf("%s", line);
		}


		printf("\n");
	}

	return 0;
}

int charcount(char line[])
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		if (i < MAXLENGTH)
			line[i] = c;
		++i;
	}

	return i;
}






