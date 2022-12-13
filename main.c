#include "main.h"
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
 *
 *
 *
 */
int main(int argc, char **argv)
{
	int i, j, c, file_line, file_stream, opcode_fun_num;
	char file_buffer[POSSIBLE_BUFFER], opcode_possible_command[POSSIBLE_BUFFER], op_command_buffer[COMMAND_BUFFER];
	stack_d *head;

	/** get the n of functions we have */
	opcode_fun_num = (sizeof(opcode) / sizeof(char *));
	/** if no argument is given, exit error */
	/** if can't access the file, exit error */
	if (argc < 1 || access(R_OK, *argv) != 0)
		fun_exit(1);

	for (file_line = 0; file_stream[file_line] != EOF; file_line++)
	{
		/** read the file stream */
		file_stream = open(argv, O_RDONLY);
		read(file_stream, (char *)file_buffer, POSSIBLE_BUFFER);
		/** Save all but spaces to an array to check for commands */
		for(i = 0; (i <= POSSIBLE_BUFFER) && (file_buffer[i] != '\0'); i++)
		{
			if (file_buffer[i] != ' ')
			{
				for(j = 0; (file_buffer[i] != ' ') && (j <= POSSIBLE_BUFFER); i++)
					opcode_possible_command[j++] = file_buffer[i];
				break;
			}
			else
				i++;
		}
		for(j = 0; (j <= opcode_fun_num); j++)
			if (strcmp(opcode[j], opcode_possible_command) == 0)
			{
				stack_d->opcode = i;
				if (opcode[j] == "push")
				{
					if (!file_buffer[i])
						fun_exit(3);
					for(; (i <= COMMAND_BUFFER) && (file_buffer[i] != '\0'); i++)
					{
						if (file_buffer[i] != ' ')
						{
							for(c = 0; (file_buffer[i] != ' ') && (c <= COMMAND_BUFFER); i++)
							{
								op_command_buffer[c++] = file_buffer[i];
								if (file_buffer[i] == '\0' || file_buffer[i] == ' ')
									break;
							}
						}
						else
							i++;
						if (c > 0)
						{
							op_command_buffer[++c] = '\0';
							break;
						}
					}
					/** send this to the fun as the input */
					/** stack_d->value = atoi(op_command_buffer); */
					/**head next goes here */
					stack_add(&head, const int);
				}
			}
	}

	return(0);
}

int fun_caller(void)
{
	char *op = instruction_t->opcode;
	int *args = stack_t->n;
	int (*opcode_fun[])(int *) = {
		&fun_push,
		&fun_pall,
		&fun_pint,
		&fun_pop,
		&fun_swap,
		&fun_add,
		&fun_nop
	};

	return((opcode_fun[op])(args));
}
