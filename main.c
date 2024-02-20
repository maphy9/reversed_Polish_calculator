#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH	100
#define NUMBER 	'0'

char getop(char* s);
void push(double x);
double pop();
void clear();
void swap();
void duplicate();
void print_top();

int main() {
	char type;
	double x1;
	char s[LENGTH];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				x1 = pop();
				push(pop() - x1);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				x1 = pop();
				if (x1 == 0.0) {
					printf("Error: division by 0\n");
					break;
				}
				push(pop() / x1);
				break;
			case '%':
				x1 = pop();
				if ((int) x1 == 0) {
					printf("Error: division by 0\n");
					break;
				}
				push((int) pop() % (int) x1);
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'c':
				push(cos(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '!':
				print_top();
				break;
			case '~':
				swap();
				break;
			case '&':
				duplicate();
				break;
			case '@':
				clear();
				break;
			case 'p':
				x1 = pop();
				push(pow(pop(), x1));
				break;
			case '\n':
				printf("%.8lf\n", pop());
				break;
			default:
				printf("Error: unknown operator\n");
				break;
		}
	}

	return 0;
}


// stack
int stack_pos = 0;
double stack[LENGTH];

void push(double x) {
	if (stack_pos == LENGTH)
		printf("Error: stack is full\n");
	else
		stack[stack_pos++] = x;
}

double pop() {
	if (stack_pos == 0) {
		printf("Error: stack is empty\n");
		return 0.0;
	}

	return stack[--stack_pos];
}

void clear() {
	stack_pos = 0;
}

void swap() {
	if (stack_pos == 0)
		printf("Error: stack is empty\n");
	else if (stack_pos == 1)
		printf("Error: too few elements in the stack\n");
	else {
		double temp = stack[stack_pos - 1];
		stack[stack_pos - 1] = stack[stack_pos - 2];
		stack[stack_pos - 2] = temp;
	}
}

void duplicate() {
	if (stack_pos == 0)
		printf("Error: stack is empty\n");
	else if (stack_pos == LENGTH)
		printf("Error: stack is full\n");
	else {
		stack[stack_pos] = stack[stack_pos - 1];
		stack_pos++;
	}
}

void print_top() {
	if (stack_pos == 0)
		printf("Error: stack is empty\n");
	else
		printf("%lf\n", stack[stack_pos - 1]);
}


// get operator
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
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
