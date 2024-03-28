#include "monty.h"

int main(void)
{
    char opcode[5];
    int value;
    unsigned int line_number = 1;
    stack_t *stack = NULL;

    while (scanf("%4s", opcode) != EOF)
    {
        if (strcmp(opcode, "push") == 0)
        {
            if (scanf("%d", &value) != 1)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value);
        }
        else if (strcmp(opcode, "div") == 0)
            div_op(&stack, line_number);
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack, line_number);
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    return 0;
}
