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
	int i = 0, j = 0, c = 0, opcode_fun_num;
	char opcode_possible_command[POSSIBLE_BUFFER], op_command_buffer[COMMAND_BUFFER], file_line_counter = 0;
	int bol_test_A = 1, bol_test_B = 1, bol_test_C = 1, bol_test_D =1, bol_test_E = 1;
	FILE *file_stream;
	char *file_line = NULL;
	size_t file_lenght = 0;
	ssize_t file_line_read;
	instruction_b *head;

	head = NULL;
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	if (bol_test_A || bol_test_B || bol_test_C || bol_test_D || bol_test_E)
		printf("starting tests...");

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
	printf("num of funs we expect: 7(6)\nnum of funs we got: %d\n", opcode_fun_num);
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

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
		printf("Attempted to open file, filestream...\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
	/** read the file stream */
	file_stream = fopen(argv[1], "r");
	if (!file_stream)
		perror("failed to read file stream: ");

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
	printf("file open!\n");

	printf("\n\n=======================================================\n\n");
	printf("\nentering loop...\n");
	printf("\n\n=======================================================\n\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

	while((file_line_read = getline(&file_line, &file_lenght, file_stream)) != -1)
	{
		file_line_counter++;
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
		printf("\n>>Current file line: %d<<\n", file_line_counter);
		printf("Attempted to open file, filestream...\n");
		printf("attempting to read from file...\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/


/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
		if (bol_test_A)
		{
			printf("Success?\n");
			printf("%s\n", file_line);
			bol_test_A = 0;
			printf("\nAttempting to enter nested loop...\n");
		}
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

		/** Save all but spaces to an array to check for commands */
		for(i = 0; (i <= (int)file_lenght) && (file_line[i] != '\0'); i++)
		{

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
			printf("Looping!\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

			if (MINUS(file_line[i]))
			{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("\nValue found!\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
				for (j = 0; j < POSSIBLE_BUFFER; j++)
					opcode_possible_command[j] = '\0';

				j = i;
				for(j--; MINUS(file_line[j]); )
				{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("\nWAIT\n");
				printf("Previous value is a char!");
				printf("\nValue: %c\n", file_line[j]);
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
					i--;
					j--;
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
					printf("\nCorrected!\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
				}

				for(j = 0; (MINUS(file_line[i])) && (j <= (int)file_lenght); i++)
				{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
					printf("\nEntering inner loop...! \n file_line[%d] = %c\n", i, file_line[i]);
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
						opcode_possible_command[j] = file_line[i];
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				  printf("\nStatus: opcode_p_c[%d] = %c\n", j, opcode_possible_command[j]);
				  getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
				  j++;
				}
				break;
			}
			else
				i++;
		}
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
printf("\nExiting nested loop...!\n");
printf("op_possible_command: %s\n", opcode_possible_command);
getchar();
printf("\nby now we should either enter or fail to enter strcmp\n");
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

		for(i = 0; (i < opcode_fun_num); i++)
		{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("Trying to enter strcmp...\n");
				printf("opcode[i] = %s[%d]...\n", opcode[i], i);
				printf("possible command: %s\n", opcode_possible_command);
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
			if (strcmp(opcode[i], opcode_possible_command) == 0)
			{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("entered strcmp!\n");
				printf("i = %d\n", i);
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

				/** If you find the operation, save it to the op */
				if (i >= 0)
				{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("i is valid!! \n");
				printf("val of i: %d", i);
				printf("Writing...!\n");
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
					op_add_instruction(&head, i);
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
					printf("!! Remember to add the exit here\n");
				printf("Success? => ");

				if (head)
					printf("head instruct: %d\n", head->opcode);
				else
					printf("Nope!\n");
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
					/** If op is push|0|, handle the saving of push value */
				}
				if (i == 0)
				{
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("i is equal to 0! (push) ");
				printf("Checking if file_line[i] is valid: %d[%d]", file_line[i], i),
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
					if (!file_line[i])
						fun_exit(3);
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("test passed! ");
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
					for(; (i < COMMAND_BUFFER) && (file_line[i] != '\0'); i++)
					{
						if (file_line[i] != ' ')
						{
							for(c = 0; (file_line[i] != ' ') && (c <= COMMAND_BUFFER); i++)
							{
								op_command_buffer[c++] = file_line[i];
								i++;
								if (MINUS(file_line[(i)])) /* fix this */
									printf("L<line_number>: usage: push integer");
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
/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
				printf("Exiting strcmp\n");
				getchar();
/**<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
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
