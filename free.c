#include "monty.h"

void free_list(stack_t **head)
{
	stack_t *hcopy;
	stack_t *temp;

	if (*head)
	{
		hcopy = *head;
		*head = NULL;

		while(hcopy->next)
		{
			temp = hcopy;
			hcopy = hcopy->next;
			free(temp);
		}
		free(hcopy);
	}
}
