#include "monty.h"

/**
 * find_op_func - finds the correct function from opcode
 * @token: opcode token
 * Return: pointer to the correct operator function, otherwise NULL
 */
void (*find_op_func(char *token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	/* using instruction_t struct to match opcode to function */
	instruction_t cmd[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		/*{"swap", swap},*/
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

	while (cmd[i].opcode)
	{
		if (strcmp(token, cmd[i].opcode) == 0)
			return (cmd[i].f);
		i++;
	}
	return (NULL);
}
