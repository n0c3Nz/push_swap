#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack {
    int content;
    struct s_stack *next;
} t_stack;

// Función para encontrar el valor máximo en la pila
int findMax(t_stack *stack) {
    int max = INT_MIN;
    while (stack) {
        if (stack->content > max) {
            max = stack->content;
        }
        stack = stack->next;
    }
    return max;
}
// Función para contar la frecuencia de cada elemento en la pila
void countFrequencies(t_stack *stack, int max, int *count) {
    while (stack) {
        count[stack->content]++;
        stack = stack->next;
    }
}
// Función para realizar Counting Sort en la pila
void countingSort(t_stack **stack) {
    int max = findMax(*stack);
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        printf("Error de asignación de memoria.\n");
        return;
    }
    // Contar la frecuencia de cada elemento en la pila
    countFrequencies(*stack, max, count);
    // Reconstruir la pila ordenada
    t_stack *sortedStack = NULL;
    for (int i = max; i >= 0; i--) {
        while (count[i] > 0) {
            t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
            if (newNode == NULL) {
                printf("Error de asignación de memoria.\n");
                free(count);
                return;
            }
            newNode->content = i;
            newNode->next = sortedStack;
            sortedStack = newNode;
            count[i]--;
        }
    }
    // Liberar la memoria utilizada para el arreglo de conteo
    free(count);
    // Reemplazar la pila original con la pila ordenada
    while (*stack) {
        t_stack *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    *stack = sortedStack; // Asignar la pila ordenada
}

// Función para imprimir la pila
void printStack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

int main() {
    t_stack *stack_a = NULL;

    // Llena tu pila con valores aquí, por ejemplo:

    printf("Pila original:\n");
    printStack(stack_a);

    countingSort(&stack_a);

    printf("Pila ordenada:\n");
    printStack(stack_a);

    return 0;
}

