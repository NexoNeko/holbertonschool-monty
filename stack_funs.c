#include "main.h"

/**
 * fun_push - A function that pushes a value into the stack
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 */
int fun_push(stack_t **stack,  int value)
{
	if(*stack)
		if (value == 0)
			return(0);
	return(0);
}

/**
 * fun_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 */
int fun_pint(stack_t **stack,  int value)
{
	stack_t *tmp = *stack;

	if (!tmp)
		return(6);
	printf("%d\n", tmp->n);
	return(0);
}

/**
 * fun_pop - A function that remove the top value in the stack.
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 */
int fun_pop(stack_t **stack,  int value)
{
	stack_t *tmp = *stack;

	if (!tmp)
		return(7);

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);
	return(0);
}

/**
 * fun_swap - A function that swaps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @value: value to operate with
 */
int fun_swap(stack_t **stack, int value)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return(8);
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
	return(0);
}

/**
 * fun_add - A function that adds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
int fun_add(stack_t **stack, int value)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return(9);
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	fun_pop(stack, 0);
	return(0);
}
