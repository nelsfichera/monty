#include "monty.h"

/**
 * dlistint_len - find the number of elements in a linked dlistint_t list
 * @h: header of the dlistint_t list
 * Return: number of elements in the list
 */

size_t dlistint_len(const stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}

/**
* pall - prints every value in the stack
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	(void)line_number;

	for (node = *stack; node; node = node->next)
		fprintf(stdout, "%d\n", node->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of the doubly linked list
 * @line_number: line count
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
* swap - swaps two top elements
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int check;
	stack_t *index0, *index1;

	check = dlistint_len(h);

	if (check < 2)
	{
		fprintf(stderr, "L:%d: Stack too short to swap\n", line_number);
		free_stack(*stack);
	}

	index0 = *stack;
	index1 = h->next;
	index0->next = index1->next;
	index0->prev = index1;

	if (index1->next)
		index1->next->prev = index0;

	index1->next = index0;
	index1->prev = NULL;
	(*stack) = index1;
}

/**
* nop - does nothing
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
