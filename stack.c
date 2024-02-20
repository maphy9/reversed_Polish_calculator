#include <stdio.h>
#include "stack.h"

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

