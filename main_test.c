#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la pila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Función para crear un nuevo nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para insertar un nodo en la parte superior de la pila
void push(Node** stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = *stack;
    *stack = newNode;
}

// Función para eliminar un nodo de la parte superior de la pila
int pop(Node** stack) {
    if (*stack == NULL) {
        printf("La pila está vacía.\n");
        return -1; // Valor de error
    }
    Node* temp = *stack;
    *stack = (*stack)->next;//!
    int data = temp->data;
    free(temp);
    return data;
}
void    ft_print_stack(Node *stack)
{
    while (stack)
    {
        printf("%d\n", (int)stack->data);
        stack = stack->next;
    }
}

int main() {
    Node* stack = NULL; // Inicialización de la pila

    // Insertar elementos en la pila
    push(&stack, 1);
    push(&stack, 4);
    push(&stack, 7);

    // Mostrar los elementos de la pila
    printf("Elementos en la pila:\n");
    ft_print_stack(stack);
	/*while (stack != NULL) {
        int data = pop(&stack);
        printf("%d\n", data);
    }*/
	pop(&stack);
	printf("---POP---\n");
	ft_print_stack(stack);
    return 0;
}
