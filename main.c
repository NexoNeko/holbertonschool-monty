#include "monty.h"
/**
 * this is just a variable holding possible functions
 * update this one if you want more functions
 * Remember to update fun caller with the address
 * of the new function too.
 */
char *opcode[] = {
	"push",
	"pall",
	"pint",
	"pop",
	"swap",
	"add",
	"nop"
};

/**
 * main - entry point for the program
 *
 * @argc: argument counter
 * @argv: file path
 *
 */
int main(int argc, char **argv)
{
	int i = 0, j = 0, c = 0, opcode_fun_num, file_line_counter = 0;
	size_t file_lenght = 0;
	ssize_t file_line_read;
	char opcode_possible_command[POSSIBLE_BUFFER], op_command_buffer[COMMAND_BUFFER];
	char *file_line;
	FILE *file_stream;
	instruction_b *head;
	stack_t *stack;

	(void)argc;
	/** initialize head of op instructions*/
	head = NULL;
	stack = NULL;

	/** initialize stack */
	stack = malloc(sizeof(stack_t));
	if (!stack)
		fun_exit(4, 2, &head, &stack);
	stack->n = 42;
	stack->next = NULL;
	stack->prev = NULL;

	/** get the n of functions we have */
	opcode_fun_num = (sizeof(opcode) / sizeof(char *));
	/** if no argument is given, exit error */

	/** if can't access the file, exit error */
	if (!argv[1])
	{
		fun_exit(1, 2, &head, &stack);
	}
	else if (access(argv[1], R_OK) != 0)
	{
		fun_exit(2, 3, argv[1], &head, &stack);
	}

	/** read the file stream */
	file_stream = fopen(argv[1], "r");
	if (!file_stream)
	{
		fun_exit(2, 3, argv[1], &head, &stack);
	}

	while((file_line_read = getline(&file_line, &file_lenght, file_stream)) != -1)
	{
		file_line_counter++;
		/** Save all but spaces to an array to check for commands */
		for(i = 0; (i <= (int)file_lenght) && (file_line[i] != '\0'); i++)
		{
			if (MINUS(file_line[i]))
			{
				for (j = 0; j < POSSIBLE_BUFFER; j++)
					opcode_possible_command[j] = '\0';

				j = i;
				if (j > 0)
					for(j--; MINUS(file_line[j]); )
					{
						i--;
						j--;
					}

				for(j = 0; (MINUS(file_line[i])) && (j <= (int)file_lenght); i++)
				{
						opcode_possible_command[j] = file_line[i];
				  j++;
				}
				c = i;
				break;
			}
			else
				i++;
		}

		for(i = 0; (i < opcode_fun_num); i++)
		{
			if (strcmp(opcode[i], opcode_possible_command) == 0)
			{

				/** If you find the operation, save it to the op */
				if (i >= 0)
				{
					fun_exit(op_add_instruction(&head, i), 3, &head, &stack, file_line);
					/** If op is push|0|, handle the saving of push value */
				}
				if (i == 0)
				{
					i = --c;
					if (file_line_content_check((int)file_line[i]) == 0)
						fun_exit(5, 4, file_line_counter, &head, &stack, file_line);

					for (c = 0; c < COMMAND_BUFFER; c++)
					op_command_buffer[c] = '\0';
					c = 0;

					for(; file_line[i] != '\0' && file_line[i] != '\n'; i++)
					{
						if (DIGIT(file_line[i]))
						{
							for(c = 0; c < COMMAND_BUFFER && file_line[i] != '\0'; )
							{
								if (file_line_content_check((int)file_line[i]) != 0 && !DIGIT(file_line[i]))
								{
									fun_exit(5, 4, file_line_counter, &head, &stack, file_line);
								}
								op_command_buffer[c] = file_line[i];
								i++;
								c++;
							}
						}
					}
					if (!op_command_buffer[0])
						fun_exit(5, 4, file_line_counter, &head, &stack, file_line);
					/** save the values to the op as int */
					    i = atoi(op_command_buffer);
				fun_exit(op_add_value(&head, (const int)i), 2, &head, &stack);
				}
				break;
			}
			else if ((i + 1) == opcode_fun_num)
				fun_exit(3, 5, file_line_counter, opcode_possible_command, &head, &stack);
		}
	}
	while(head->prev != NULL)
		head = head->prev;
	while(stack->prev != NULL)
		stack = stack->prev;
	free (file_line);

	while(1)
	{
		fun_exit(fun_caller(head, &stack), 2, &head, &stack);
		head = head->next;
		if (!head)
			break;
	}
	return(0);
}

int fun_caller(const instruction_b *head, stack_t **stack)
{
	int op = head->opcode;
	int args = head->value;
	int (*opcode_fun[])(stack_t **, int) = {
 		&fun_push,
		&fun_pall,
		&fun_pint,
		&fun_pop,
		&fun_swap,
		&fun_add,
		&fun_nop
	};
	return((opcode_fun[op])(stack, args));
}

int file_line_content_check(int file_line_char)
{
	switch (file_line_char)
	{
		case 00: /** NULL */
			return(0);
			break;
		case 03:/** end of text */
			return (0);
			break;
		case 9: /** horizontal tab*/
			return(0);
			break;
		case 10: /** line feed*/
			return(0);
			break;
		case 32: /** space */
			return(0);
			break;
		default:
			return(4);
			break;
	}
}
