#include <stdio.h>

#define MAXLENGTH 6
#define TRUE 1
#define FALSE 0

int lineinput(char line[]);
void sreverse(char line[], int fli);

int main ()
{
	int i, fli; /* Final Line Index*/
	char line[MAXLENGTH];

	while ((fli = lineinput(line)) > 0)		// while there is a line
	{
		line[fli] = '\0'; 			// mark the final of line/string
		sreverse(line, fli); 			// invert it
		for (i = 0; line[i] != '\0'; ++i)	// run the array, untill the final marked before
			putchar(line[i]); 		// print it
		if (line[i - 1] != '\n') 		// if it doesnt end with an enter (to better view)
			putchar('\n');			// print one
	}

	return 0;
}

int lineinput(char line[])
{
	int i, c, enter, eof;

	i = 0;
	enter = eof = FALSE;

	while (enter == FALSE && eof == FALSE)
	{
		if ((c = getchar()) != EOF && i < MAXLENGTH - 1)
		{
			line[i] = c;
			++i;
		}
		else if (c == EOF)
			eof = TRUE;

		if (c == '\n')
			enter = TRUE;
	}

	return i;
}

void sreverse(char line[], int fli)
{
	int i, temp;

	--fli;

	if (line[fli] == '\n')
		--fli;
	if (fli > 0)
	{
		for (i = 0; i <= (fli / 2); ++i)
		{
			temp = line[i];
			line[i] = line[fli - i];
			line[fli - i] = temp;
		}
	}
}
