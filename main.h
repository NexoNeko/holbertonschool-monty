#ifndef MAIN_H
#define MAIN_H

/**==================================*/
/**========= structs ================*/
/**==================================*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**********/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**********/

/**
 * struct instruction_b - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_a
{
        int value;
	int opcode;
        struct instruction_a *prev;
        struct instruction_a *next;
} instruction_b;

/********** structs end **********/



/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/**==================================*/
/**========= macro defns  ===========*/
/**==================================*/
#define POSSIBLE_BUFFER 80
#define COMMAND_BUFFER 124


/**==================================*/
/**===== function signatures=========*/
/**==================================*/

/** auxiliary functions */
int fun_caller(const instruction_b *);
int fun_exit(int);

/** instruct op functions */

int op_add_value(instruction_b **, const int);
int op_add_instruction(instruction_b **, const int);
instruction_b *op_get_first(instruction_b **);

/** interpreter functions */
int fun_push(int);
int fun_pall(int);
int fun_pint(int);
int fun_pop(int);
int fun_swap(int);
int fun_add(int);
int fun_nop(int);


#endif
