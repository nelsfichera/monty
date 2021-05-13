#include "monty.h"
/**
* pop -  removes the top element of the stack
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *popper = *stack;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		/* free_node(&stack); */
	}
	popper = popper->next;
	free(*stack);
	*stack = popper;
	if (popper != NULL)
		popper->prev = NULL;
}

/**
* push -  pushes an element into the bottom of the stack
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void push(stack_t **stack, unsigned int line_number, const char *n)
{
	if (!stack)
		return;

	if (isdigit(n) != 0)
	{
		fprintf(stderr, "L%d: usage push integer\n", line_number);
		/* free_list(*stack); */
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_dnodeint(stack, atoi(n)) == -1)
		{
			/* free */
			exit(EXIT_FAILURE);
		}
	}
}
