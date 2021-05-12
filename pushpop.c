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
void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *n_node;

	if (!stack)
		return;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/* free_list(&stack); */
		exit(EXIT_FAILURE);
	}
		if (isdigit(n) != 0)
	{
		fprintf(stderr, "L%d: usage push integer\n", line_number);
		/* free_list(*stack); */
	}

	n_node->n = n;
	n_node->next = *stack;
	n_node->prev = NULL;

	if (*stack)
		(*stack)->prev = n_node;

	*stack = n_node;


	/** n_node->n = atoi(argv[1]);
	* if (info.type == LIFO)
	* add_node_lifo(stack, n_node);
	* else
	*	add_node_fifo(stack, n_node); */
}
