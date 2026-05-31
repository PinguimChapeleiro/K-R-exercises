#include <stdio.h>

int main () {
	#define FALSE 0
	#define TRUE 1

	int c;
	int blank;

	blank = FALSE;

	while ((c = getchar()) != EOF) {
		if (c != ' ')
			putchar(c);
		if (blank == FALSE) {
			if (c == ' ') {
				blank = TRUE;
				putchar(c);
			}
		}
		if (blank == TRUE) {
			if (c != ' ')
				blank = FALSE;
		}
	}
	return 0;
}
