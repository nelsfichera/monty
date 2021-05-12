#include "monty.h"

void free_node(void)
{
	free(info.cmd);
	info.cmd = NULL;
	free(info.arg);
	info.arg = NULL;
	fclose(info.fp);
}
void free_list(stack_t *stack)
{
	stack_t *node;

	while(stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
