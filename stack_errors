#include "main.h"

/**
 * usage_error - A function that print usage error menssage.
 * @flag: Type a error 0 malloc filed or 1 usage.
 * Return: EXIT-FAILURE.
 */
int usage_error(int flag)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[flag]);
	return (EXIT_FAILURE);


/**
 * open_error - A function that print the errors.
 * @filename: Name of file failed to open.
 * Return: EXIT-FAILURE.
 */

int open_error(char *filename)

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);


/**
 * stack_errors - A function that print the errors.
 * @flag: The index to type the error.
 * @line_num: The number of line in file with error.
 * Return: EXIT_FAILURE
 */



int stack_errors(int flag, unsigned int line_num)
{
	char *errors[] = {"usage: push integer",
		"can\'t pint, stack empty stack empty",
		"can\'t pop an empty stack", "can't swap, stack too short",
		"can\'t add, stack too short"};
	fprintf(stderr, "L%d: %s\n", line_num, errors[flag]);
	return (EXIT_FAILURE);
}
