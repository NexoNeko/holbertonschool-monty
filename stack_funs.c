#include "main.h"
/**
 * stack_add - adds a new node to the begining of the stack
 *
 * @head: List to add a node to
 * @n: Value to store in the new node
 *
 * Return: Pointer to last node
 */
stack_d *stack_add(stack_d **head, const int n)
{
	stack_d *new_node = malloc(sizeof(stack_d));

	if (!new_node || !head)
		free(new_node);
	else
	{
		if (*head)
			(*head)->prev = new_node;
		new_node->n = n;
		new_node->next = (*head);
		(*head) = new_node;
	}
	return (new_node);
}
