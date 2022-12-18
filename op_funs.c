#include "monty.h"
/**
 * op_add_value - adds a new node to the end of the stack
 *
 * @head: Pointer to last node in head
 * @op_value: Value well store for the fun to operate on
 *
 * Return: 0 on success, 5 on failure
 * Description: Warning, only run this function after running
 * op_add_instruction! This will move the position of head to the
 * next node!
 */
int op_add_value(instruction_b **head, const int op_value)
{
	if (*head)
		(*head)->value = op_value;
	else
		return(4);
	return (0);
}

/**
 * op_add_instruction - adds a new node to the end of the stack
 *
 * @head: Pointer to last value in list
 * @op: index of the function to call
 *
 * Return: 0 on success, 5 on failure
 * Description: Warning, do not run this function two times
 * in a row!
 * It will not change the position of head!
 */
int op_add_instruction(instruction_b **head, const int op)
{
        instruction_b *new_node = malloc(sizeof(instruction_b));

	if (!new_node)
		return(4);
	new_node->opcode = op;
	if (*head)
	{
		(*head)->next = new_node;
		new_node->prev = (*head);
	}
	else
		new_node->prev = NULL;
	(*head) = new_node;
	new_node->next = NULL;
	return(0);
}

/**
 * op_get_first - returns a pointer to the first node
 *
 * @head: Pointer to value>0 int list
 *
 * Return: Pointer to first node
 */
instruction_b *op_get_first(instruction_b **head)
{
	if (*head)
	{
		while ((*head)->prev)
			(*head) = (*head)->prev;
	}

	return (*head);
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
