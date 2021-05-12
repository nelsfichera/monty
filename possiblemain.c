#include "monty.h"
#include "nelsheadertemp.h"

int main(int argc, char **argv)
{
	info.type = LIFO;
	if (argc != 2)
		error_handler(2);
	else
		coordination(argv[1]);
	return (EXIT_SUCCESS);
}
