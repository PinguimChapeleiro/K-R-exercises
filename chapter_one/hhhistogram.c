#include <stdio.h>

#define PMIN 33  /* min printable character in ASCII table */
#define PMAX 126 /* max printable character in ASCII table */
#define AL 93	 /* Array Length */

int main () {
	int c, i, ii;
	int repeat[AL];

/*	printable = PMIN; */

	for (i = 0; i < AL; ++i) {
/*		characters[i] = printable;
		++printable; */
		repeat[i] = '0';
	}

	while ((c = getchar()) != EOF) {
		if (c >= PMIN && c <= PMAX) {
			i = c - PMIN;
			++repeat[i];
		}
		else if (c == '\n') {
			for (i = 0; i < AL; ++i) {
				if (repeat[i] != '0') {
					printf("%c|", i + PMIN);
					for (ii = 0; ii < (repeat[i] - '0'); ++ii)
						printf("=");
					printf("\n");
					repeat[i] = '0';
				}
			}
		}
	}
	return 0;
}
