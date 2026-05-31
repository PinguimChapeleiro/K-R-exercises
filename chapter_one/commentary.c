#include <stdio.h>

#define IN 1 	// inside of
#define OUT 0 	// out of
#define TRUE 1
#define FALSE 0  /* just for the final test */


void put_char(int c, char state);
int inacomm(int c); 	// inside a comment function


char bar, dbar, asterisk, quotes, state, canprint, temp, line_error;



int main ()
{
	bar = dbar = asterisk = FALSE;
	quotes = state = OUT;
	canprint = TRUE;
	temp = 0;

	int c, line;
	line = 1;

	while ((c = getchar()) != EOF)
	{
		++line;
		state = inacomm(c);
		put_char(c, state);
	}

	putchar('\n');
	return 0;
}

int inacomm(int c)
{

	if (state == OUT)
	{
		if (c == '"' && quotes == OUT)
		{
			quotes = IN;
			return state;
		}
		else if (c == '"' && quotes == IN)
		{
			quotes = OUT;
			return state;
		}
		else if (quotes == OUT)
		{
			if (c == '/')
			{
				if (bar == TRUE)
				{
					bar = FALSE;
					dbar = TRUE;
					state = IN;
					return state;
				}
				else
				{
					bar = TRUE;
					return state;
				}
			}
			else if (c == '*' && bar == TRUE)
			{
				state = IN;
				return state;
			}
			else
			{
				bar = FALSE;
				return state;
			}
		}
	}
	else // if state == IN
	{
		if (dbar == TRUE)
		{
			if (c == '\n')
			{
				dbar = FALSE;
				state = OUT;
				return state;
			}
		}
		else
		{
			if (c == '*')
			{
				asterisk = TRUE;
				return state;
			}
			else if (c == '/' && asterisk == TRUE)
			{
				asterisk = FALSE;
				bar = FALSE;
				return state;

			}
			else if (bar == FALSE && asterisk == FALSE)
			{
				state = OUT;
				return state;
			}
			else
			{
				asterisk = FALSE;
					return state;
			}
		}
	}

	return state;
}

void put_char(int c, char state)
{
	if (state == OUT)
	{
		if (c == '/' && canprint == TRUE)
		{
			canprint = FALSE;
			temp = c;
		}
		else if (canprint == FALSE)
		{
			canprint = TRUE;
			putchar(temp);
			putchar(c);
		}
		else	// if (c != '/' && canprint == TRUE)
		{
			putchar(c);
		}
	}
	else	// if (state == IN)
	{
		canprint = TRUE;
	}
}
