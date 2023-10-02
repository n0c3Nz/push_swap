#include "../push_swap.h"

int pop(t_stack **stack) {
    if (*stack == NULL) {
        printf("La pila está vacía.\n");
        return -1; // Valor de error
    }
    t_stack* temp = *stack;
    *stack = (*stack)->next;
    int content = temp->content;
    free(temp);
    return content;
}