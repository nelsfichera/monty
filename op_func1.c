#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
