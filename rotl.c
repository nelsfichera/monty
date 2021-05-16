#include "monty.h"
/**
* rotl -  Reverse all the data from stack
* @stack: pointer to head of stack
* @line_number: line number
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t **head = stack;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *last = NULL;
	(void)line_number;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	if ((*head)->next->next == NULL)
	{
		swap(stack, 0);
		return;
	}

	first = *head;
	second = (*head)->next;
	last = *head;

	while (last->next != NULL)
		last = last->next;

	first->next = last->next;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*head = second;
}
