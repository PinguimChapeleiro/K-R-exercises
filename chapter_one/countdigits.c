#include <stdio.h>

int main () {
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;

	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 48 && c <= 57)
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else
			++nother;
	}

	printf("Digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}









