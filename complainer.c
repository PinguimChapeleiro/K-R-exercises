#include <stdio.h>

// definitions:
#define YES 1
#define NO 0
#define INSIDE
#define OUTSIDE

// external variables:
int c;		// 'c' variable will store a single character from input
int line = 1;

// functions syntax:
/*
int basic_input_filter
int delimiters
int quotes // include scape sequence
int comments
*/

int main ()
{
	int value;

	while ((value = basic_input_filter) == INSIDE) // while we we're inside a file
	{


int basic_input_filter()
{
	c = getchar();

	if (c == EOF)
	{
		return OUTSIDE;
	}
	else if (c == '\n')
	{
		++line;
		return INSIDE;
	}

