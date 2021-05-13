#include "monty.h"

/**
 * pchar - prints the character at the top of the stack using ascii
 * @stack: header for the double linked list
 * @line_number: line count
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(h->n > 64 && h->n < 91) && !(h->n > 96 && h->n < 123))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)h->n);
}

/**
 * pstr - prints string at the top of the stack
 * @stack: header for the double linked list
 * @line_number: line count
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int i = 0;
	char str[1240];
	(void)line_number;

	memset(str, 0, 1240);
	if (!h)
		printf("\n");
	while (h)
	{
		if (!(h->n > 64 && h->n < 91) && !(h->n > 96 && h->n < 123))
		{
			break;
		}
		str[i] = (char)h->n;
		i++;
		h = h->next;
	}
	printf("%s\n", str);
}
