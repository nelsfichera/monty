#include "monty.h"

/**
 * find_op_func - finds the correct function from opcode
 * @token: opcode token
 * Return: pointer to the correct operator function, otherwise NULL
 */
void (*find_op_func(char **token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	/* using instruction_t struct to match opcode to function */
	instruction_t instruction_s[] = {
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

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
