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
	struct instruction_a *head;

	/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	printf("entering main\n");
	if (argv[1])
		printf("argument passed: %s\n", argv[1]);
	else
		printf("arguments passed: none\n");
	/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	/** get the n of functions we have */
	opcode_fun_num = (sizeof(opcode) / sizeof(char *));
	/** if no argument is given, exit error */

	/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	printf("num of funs we expect: 6\nnum of funs we got: %d\n", op_fun_num);
	/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	printf("starting test for access R_OK...\n");
	/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	/** if can't access the file, exit error */
	if (argc < 1 || access(argv[1], R_OK) != 0)
		fun_exit(1);

	/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	printf("test passed!\n");
	/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	for (file_line = 0; file_buffer[file_line] != EOF; file_line++)
	{
		/** read the file stream */
		file_stream = open(argv[1], O_RDONLY);

		/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
		printf("\n>>Current file line: %d<<\n", file_line);
		printf("Attempted to open file, filestream: %d\n", file_stream);
		printf("attempting to read from file...\n");
		/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

		/** add an EOF to the end of file buffer for checking*/
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
			if (strcmp(*opcode, opcode_possible_command) == 0)
			{
				/** If you find the operation, save it to the op */
				op_add_instruction(&head, (const int)i);
				/** If op is push(1), handle the saving of push value */
				if (i == 1)
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
					/** save the values to the op as int*/
					i = atoi(op_command_buffer);
					op_add_value(&head, (const int)i);
				}
			}
	}

	return(0);
}

int fun_caller(const instruction_b *head)
{
	int op = head->opcode;
	int args = head->value;
	int (*opcode_fun[])(int) = {
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
