#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 10

int main () {
	int c, state, w, wl, i, overword;
	int l1[MAX], l2[MAX], l3[MAX], l4[MAX], l5[MAX], overflow[MAX];

	for (i = 0; i < MAX; ++i)
		overflow[i] = 0;
	for (i = 0; i < MAX; ++i)
		l1[i] = ' ';
	for (i = 0; i < MAX; ++i)
		l2[i] = ' ';
	for (i = 0; i < MAX; ++i)
		l3[i] = ' ';
	for (i = 0; i < MAX; ++i)
		l4[i] = ' ';
	for (i = 0; i < MAX; ++i)
		l5[i] = ' ';

	state = OUT;
	w = overword = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				if (w <= MAX) {
					if (wl >= 1)
						l1[w] = '#';
					if (wl >= 2)
						l2[w] = '#';
					if (wl >= 3)
						l3[w] = '#';
					if (wl >= 4)
						l4[w] = '#';
					if (wl >= 5)
						l5[w] = '#';
					if (wl > 5)
						overflow[w] = wl - 5;
				}
				else
					overword = w - MAX;
				++w;
				wl = 0;
			}
		}
		else {
			state = IN;
			++wl;
		}
		if (c == '\n') {
			for (i = 0; i < MAX; ++i) {
				printf("%c ", l5[i]);
				l5[i] = ' ';
			}
			printf("\n");
			for (i = 0; i < MAX; ++i) {
				printf("%c ", l4[i]);
				l4[i] = ' ';
			}
			printf("\n");
			for (i = 0; i < MAX; ++i) {
				printf("%c ", l3[i]);
				l3[i] = ' ';
			}
			printf("\n");
			for (i = 0; i < MAX; ++i) {
				printf("%c ", l2[i]);
				l2[i] = ' ';
			}
			printf("\n");
			for (i = 0; i < MAX; ++i) {
				printf("%c ", l1[i]);
				l1[i] = ' ';
			}
			printf("\n0 1 2 3 4 5 6 7 8 9 (OVERFLOW WORDS: %d)\n", overword);
			for (i = 0; i < MAX; ++i) {
				printf("%d ", overflow[i]);
				overflow[i] = 0;
			}
			printf("(OVERFLOW LENGTH)\n");
			w = 0;
		}
	}
	return 0;
}






