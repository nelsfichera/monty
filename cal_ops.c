#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		/* free the stack here? */
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	/* we can use pop function to remove first element: */
	/* pop(stack, line_number); */
	/* otherwise: */
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		/* free the stack here? */
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	/* we can use pop function to remove first element: */
	/* pop(stack, line_number); */
	/* otherwise: */
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div - divides the top two elements of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		/* free the stack here? */
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		/* free stack? */
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	/* we can use pop function to remove first element: */
	/* pop(stack, line_number); */
	/* otherwise: */
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		/* free the stack here? */
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	/* we can use pop function to remove first element: */
	/* pop(stack, line_number); */
	/* otherwise: */
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod - calculates the the rest of the division of
 * the top two elements of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		/* free the stack here? */
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		/* free stack? */
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	/* we can use pop function to remove first element: */
	/* pop(stack, line_number); */
	/* otherwise: */
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
