#include "monty.h"

/**
* pall - prints every value in the stack
* @stack: head of the doubly linked list
* @line_number: line count
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{ 
	/*needs error handling*/
	int iter;
	stack_t *node;
	(void)line_number;

	node = *stack;

	for (iter = 0; node; iter++)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}

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
		fprintf(stderr, "L:%d: Stack too short to swap\n", info.l_number);
		free_info();
	}
	
	index0 = head;
	index1 = head->next;
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
