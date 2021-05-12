#include "monty.h"

int main(int argc, char **argv[])
{
	int fd, is_push = 0;
	char *buffer, *token;
	ssize_t file_data;
	unsigned int line_count = 1;
	stack_t *h = NULL;

	if (argc != 2)
	{
		/* usage error and exit */
	}
	fd = open(argv[1], O_RDONLY); /* open with fd */
	if (fd == -1)
	{
		/* can't open error and exit */
	}
	buffer = malloc(sizeof(char) * 10240);
	if (!buffer) /* buffer for reading file */
		return (0);
	file_data = read(fd, buffer, 10240);
	if (file_data == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	/* token time */
	token = strtok(buffer, "\n\t\a\r ");
	while (token != NULL)
	{
		if (is_push == 1) /* if cmd is push: because needs 3 inputs */
		{
			push(&h, line_count, token);
			is_push = 0;
			token = strtok(NULL, "\n\t\a\r ");
			line_count++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			is_push = 1;
			token = strtok(NULL, "\n\t\a\r ");
			continue;
		}
		else /* use find operator func to check for matching cmd */
		{
			if (find_op_func(token) != 0)
			{
				find_op_func(token)(&h, line_count);
			}
			else
			{
				/* free dlist */
				/* print unknown instruction error */
				/* exit */
			}
		}
		line_count++;
		token = strtok(NULL, "\n\t\a\r ");
	}
	/* free dlist and free buffer */
	close(fd);
	return (0);
}
