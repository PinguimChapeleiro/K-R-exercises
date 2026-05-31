#include <stdio.h>

/* Write a program to print a histogram of the lengths of words in its input. It is */
/* easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/

/* first part: separate words (done) */
/* second part: make a count of words (done) */
/* third parte: make a count of characters in every word */
/* fourth part: store it in an array */

#define IN 1
#define OUT 0
#define MAX 10 /* max length of array/histogram */

int main () {
	int c, state, w, wl, i;
	int l1[MAX];

	for (i = 0; i < MAX; ++i)
		l1[i] = ' ';

	state = OUT;
	w = wl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				for (i = 0; i < wl; ++i)
					l1[i] = '=';

				for (i = 0; i < MAX; ++i)
					printf("%c ", l1[i]);
				if (wl > MAX)
					printf("+%d", wl - MAX);
				printf("\n");
				++w;
				wl = 0;
				for (i = 0; i < MAX; ++i)
					l1[i] = ' ';
				state = OUT;
			}
		}
		else {
			state = IN;
			++wl;
		}
	}
	return 0;
}

