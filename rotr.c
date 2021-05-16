#include "monty.h"

/**
 * rotr - last element in the list becomes the first
 * @stack: head of the double linked list stack
 * @line_number: line count
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		for (; last->next; last = last->next)
			;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
