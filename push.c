#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack
 * @value: Value to push onto the stack
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node;

    /* Create a new node */
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (!*stack)
    {
        /* If stack is empty */
        new_node->next = NULL;
    }
    else
    {
        /* Add new node to the top of the stack */
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
