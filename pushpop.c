#include "monty.h"
stack_t *stack = NULL;
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

void push(stack_t **head, int n)
{
	stack_t *pusher_node;
	/*add error handling here*/ 
	pusher_node = malloc(sizeof(stack_t));

	pusher_node->n = n;
	pusher_node->next = *head;
	pusher_node->prev = NULL;
	*head = pusher_node;
}

int nudge_push(char *opcode, char *push_data, unsigned int line_number)
{
	int push_num;

	if (strcmp("push", opcode) != 0)
		return (0);
	if (push_data)
	{
		push_num = atoi(push_data);
		if (push_num != 0 || strcmp(push_data, "0") == 0)
		{
			push(&stack, push_num);
			return (1);
		}
	}
	/* add error handling here*/
}
