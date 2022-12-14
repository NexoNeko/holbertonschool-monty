#include "main.h"
/*
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
