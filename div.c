#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;

    if (top->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    top->next->n /= top->n;

    /* Remove the top element */
    *stack = (*stack)->next;
    free(top);
}
