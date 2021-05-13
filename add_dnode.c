#include "monty.h"

/**
 * add_dnodeint - adds a new node at the begining of a dlistint_t list
 * @head: pointer to the head of the list
 * @n: numberic value to add to the list
 * Return: 0 if success, otherwise -1 if failed
 */

int add_dnodeint(stack_t **head, int n)
{
	stack_t *new_node;

	if (!head)
		return (-1);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (0);
}
