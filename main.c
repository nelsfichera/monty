#include "monty.h"
/**
* main - opens files, tokenizes input, creates commands
* @argc: number of args
* @argv: string of args
* Return: exit success or failure
*/
int main(int argc, char **argv)
{
	FILE *fptr;
	char *token[] = {NULL, NULL, NULL};
	char *line = NULL;
	size_t buffsize;
	unsigned int line_count = 1;
	char *file_path;
	int line_value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_path = argv[1];
	fptr = fopen(file_path, "r");
	if (!fptr)
	{
		printf("Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	line_value = getline(&line, &buffsize, fptr);
	while (line_value != -1)
	{
		token[0] = strtok(line, "\n\t\a\r ");
		token[1] = strtok(NULL, "\n\t\a\r ");
		get_func(token, line_count);
		line_count++;
		line_value = getline(&line, &buffsize, fptr);
	}
	return (EXIT_SUCCESS);
}
