#include "main.h"

/**
 * fun_push - A function that pushes a value into the stack
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 */
int fun_push(stack_t **stack,  int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if(!new_node)
		return(4);
	new_node->n = value;
	new_node->next = (*stack);
	new_node->prev = NULL;
	(*stack)->prev = new_node;

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

	(void)value;
	if (!tmp)
		return(6);
	while(tmp->next != NULL)
		tmp = tmp->next;
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

	(void)value;
	if (!tmp)
		return(7);

	while(tmp->next->next != NULL)
		tmp = tmp->next;
	(*stack) = tmp;
	tmp = tmp->next;
	(*stack)->next = NULL;
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
	stack_t *tmp = *stack;

	(void)value;
	if (*stack == NULL || (*stack)->next == NULL)
		return(8);
	/** find last node */
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	/**set initial values, Stack = penultimate, tmp = last */
	(*stack) = tmp;
	tmp = tmp->next;
	/** tmp is gonna become penultimate */
	/** so tmp-> prev must be penultimate's */
	tmp->prev = (*stack)->prev;
	/** stack is gonna become last */
	/** so stack prev points to penultimate*/
	/** tmp->next points to last value */
	(*stack)->prev = tmp;
	tmp->next = *stack;
	/** the value before penultimate is pointing to last */
	/** we correct this here, we also set last next to NULL */
	tmp->prev->next = tmp;
	(*stack)->next = NULL;
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
	stack_t *tmp = *stack;

	(void)value;
	if (*stack == NULL || (*stack)->next == NULL)
		return(9);
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	*stack = tmp;
	tmp = tmp->next;
	(*stack)->n += tmp->n;
	fun_pop(&tmp, 0);
	return(0);
}
