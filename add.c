#include "monty.h"


/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *top;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    result = top->n + top->next->n;

    /* Update the second top element with the result */
    top->next->n = result;

    /* Remove the top element */
    *stack = (*stack)->next;
    free(top);
}
