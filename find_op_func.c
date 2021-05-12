#include "monty.h"

/**
 * find_op_func - finds the correct function from opcode
 * @token: opcode token
 * Return: pointer to the correct operator function, otherwise NULL
 */
int find_op_func(stack_t **stack, unsigned int line_number)
{
	/* using instruction_t struct to match opcode to function */
	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		/** {"pchar", pchar},
		* {"pstr", pstr},
		* {"rotl", rotl},
		* {"rotr", rotr}, */
		{NULL, NULL}
	};
	int i = 0;

	while ((command + i)->opcode)
	{
		if (strcmp((command + i)->opcode, **argv) == 0)
		{
			(command + i)->f(stack, line_number);
			return (0);
		i++;
	}
	return (1); 
	/*needs error handler*/

}
