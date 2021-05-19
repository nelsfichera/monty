#include "monty.h"

/**
 * free_stack - frees a dlist
 * @head: header to the dlist
 */
void free_stack(stack_t *head)
{
	stack_t *node_x;
	stack_t *next;

	for (node_x = head; node_x; node_x = next)
	{
		next = node_x->next;
		free(node_x);
	}
}
/**
* free_all - frees everything
* @buff_addy: buffer from getline()
* @bytecode_file: open bytecode file
*/
void free_all(char **buff_addy, FILE **bytecode_file)
{
	static char **line;
	static FILE **bytecode;

	if (buff_addy || bytecode_file)
	{
		line = buff_addy ? buff_addy : line;
		bytecode = bytecode_file ? bytecode_file : bytecode;
		return;
	}
	fclose(*bytecode);
	free(*line);
	free_stack(stack);
}
