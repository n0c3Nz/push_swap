/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:18:24 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/02 17:20:08 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arrayzer(int size, char **argv)
{
	int	*array;
	int	j;

	j = 0;
	array = (int *)malloc((size) * sizeof(int));
	for (int i = size; i > 0; i--) // Cambiamos el bucle para recorrer en orden inverso
	{
		array[j] = atoi(argv[i]);
		j++;
	}
	return (array);
}

int isEmpty(t_stack *stack) {
    return stack == NULL;
}
int peek(t_stack *stack) {
    if (!isEmpty(stack)) {
        return stack->content;
    } else {
        fprintf(stderr, "La pila está vacía, no se puede hacer peek.\n");
        exit(EXIT_FAILURE);
    }
}
int	main(int argc, char **argv)
{
	t_stack *stack_a = NULL; // Inicializa stack_a como NULL
	t_size size;
	t_stack *stack_b = NULL;
	size.size_a = argc - 1;
	size.size_b = 0;

	int *array = arrayzer(argc - 1, argv);

    //int *simplificado = positioner(array, argc - 1);
	stack_a = create_stack_a(size.size_a, array, stack_a); // Actualiza stack_a	
	moves(&stack_a, &stack_b, &size);
	//ft_print_stack_horizontal(stack_a, stack_b);
//	printf("Peek de la pila A [%d]", peek(stack_a));
    return (0);
}