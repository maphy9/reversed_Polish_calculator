#include "getop.h"
#include "buffer.h"

int is_digit(char c) {
	return c >= '0' && c <= '9';
}

char getop(char* s) {
	char c;
	while ((*s = c = getch()) == ' ' || c == '\t');
	*(s + 1) = '\0';

	if (c == 's') {
		char c1 = getch();
		if (c1 == '\n') {
			ungetch(c1);
			return '?';
		}
		char c2 = getch();
		if (c1 == 'i' && c2 == 'n')
			return 's';
		return '?';
	}

	if (c == 'c') {
		char c1 = getch();
		if (c1 == '\n') {
			ungetch(c1);
			return '?';
		}
		char c2 = getch();
		if (c1 == 'o' && c2 == 's')
			return 'c';
		return '?';
	}

	if (c == 'e') {
		char c1 = getch();
		if (c1 == '\n') {
			ungetch(c1);
			return '?';
		}
		char c2 = getch();
		if (c1 == 'x' && c2 == 'p')
			return 'e';
		return '?';
	}

	if (c == 'p') {
		char c1 = getch();
		if (c1 == '\n') {
			ungetch(c1);
			return '?';
		}
		char c2 = getch();
		if (c1 == 'o' && c2 == 'w')
			return 'p';
		return '?';
	}

	if (!is_digit(c) && c != '.' && c != '-') {
		return c;
	}

	int i = 0;
	if (is_digit(c) || c == '-')
		while (is_digit(*(s + (++i)) = c = getch()));
	if (i == 1 && *s == '-') {
		ungetch(c);
		*(s + 1) = '\0';
		return '-';
	}
	if (c == '.')
		while (is_digit(*(s + (++i)) = c = getch()));

	*(s + i) = '\0';
	if (c != '\n')
		ungetch(c);
	return NUMBER;
}

