#include "main.h"

/**
 * fun_nop - Does nothing
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 *
 */
int fun_nop(stack_t **stack,  int value)
{
	if(*stack)
		if (value == 0)
			return(0);
	return(0);
}

/**
 * fun_pall - prints all the values on the stack, starting from the top
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 *
 */
int fun_pall(stack_t **stack,  int value)
{
	if(*stack)
		if (value == 0)
			return(0);
	return(0);
}

