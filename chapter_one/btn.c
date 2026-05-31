#include <stdio.h>

int main () {
 	int c;
	int blanks;
	int tabs;
	int newlines;

	blanks = tabs = newlines = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		if (c == '\t')
			++tabs;
		if (c == '\n')
			++newlines;
	}
	printf("blanks: %d\ntabs: %d\nnewlines: %d\n", blanks, tabs, newlines);
	return 0;
}
