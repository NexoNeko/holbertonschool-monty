#include "main.h"

/**
 * fun_push - A function that pushes a value into the stack
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * @value: value to operate with
 */
int fun_push(stack_t **stack, int line_number, int value)
{
	return(0);
}

/**
 * fun_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * @value: value to operate with
 */
int fun_pint(stack_t **stack, int line_number, int value)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		stack_errors(1, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * fun_pop - A function that remove the top value in the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * @value: value to operate with
 */
int fun_pop(stack_t **stack, int line_number, int value)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		stack_errors(2, line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*stack = tmp->tmp->next;
	free(tmp);
}

/**
 * fun_swap - A function that swaps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * @value: value to operate with
 */
int fun_swap(stack_t **stack, int line_number, int value)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(3, line number);
		exit(EXIT_FAILURE)
	}
	tmp = (*stack)->next->n;
	(*stak)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
 * fun_add - A function that adds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * @value: value to operate with
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
int fun_add(stack_t **stack, int line_number, int value)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		stack_errors(4, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	fun_pop(stack, line_number);
}
