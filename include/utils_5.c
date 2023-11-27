/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:44:23 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 09:09:02 by guortun-         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	size_t	num;

	num = 0;
	while (*str == 32 || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= 48 && *str <= 57))
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	if (num > 2147483647)
		error();
	return (num);
}

bool	are_all_numbers(char **argv, int argc)
{
	int		i;
	char	*arg;
	char	*endptr;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		endptr = arg;
		while (*endptr != '\0')
		{
			if (*endptr >= '0' && *endptr <= '9')
				endptr++;
			else if (*endptr == ' ')
				endptr++;
			else if (*endptr == '-' || *endptr == '+')
				endptr++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}
