#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
