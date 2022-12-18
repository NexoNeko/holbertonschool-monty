#include "main.h"

int fun_exit(int value, int arg_num, ...)
{
	va_list error_info;
	int line;
	char *text;
	instruction_b *head = NULL;
	stack_t *stack = NULL;

	va_start(error_info, arg_num);

	switch (value)
	{
	case 1: /** If no file or no arguments*/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
		break;
	case 2: /** Not possible to open the file */
		text = va_arg(error_info, char*);
		fprintf(stderr, "Error: Can't open file %s\n", text);
		exit(EXIT_FAILURE);
		break;
	case 3: /** File contains an invalid instruction */
		line = va_arg(error_info, int);
		text = va_arg(error_info, char*);
		fprintf(stderr, "L%d: unknown instruction %s\n", line, text);
		break;
	case 4: /** malloc failed */
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5: /** push: int not integer or no arguments */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: usage: push integer\n", line);
		break;
	case 6: /** pint: If the stack is empty */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
		break;
	case 7: /** pop: If the stack is empty */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
		break;
	case 8: /** swap: If the stack contains less than two elements */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		break;
	case 9: /** add: If the stack contains less than two elements */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		break;
	case 10: /** free */
		break;
	default:
		va_end(error_info);
		return(0);
		break;

	}
        *head = va_arg(error_info, instruction_b);
	*stack = va_arg(error_info, stack_t);

	free_ophead(head);
	free_stack(stack);

	va_end(error_info);
	exit(EXIT_FAILURE);
}

int free_ophead(instruction_b *head)
{
	if (head)
		while(head->prev)
			head = head->prev;
	else
		return(0);
	free_ophead(head->next);
	free(head);
	return (0);
}

int free_stack(stack_t *stack)
{
	if (stack)
	{
		free_stack(stack->next);
		free(stack);
	}
		return (0);
}
