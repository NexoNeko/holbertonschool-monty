#include "main.h"

/**
 * fun_nop - Does nothing
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * @value: value to operate with
 *
 */
int fun_nop(stack_t **stack, int line_number, int value)
{
	if(*stack)
		if(line_number = 0)
			if (value = 0)
				return(0);
	return(0);
}

/**
 * stack_free - A function that frees the memory allocated for stack.
 * @stack: Pointer to the doubly linked list rpresentation of the stack.
 * Return: Nothing.
 */
void stack_free(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
