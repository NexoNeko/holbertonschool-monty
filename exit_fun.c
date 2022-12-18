#include "main.h"

int fun_exit(int value, int arg_num, ...)
{
	va_list error_info;
	int line;
	char *text;

	va_start(error_info, arg_num);

	switch (value)
	{
	case 1: /** If no file or no arguments*/
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2: /** Not possible to open the file */
		text = va_arg(error_info, char*);
		fprintf(stderr, "Error: Can't open file %s\n", text);
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
		break;
	case 7: /** pop: If the stack is empty */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		break;
	case 8: /** swap: If the stack contains less than two elements */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		break;
	case 9: /** add: If the stack contains less than two elements */
		line = va_arg(error_info, int);
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		break;
	default:
		va_end(error_info);
		return(0);
		break;

	}
	va_end(error_info);
	exit(EXIT_FAILURE);
}
