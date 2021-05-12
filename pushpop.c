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

	/*if (*stack == NULL)
	  * handle error*/
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
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	void(line_number);

	n_node = malloc(sizeof(stack_t));
	/*if (n_node == NULL 
	  * handle error*/
	n_node->n = atoi(info.arg[1]);
	if (info.type == LIFO)
		add_node_lifo(stack, n_node);
	else
		add_node_fifo(stack, n_node);
}
