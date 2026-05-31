#include <stdio.h>

#define LINE_RANGE 10
#define TRUE 1
#define FALSE 0

/*
   a system that when the value of X is equal to Y, a new
   line will appear. I think it's a good beggin.

   let's just write some ideas

   we can have a variable to check if the index A guads
   the last blank line or not, and make a new line or not.

   i still dont know what to do with the folder function
   or it parameters (done i think)
*/

// variables
int last_blank_index, no_blank;

// functions
int get_line(char line[]);
int folder(char line[], int i, int remaining);

int main () // arrays of characters can always ends with '\0'
{
	int indices, remaining;
	char line[LINE_RANGE];

	remaining = LINE_RANGE;

	while ((indices = get_line(line)) > 0)
	{
		remaining = folder(line, indices, remaining);
	}

	printf("\n");
	return 0;
}

int get_line(char line[])
{
	int i, c;
	c = '\0';
	i = 0;

	no_blank = TRUE;
	last_blank_index = -1;

	while(c != '\n' && c != EOF && i < LINE_RANGE) // (c = getchar()) != EOF && c != '\n')...
	{
		if ((c = getchar()) != EOF)
		{
			if (c == ' ')
			{
				last_blank_index = i;
			}
			line[i] = c;
			++i;
		}
	}

	if (last_blank_index != -1)
	{
		no_blank = FALSE;
	}

	return i;
}

int folder(char line[], int i, int remaining)
{
	int index;

	index = 0;

	if (i >= remaining)
	{
		if (no_blank == FALSE)
		{
			while (index < last_blank_index)
			{
				if (remaining > 0)
				{
					printf("%c", line[index]); // does putchar ever exist?
					--remaining;
					++index;
				}
				else
				{
					remaining = LINE_RANGE;
					printf("-\n");
				}
			}

			remaining = LINE_RANGE;
			printf("\n");

			for (index = index + 1; index < i; ++index)
			{
				printf("%c", line[index]);

				if (line[index] != '\n')
				{
					--remaining;
				}
				else
				{
					remaining = LINE_RANGE;
				}
			}
		}
		else
		{
			while (index < i)
			{
				if (remaining > 0)
				{
					printf("%c", line[index]);

					if (line[index] != '\n')
					{
						--remaining;
					}
					else
					{
						remaining = LINE_RANGE;
					}

					++index;
				}
				else
				{
					printf("-\n");
					remaining = LINE_RANGE;
				}
			}
		}
	}
	else
	{
		while (index < i)
		{
			printf("%c", line[index]);

			if (line[index] != '\n')
			{
				--remaining;
			}
			else
			{
				remaining = LINE_RANGE;
			}

			++index;
		}
	}

	return remaining;
}
