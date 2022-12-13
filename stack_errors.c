#include "main.h"

/**
 * stack_errors - A function that print the errors.
 * @flag: The index to type the error.
 * @line_num: The number of line in file with error.
 * Return: EXIT_FAILURE
 */

Int stack_errors (int flag, unsigned int line_num)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty stack empty",
		"can\'t pop an empty stack", "can't swap, stack too short", "can\'t add, stack too short"};
	fprintf(stderr, "L%d: %s\n", line_num, errors[flag]);
	return (EXIT_FAILURE);
}

