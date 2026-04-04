#include <stdio.h>

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

// max values:
#define MAX_D_ERROR_LINES	7

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
#define NEW_LINE	10

#define SCAPE		92

#define CHAR		97

/*
   NOTE: all char variables in this program control
   a state of something, like YES or NO
*/

// external variables:
char canprint, its_a_scape;

// functions syntax:
int basic_filter(int c);
int what_is_c;

int delimiter(int c, int line, int openned, int d_error_lines[]);

int quotes(int line, int qerror_line);
char inside_quotes, quotes_type;

int comment(int line, char ctype, char comment_state);
char bar, second_bar, asterisk, second_asterisk, cerror_line, canprint;

void parser(int openned, int d_error_lines[], int qerror_line);
char found_error; // it also uses cerror_line


int main ()
{
	// external
	cerror_line = quotes_type = what_is_c = NOTHING;
	its_a_scape = found_error = inside_quotes = NO;
	asterisk = bar = second_bar = OUT;

	// local
	int d_error_lines[MAX_D_ERROR_LINES];

	int c, openned, line, qerror_line;
	char ctype, comment_state;

	c = '\0';
	line = 1;
	printf("%d |", line);

	qerror_line = openned = ctype = NOTHING;
	comment_state = OUT;

	while ((c = getchar()) != EOF)
	{
		canprint = YES;
		if (what_is_c == NEW_LINE)
		{
			++line;
			printf("%d |", line);
		}

		// tells what is "c"
		ctype = basic_filter(c);

		// outputing for visual debbug
		if (comment_state == OUT && bar == YES)
		{
			if (what_is_c != BAR && what_is_c != ASTERISK)
			{
				putchar('/');
				putchar(c);
			}
		}

		// who will handle "¢"
		if (ctype == DELIMITER && comment_state == OUT && inside_quotes == NO)
		{
			openned = delimiter(c, line, openned, d_error_lines);
		}
		else if (ctype == QUOTES && comment_state == OUT && its_a_scape == NO)
		{
			qerror_line = quotes(line, qerror_line);
		}

		if (inside_quotes == NO)
		{
			comment_state = comment(line, ctype, comment_state);
		}

		// also visual debug
		if (comment_state == OUT && bar == NO && canprint == YES)
		{
			putchar(c);
		}

		// checking scape
		if (its_a_scape == YES)
		{
			its_a_scape = NO;
		}
		else if (ctype == SCAPE)
		{
			its_a_scape = YES;
		}

	}

	parser(openned, d_error_lines, qerror_line);

	if (found_error == NO)
	{
		putchar('\n');
	}
	return 0;
}

int basic_filter(int c)
{
/*
	this function return the type of variable "c"
	and tells the program what its value is in
	order, making the functions easy to read
*/


	// scape
	if (c == '\\' && inside_quotes == YES)
	{
		what_is_c = SCAPE;
		return SCAPE;
	}

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
		what_is_c = BRACES;
		return DELIMITER;
	}

	// quotes
	if (c == '"')
	{
		what_is_c = DOUBLE_QUOTES;
		return QUOTES;
	}
	else if (c == '\'')
	{
		what_is_c = SINGLE_QUOTES;
		return QUOTES;
	}

	// comment
	if (c == '/')
	{
		what_is_c = BAR;
		return COMMENT;
	}
	else if (c == '*')
	{
		what_is_c = ASTERISK;
		return COMMENT;
	}
	else if (c == '\n')
	{
		what_is_c = NEW_LINE;
		return COMMENT;
	}

	// normal characters
	what_is_c = CHAR;
	return NORMAL_CHAR;
}

int delimiter(int c, int line, int openned, int d_error_lines[]) // d_error_lines[example[0]] = line
{								 // d_error_lines[example[1]] = what_is_c
	if (what_is_c == PARENTHESES)
	{
		if (c == '(')
		{
			++openned;

			if (openned < MAX_D_ERROR_LINES)
			{
				d_error_lines[openned] = line;
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

			if (openned < MAX_D_ERROR_LINES)
			{
				d_error_lines[openned] = line;
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

			if (openned < MAX_D_ERROR_LINES)
			{
				d_error_lines[openned] = line;
			}
		}

		else if (c == '}' && openned >= 0)
		{
			--openned;
		}
	}

	return openned;
}

int quotes(int line, int qerror_line)
{
	// double quotes
	if (what_is_c == DOUBLE_QUOTES && quotes_type == NOTHING)
	{
		qerror_line = line;
		quotes_type = DOUBLE_QUOTES;
		inside_quotes = YES;
	}
	else if (what_is_c == DOUBLE_QUOTES && quotes_type == DOUBLE_QUOTES)
	{
		qerror_line = NOTHING;
		quotes_type = NOTHING;
		inside_quotes = NO;
	}

	// single quotes
	else if (what_is_c == SINGLE_QUOTES && quotes_type == NOTHING)
	{
		qerror_line = line;
		quotes_type = SINGLE_QUOTES;
		inside_quotes = YES;
	}
	else if (what_is_c == SINGLE_QUOTES && quotes_type == SINGLE_QUOTES)
	{
		qerror_line = NOTHING;
		quotes_type = NOTHING;
		inside_quotes = NO;
	}

	return qerror_line;
}

int comment(int line, char ctype, char comment_state)
{
	// discarding fake calls
	if (what_is_c == NEW_LINE && comment_state == OUT)
	{
		return comment_state;
	}
	else if (what_is_c == NEW_LINE && second_bar == NO)
	{
		return comment_state;
	}

	// comment untrigger
	if (bar == YES && ctype != COMMENT)
	{
		bar = NO;
		return comment_state;
	}

	// oneline comments type
	else if (what_is_c == BAR && bar == YES)
	{
		bar = NO;
		second_bar = YES;
		comment_state = IN;
		return comment_state;
	}
	else if (what_is_c == NEW_LINE && second_bar == YES)
	{
		bar = NO;
		second_bar = NO;
		comment_state = OUT;
		return comment_state;
	}

	// comment trigger
	else if (what_is_c == BAR && comment_state == OUT)
	{
		bar = YES;
		return comment_state;
	}

	// long comments type
	else if (bar == YES && what_is_c == ASTERISK)
	{
		bar = NO;
		asterisk = YES;
		comment_state = IN;
		cerror_line = line;
		return comment_state;
	}
	else if (asterisk == YES && what_is_c == ASTERISK)
	{
		second_asterisk = YES;
		return comment_state;
	}
	else if (second_asterisk == YES && what_is_c == BAR)
	{
		bar = NO;
		asterisk = second_asterisk = NO;
		comment_state = OUT;
		cerror_line = NOTHING;
		canprint = NO;
		return comment_state;
	}
	else if (second_asterisk == YES && what_is_c != BAR)
	{
		second_asterisk = NO;
		return comment_state;
	}

	return comment_state;
}

void parser(int openned, int d_error_lines[], int qerror_line)
{
	int i;

	if (openned != NOTHING)
	{
		found_error = YES;

		for (i = 0; i <= openned; ++i)
		{
			printf("========\n");
			printf("error type: DELIMITER\n");
			printf("error line:  %d\n", d_error_lines[i]);
		}
	}

	if (qerror_line != NOTHING)
	{
		found_error = YES;

		printf("========\n");
		printf("error type: quotes\n");
		printf("error line: %d\n", qerror_line);
	}

	if (cerror_line != NOTHING)
	{
		found_error = YES;

		printf("========\n");
		printf("error type: comment\n");
		printf("error line: %d\n", cerror_line);
	}
}
