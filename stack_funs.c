#include "main.h"
/**
 * op_add_value - adds a new node to the end of the stack
 *
 * @head: Pointer to last node in head
 * @op_value: Value well store for the fun to operate on
 *
 * Return: Pointer to last node
 * Description: Warning, only run this function after running
 * op_add_value! This will move the position of head to the
 * next node!
 */
instruction_a *op_add_value(instruction_a **head, const int op_value)
{
	instruction_a *new_node = malloc(sizeof(instruction_a));

	if (!new_node || !head)
		free(new_node);
	else
	{
		if (*head)
			(*head)->next = new_node;
		new_node->value = op_value;
		new_node->prev = (*head);
		new_node->next = NULL;
		(*head) = new_node;
	}
	return (new_node);
}

/**
 * op_add_instruction - adds a new node to the end of the stack
 *
 * @head: Pointer to last value in list
 * @op: index of the function to call
 *
 * Description: Warning, do not run this function two times
 * in a row!
 * It will not change the position of head!
 */
void *op_add_instruction(instruction_a **head, const int op)
{
        instruction_a *new_node = malloc(sizeof(instruction_a));

	if (!new_node || !head)
		free(new_node);
	{
		if (*head)
			(*head)->next = new_node;
		new_node->value = op;
		new_node->prev = (*head);
		new_node->next = NULL;
	}
}

/**
 * op_get_first - returns a pointer to the first node
 *
 * @head: Pointer to value>0 int list
 *
 * Return: Pointer to first node
 */
instruction_a *op_get_first(instruction_a **head)
{
	if (*head)
	{
		while ((*head)->prev)
			(*head) = (*head)->prev;
	}

	return (*head);
}
