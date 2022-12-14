#ifndef MAIN_H
#define MAIN_H


/**==================================*/
/**========= header files ===========*/
/**==================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/**==================================*/
/**========= definitions  ===========*/
/**==================================*/
#define POSSIBLE_BUFFER 80
#define COMMAND_BUFFER 124



/**==================================*/
/**===== function signatures=========*/
/**==================================*/
/** auxiliary functions */
int fun_caller(void);
int fun_exit(int);

/** stack functions */
stack_d *stack_add(stack_d **, const int);

/** interpreter functions */
int fun_push(int *);
int fun_pall(int *);
int fun_pint(int *);
int fun_pop(int *);
int fun_swap(int *);
int fun_add(int *);
int fun_nop(int *);


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

/**
 * struct stack_c - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_c
{
        int value;
:	int opcode;
        struct stack_c *prev;
        struct stack_c *next;
} stack_d;

/**==================================*/
/**========= stack_free.c ===========*/
/**==================================*/


void stack_free(stack_t **stack)


/**==================================*/
/**========= stack_funs.c ===========*/
/**==================================*/
int fun_pint(stack_t **stack, unsigned int line_number)
int fun_pop(stack_t **stack, unsigned int line_number)
int fun_swap(stack_t **stack, nsigned int line_number)
int fun_add(stack_t **stack, unsigned int line_number)

#endif /*__MAIN_H__*/
