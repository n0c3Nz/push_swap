/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:49:09 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/03 20:26:19 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **stack_a, int rr)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		last = first;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first;
		(*stack_a) = first->next;
		first->next = NULL;
	}
	if (rr == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int rr)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack_b) != NULL && (*stack_b)->next != NULL)
	{
		first = (*stack_b);
		last = first;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first;
		(*stack_b) = first->next;
		first->next = NULL;
	}
	if (rr == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}

long long	ft_atoi(const char *str)
{
	long long	num;
	int			neg;

	num = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > LONG_MAX && neg == 1)
			return (LONG_MAX);
		else if (num < LONG_MIN && neg == -1)
			return (LONG_MIN);
		str++;
	}
	return (num * neg);
}

bool are_all_numbers(char **argv, int argc) {
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        char *endptr;
        long num = strtol(arg, &endptr, 10); // Convierte la cadena a un número

        // Verifica si strtol tuvo éxito y si no hay caracteres adicionales
        if (*endptr != '\0' || arg == endptr) {
            return false; // No es un número válido
        }

        // Verifica si el número es positivo o negativo
        if (num >= 0) {
            continue; // Es un número positivo
        } else {
            // Si el número es negativo, debe tener un signo '-' al principio
            if (arg[0] == '-') {
                continue; // Es un número negativo
            } else {
                return false; // No es un número negativo válido
            }
        }
    }
    return true; // Todas las cadenas son números válidos
}
