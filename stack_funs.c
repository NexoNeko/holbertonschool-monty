#include "main.h"

/**
 * fun_push - A function that pushes a value into the stack
 * @stack: The pointer to the stack list.
 * @value: value to operate with
 */
int fun_push(stack_t **stack,  int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

/**>>>>*/
	printf("pushnig %d", value);
	getchar();
/**<<<<<*/
	if (!new_node)
		return(4);
	if ((*stack)->next == NULL && (*stack)->n == INIT_VAL)
	{
		(*stack)->n = value;
		free(new_node);
	}
	else
	{
	new_node->n = value;
	new_node->next = (*stack);
	new_node->prev = NULL;
	(*stack)->prev = new_node;
	*stack = new_node;
	}
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

/**>>>>*/
	printf("pintin top value from stack");
	getchar();
/**<<<<<*/
	(void)value;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
		return(6);
	while(tmp->prev != NULL)
		tmp = tmp->prev;
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

/**>>>>*/
	printf("poppin");
	getchar();
/**<<<<<*/
	(void)value;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
		return(7);

	while(tmp->prev != NULL)
		tmp = tmp->prev;
	(*stack) = tmp->next;
	(*stack)->prev = NULL;
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

/**>>>>*/
	printf("swapping the two top values\n");
	getchar();
/**<<<<<*/
	(void)value;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
		return(8);
	/** find last node */
	while(tmp->prev != NULL)
		tmp = tmp->prev;
	/**set initial values, Stack = penultimate, tmp = last */
	tmp = tmp->next;
	(*stack) = tmp;
	tmp = tmp->prev;
	/** tmp is gonna become penultimate */
	/** so tmp-> prev must be penultimate's */
	tmp->next = (*stack)->next;
	/** stack is gonna become last */
	/** so stack prev points to penultimate*/
	/** tmp->next points to last value */
	(*stack)->next = tmp;
	tmp->prev = *stack;
	/** the value before penultimate is pointing to last */
	/** we correct this here, we also set last next to NULL */
	tmp->next->prev = tmp;
	(*stack)->prev = NULL;
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
	int a, b;
/**>>>>*/
	printf("adding the two top values");
	getchar();
/**<<<<<*/
	(void)value;
	if ((*stack)->next == NULL && (*stack)->prev == NULL)
		return(9);
	while(tmp->prev != NULL)
		tmp = tmp->prev;
	*stack = tmp->next;
		a = (*stack)->n;
		b = tmp->n;
		a += b;
		(*stack)->n = a;
	fun_pop(&tmp, 0);
	while((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	return(0);
}
