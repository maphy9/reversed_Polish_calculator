#include "buffer.h"
#include <stdio.h>

#define BUFSIZE	100

char buf[BUFSIZE];
int buf_pos = 0;

int getch() {
	return buf_pos == 0 ? getchar() : buf[--buf_pos];
}

void ungetch(char c) {
	if (buf_pos == BUFSIZE)
		printf("Error: buffer is full\n");
	else
		buf[buf_pos++] = c;
}

