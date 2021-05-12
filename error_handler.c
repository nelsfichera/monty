#include "monty.h"
#include "nelsheadertemp.h"
void error_handler(int code)
{
	error_t err [] = {
		{1, fail_malloc},
		{2, fail_usage},
		{3, fail_permissions},
		{4, command_unknown},
		{5, push_error},
		{6, pint_error},
		{7, pop_error},
		{8, swap_error},
		{9, add_error},
		{10, sub_error},
		{11, mul_error},
		{12, div_error},
		{13, mod_error},
		{0, NULL}
	};

	int iter = 0;

	while ((err + iter)->error_code)
	{
		if ((err + iter)->error_code == code)
		{
			(err + iter)-> error_type();
			exit(EXIT_FAILURE);
		}
		iter++;
	}
}
