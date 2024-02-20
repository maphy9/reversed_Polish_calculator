#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "getop.h"

#define SIZE	100

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
	char s[SIZE];

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
