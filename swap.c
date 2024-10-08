#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Current line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;
    stack_t *top;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    temp = top->n;
    top->n = top->next->n;
    top->next->n = temp;
}
