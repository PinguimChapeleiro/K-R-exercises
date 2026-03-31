#include <stdio.h>

#define NONE



/*
 nothing, to prevent invalid values. it also tells
 what is the current error_lines index, but when
 there is no error_lines, its index stores...
*/
#define NOTHING -1

// its_a_scape definitions:
#define YES	1
#define NO	0

// comment_state && quote_state definitions:
#define IN	1
#define OUT	0

// quotes_state definitions:
#define OPEN	1
#define CLOSED	0

// max values:
#define MAX_LINE_ERRORS	7

// ctypes values:	\\symbolic numbers:
#define NORMAL_CHAR	65
#define DELIMITER	41
#define QUOTES		96
#define COMMENT		35

// what_is_c values:	\\symbolic numbers:
#define PARENTHESES	40
#define BRACKETS	91
#define BRACES		123

#define DOUBLE_QUOTES	34
#define SINGLE_QUOTES	39

#define BAR		47
#define ASTERISK	42

#define SCAPE		92
#define CHAR		97


// NOTE: all char types in this program control
// a state of something, like YES or NO

// external variables:
int what_is_c, q_error_line;
char canprint;

// external arrays:
int d_error_lines[MAX_ERROR_LINES];


// functions syntax:
int basic_filter(int c);

int delimiters(int c, int line, int oppened);

int quotes(int c, int line);
char inside_quotes, doubleq, singleq, qerror_line;

int comment(int c, int line, char comment_state);
/*
int quotes // include scape sequence
int comments
*/

int main ()
{
	qerror_line = -1;
	what_is_c = NOTHING;
	inside_quotes = NO;

	char ctype, comment_state, its_a_scape;
	int c, oppened, line;

	c = '\0';
	line = 0;
	openned = ctype = NOTHING;
	comment_state = OUT;
	its_a_scape = NO;

	while ((c = getchar()) != EOF)
	{
		++line;

		// tells what is "c"
		ctype = basic_filter(c);

		// who will handle "¢"
		if (ctype == NORMAL_CHAR)
		{
			canprint = YES;
		}
		else if (ctype == DELIMITER && comment_state == OUT && its_a_scape == NO && inside_quotes == NO)
		{
			oppened = delimiter(c, line, oppened);
		}
		else if (ctype == QUOTES && comment_state == OUT && its_a_scape == NO)
		{
			quotes(c, line);
		}
		else if (ctype == COMMENT && inside_quotes == NO)
		{
			comment_state = comment(c, line, comment_state);
		}

		// checking scape
		if (what_is_c == SCAPE)
		{
			if (c == '\\' && inside_quotes == YES)
			{
				its_a_scape = YES;
			}
			else if (its_a_scape == YES)
			{
				its_a_scape = NO;
			}
		}

		if (canprint == YES)
		{
			putchar(c);
		}
	}

	putchar('\n')
	return 0;
}

int basic_filter(int c)
{
/*
	this function return the type of variable "c"
	and tells the program what its value is in
	order, making the functions easy to read
*/

	// delimiters
	if (c == '(' || c == ')')
	{
		what_is_c = PARENTHESES;
		return DELIMITER;
	}
	else if (c == '[' || c == ']')
	{
		what_is_c = BRACKETS;
		return DELIMITER;
	}
	else if (c == '{' || c == '}')
	{
		what_is_c BRACES;
		return DELIMITER;
	}

	// quotes
	else if (c == '"')
	{
		what_is_c DOUBLE_QUOTES;
		return QUOTES;
	}
	else if (c == '\'')
	{
		what_is_c SINGLE_QUOTES;
		return QUOTES;
	}

	// scape
	else if (c == '\\')
	{
		what_is_c SCAPE;
		return QUOTES;
	}

	// comment
	else if (c == '/')
	{
		what_is_c = BAR;
		return COMMENT;
	}
	else if (c == '*')
	{
		what_is_c = ASTERISK;
		return COMMENT;
	}

	// normal characters
	else
	{
		what_is_c = CHAR;
		return NORMAL_CHAR;
	}
}

int delimiter(int c, int line, int oppened)
{
	if (what_is_c == PARENTHESES)
	{
		if (c == '(')
		{
			++openned;

			if (openned < MAX_ERROR_LINES)
			{
				error_lines[openned] = line;
			}
		}

		else if (c == ')' && openned >= 0)
		{
			--openned;
		}
	}

	else if (what_is_c == BRACKETS)
	{
		if (c == '[')
		{
			++openned;

			if (openned < MAX_ERROR_LINES)
			{
				error_lines[openned] = line;
			}
		}

		else if (c == ']' && openned >= 0)
		{
			--openned;
		}
	}

	else if (what_is_c == BRACES)
	{
		if (c == '{')
		{
			++openned;

			if (openned < MAX_ERROR_LINES)
			{
				error_lines[openned] = line;
			}
		}

		else if (c == '}' && openned >= 0)
		{
			--openned;
		}
	}

	return openned;
}

void quotes(int c, int line)
{
	if (its_a_scape == NO)
	{
		// double quotes
		if (c == '"' && quotes_type == NOTHING)
		{
			qerror_lines = line;
			quotes_type = DOUBLE;
			inside_quotes = YES;
		}
		else if (c == '"' && quotes_type == DOUBLE)
		{
			qerror_line = -1;
			quotes_type = NOTHING;
			inside_quotes = NO;
		}

		// single quotes
		else if (c == '\'' && quotes_type == NOTHING)
		{
			qerror_line = line;
			quotes_type = SINGLE;
			inside_quotes = YES;
		}
		else if (c == '\'' && quotes_type == SINGLE)
		{
			qerror_line = -1;
			quotes_type = NOTHING;
			inside_quotes = NO;
		}
	}
}


