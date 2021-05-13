#include "monty.h"

/**
 * free_node - frees a node
 * @stack: header to the dlist
 */
void free_node(stack_t **stack)
{
	free(stack);
}

/**
 * free_list - frees a dlist
 * @stack: header to the dlist
 */
void free_list(stack_t **stack)
{
	stack_t *hcopy;
	stack_t *temp;

	if (*stack)
	{
		hcopy = *stack;
		*stack = NULL;

		while (hcopy->next)
		{
			temp = hcopy;
			hcopy = hcopy->next;
			free(temp);
		}
		free(hcopy);
	}
}
