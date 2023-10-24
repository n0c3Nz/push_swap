/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:23:30 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/03 21:19:12 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arrayzer(int size, char **argv)
{
	int	*array;
	int	j;
	int	i;

	i = size;
	j = 0;
	array = (int *)malloc((size) * sizeof(int));
	while (i > 0)
	{
		array[j] = ft_atoi(argv[i]);
		j++;
		i--;
	}
	return (array);
}

int	is_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	peek(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return (stack->content);
	}
	else
	{
		fprintf(stderr, "La pila está vacía, no se puede hacer peek.\n");
		exit(EXIT_FAILURE);
	}
}

int	str_int_limits(char *str)
{
	int	pos;
	int	limit;
	int	length;

	pos = 0;
	limit = 0;
	while (ft_isspace(str[pos]))
		++pos;
	if (str[pos] == '+')
		++pos;
	else if (str[pos] == '-')
		limit = ++pos;
	while (str[pos] == '0')
		++pos;
	length = ft_strlen(&str[pos]);
	if (length == 10)
	{
		if ((limit && ft_strncmp(&str[pos], "2147483648", length) > 0)
			|| (!limit && ft_strncmp(&str[pos], "2147483647", length) > 0))
			return (1);
	}
	else if (length > 10)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_size	size;
	int		*array;

	if (!are_all_numbers(argv, argc))
	{
		write(2, "Error", 5);
		exit(1);
	}
	stack_b = NULL;
	stack_a = NULL;
	size.size_a = argc - 1;
	size.size_b = 0;
	if (checker(argv))
		return (1);
	array = arrayzer(argc - 1, argv);
	if (has_duplicates(array, argc))
		exit(1);
	stack_a = create_stack_a(size.size_a, array, stack_a);
	moves(&stack_a, &stack_b, &size);
	return (0);
}
