#include "monty.h"
#include "nelstempheader.h"
info_t info;

int coordination(char *filename)
{
	ssize_t x = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	info.fn = filename;
	info.fp = fopen(info.fn, "r");
	if (info.fp == NULL)
		error_handler(3);
	while ((x = getline(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_number++;
		free(info.arg);
		if (split() < 0)
			continue;
		if (info.arg == NULL)
			continue;
		executer(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}

NEEDS TO BE COORDINATED!!!!!!!!
